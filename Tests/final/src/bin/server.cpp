#include "lib.hpp"

using namespace pack109;
using namespace std;

using std::cout; using std::endl;
using std::system; using std::string;

#define KEY 42

int main(int argc, char *argv[]){
    /*** Cut 1
        /* start server: [4] */
        unsigned int microsecond = 1000000;
        int sockfd, newsockfd, portno, clilen;
        char buffer[256];
        struct sockaddr_in serv_addr, cli_addr;
        int n;
        
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0) {
            perror("ERROR opening socket");
            exit(1);
        }
        printf("Successful start of server on sockfd: %d\n", sockfd);
        usleep(3*microsecond);
        /* bind a socket to a port: [4] */
        bzero((char *) &serv_addr, sizeof(serv_addr));
        portno = 8081;
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_addr.s_addr = INADDR_ANY;
        serv_addr.sin_port = htons(portno);

        /* listen for a connection: [4] */
        if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
            perror("ERROR on binding");
            exit(1);
        }
        listen(sockfd,5);
        clilen = sizeof(cli_addr);
        printf("Listening for connection of Portno: %d Clilen: %d\n", portno, clilen);

        usleep(3*microsecond);
        printf("Waiting for client to send hostname, port, and message...\n");
        printf("======================================================================\n");
        /* Once connection is established: [4] */
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t*) &clilen); /* solution to bug here was: [5] */
        if (newsockfd < 0) {
            perror("ERROR on accept");
            exit(1);
        }
        printf("Successfull Connection!\n");
        usleep(1*microsecond);
        printf("Reading message from client...\n");
        usleep(3*microsecond);
        /* Read message to a buffer: [4] */
        bzero(buffer,256);
        n = read(newsockfd,buffer,255);
        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }

        /* decrypt the message using decimal #42: [6] */
        printf("Decrypting Data...\n");
        usleep(3*microsecond);
        for (int i=0; buffer[i] != '\0'; i++){
		    buffer[i] = buffer[i] ^ KEY;
        }

        printf("Deserializing message...\n");
        /* Deserialize message into struct file or struct request: [7] */
        std::vector<unsigned char> vectorBuffer(std::begin(buffer), std::end(buffer));
        usleep(3*microsecond);
        long File = 0x46;
        long Request = 0x52;
        if(vectorBuffer.at(4) == File){ /* File from kv pair when deserialized. vector position 4-7 = "F" [8] */
            /* Deserialize message into struct file */
            printf("Client Action: Save a File to server.\n");
            struct File deserializeFile = deserialize_file(vectorBuffer);
            /* save struct File into disk in a folder called received [9] */
            printf("Saving File to server...\n");
            usleep(3*microsecond);
            FILE *fout = fopen("writtenFile", "wb");
            fwrite(&deserializeFile, sizeof(File), 1, fout);
            fclose(fout);
            /*================================================== [10] */
            if (mkdir("received", 0777) == -1){
                cerr << "Error :  " << strerror(errno) << endl;
            }else{
                printf("File Saved Successfully!\n");
            }
            /*================================================== [10] */
            std::rename("writtenFile", "received"); /* [11] */
        }else if(vectorBuffer.at(4) == Request){ /* Request from kv pair when deserialized. vector position 4-10 = "R" [8] */
            printf("Client Action: Request a File from server.\n");
            string deserializeRequest = pack109::deserialize_string(vectorBuffer);
            // look for file in recieved folder
            struct dirent* directory; // Pointer for directory stream [10]
            char* usrDirectory = "/mnt/c/Users/MitriDell/Documents/Textbooks/Junior - Spring 2022/CSE 109/CSE109 Code/Tests/final/build/bin/release/received";
            DIR* dir = opendir(usrDirectory);
            if((dir = opendir(usrDirectory)) == NULL){
                printf("No files found within request folder\n");
                exit(0);
            }else{// if file is not there, nothing is returned
                // if file is there, read into memory
                char * newBaseName = new char[deserializeRequest.length() + 1];
                std::strcpy(newBaseName,deserializeRequest.c_str());
                usleep(3*microsecond);
                auto readFile = readFiles(newBaseName);

                // serialized into a 'file' message
                usleep(3*microsecond);
                printf("Serializing struct...\n");
                usleep(3*microsecond);
                vec fileSend = serialize(readFile);

                // encrypt
                printf("Encrypting Data...\n");
                usleep(3*microsecond); 
                for (auto & element : fileSend){
                    fileSend[element] = fileSend[element] ^ KEY;
                }

                // send to client
                printf("Sending file to server!\n");
                void * fileSendForClient = (void*) & fileSend;
                n = write(sockfd, fileSendForClient, fileSend.size());
            }
        }else{
            printf("ERROR 76: Unidentified client Action.\n");
        }
        
        usleep(3*microsecond);
        printf("Closing Server...\n");
        // server is closed
    /***/
}
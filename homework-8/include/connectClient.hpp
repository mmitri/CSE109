#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>
#include <iostream>
#include <string>
#include <vector> 

int connectToServer(int portno, struct hostent * address, vec fileSend){
   int n, sockfd;
   struct sockaddr_in serv_addr;
   sockfd = socket(AF_INET, SOCK_STREAM, 0);
   void * fileSendForClient = (void*) & fileSend;

   if (sockfd < 0) {
      perror("ERROR opening socket");
      exit(1);
   }

   printf("Socket Open Successfully!\n");
   
   if (address == NULL) {
      fprintf(stderr,"ERROR, no such host\n");
      exit(0);
   }

   printf("%s Host found!\n", address);

   bzero((char *) &serv_addr, sizeof(serv_addr));
   serv_addr.sin_family = AF_INET;
   bcopy((char *)address->h_addr, (char *)&serv_addr.sin_addr.s_addr, address->h_length);
   serv_addr.sin_port = htons(portno);

   if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
      perror("ERROR connecting");
      exit(1);
   }
   printf("Connected to Server.\n");
   n = write(sockfd, fileSendForClient, fileSend.size());
   if (n < 0){
      perror("ERROR writing to socket");
      exit(1);
   }

   return 0;
}
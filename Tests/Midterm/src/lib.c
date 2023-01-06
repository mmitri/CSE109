#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <dirent.h>

void myLS(int argc, char* usrDirectory, bool aFlag, bool lFlag, bool hFlag, bool vFlag){ 
// argc = # of arguments
// argv = array of the arguments
    struct dirent* directory; // Pointer for directory stream [10]
    DIR* direct = opendir(usrDirectory); // opendir() returns a pointer to the directory stream [5]
    if(direct == NULL){ // If there is no argument
        printf("Error 607: Could not open current directory\n");
        // This is just a random error code. Nothing special
        exit(0);
    }
    while((directory = readdir(direct)) != NULL){ // [6] example for heading of while loop
    // readdir() returns a pointer to the structure representing the directory entry at the position [6]
    // while the current directory is not empty
        if(aFlag && (strcmp(".", directory->d_name) == 0 || strcmp("..", directory->d_name) == 0)){
            printf("%s ",directory->d_name);
        }if(lFlag){
            system(directory->d_name);
        }if(hFlag){
            printf("Usage: ls [OPTION]... [FILE]...\n");
            printf("List information about the FILEs (the current directory by default).\n");
            printf("Sort entries alphabetically if none of -cftuvSUX nor --sort is specified.\n");
            printf("\n-a --all: do not ignore entries starting with .\n");
            printf("-l : use a long listing format\n");
            printf("--help : displat this help and exit\n");
            printf("--version : output version information and exit\n");
            exit(0);
        }if(vFlag){
            printf("ls version: %ld\n", directory->d_ino);// [10]
            printf("Copywrite: 2022. Created for CSE109, Lehigh University\n");
            printf("Written by Mark Mitri\n");
            exit(0);
        }if(strcmp(".", directory->d_name) == 0 || strcmp("..", directory->d_name) == 0){
        // strcmp compares two strings and returns >0,<0,=0 [8]
            continue;
        }
        printf("%*s%s" "",argc," ",directory->d_name);
    }
    printf("\n");
    closedir(direct); // Similar to keyboard.close() in java
    exit(0);
}

// for loop for the first flag is from homework 2 solutions [9]
//      Line 60-63 are taken from homework 2
//      the additional flag and else if statements are mine
int main(int argc, char* argv[]){
    bool aFlag = false;
    bool lFlag = false;
    bool hFlag = false;
    bool vFlag = false;
    if(argc == 1){ // There are no flags
        myLS(argc,".",aFlag, lFlag, hFlag, vFlag); // call the ls function and pass the current directory
    }else{                                                                      
        for(int i = 1; i < argc; i++){                          
            if(strcmp(argv[i], "-a") == 0 || strcmp(argv[i], "--all") == 0){
                // Set the flag here, we'll use it later
                aFlag = true;
            }else if(strcmp(argv[i], "-l") == 0){
                lFlag = true;
            }else if(strcmp(argv[i], "--help") == 0){
                hFlag = true;
            }else if(strcmp(argv[i], "--version") == 0){
                vFlag = true;
            }else if(argv[i][0] == '-'){
                printf("ls: invalid option -- '%s'\n",argv[i]);
                printf("Try 'ls --help' for more information.\n");
                // Illegal Flag -> return 2
                return 2;
                exit(0);
            }
        }
        myLS(argc,".",aFlag, lFlag, hFlag, vFlag);
    }
}


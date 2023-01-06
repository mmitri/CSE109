#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/***
 * Mark Mitri
 * 2/13/2022
 * CSE109
 * Homework 2
***/

/***
 * Procedure for the program:
 * 1. Collect the PATH file and place within a temporary array (done)
 * 2. Record the user input into an array (done)
 * 3. Use strtok() method to replace the 
 * ':' with \0 to make it easier to separate the path variables (done)
 * 4. Loop through the temporary array that houses 
 * the PATH file and append the user inputted programs (sort of working)
 *    - works for a single input like ./mainHW2 gcc
 * 5. For each path, use file_exit() method to check if it is a path and the program is executable
 * 6. If 5 is correct, then print the location of the program, keeping in mind 
 * the different tags with which program
***/

int main(int argc, char** argv){
  char* pathV = getenv("PATH");
  char* usrPath = strtok(pathV, ":");
  char myArray[1000][1000];
  int num_tokens = 0;
  while (usrPath != NULL){
    strcpy(myArray[num_tokens], usrPath); // Copy to token list
    num_tokens++;
    usrPath = strtok(NULL, ":"); // Get the next token. input=NULL now
  }
  printf("PATH Variable\n");
  for(int i=0;i<1000;i++){
    printf("%c",pathV[i]);
  }
  printf("\nstrtok() Path Variable\n");
  for(int j=0;j<num_tokens;j++){
    printf("%s\n",myArray[j]);
  }
  // For loop to append user inputted string to the file locations within myArray
  printf("\nAppended argv with myArray\n");
  for(int k=1;k<argc;k++){
    for(int l=0;l<num_tokens;l++){
      if(myArray[l] == '\0'){
        myArray[l] = '/';
        strcat(myArray, argv[k]);
        break;
      }
    }
    if(file_exists(myArray[k])){
      printf("%s\n", myArray[k]);
      fileExits = true;
    }else{
      fileExits = false;
    } 
  }
  return 0;
}
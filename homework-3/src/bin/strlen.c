#include <stdio.h>
#include <stdlib.h>

int myStrlen(char* str);

int main(int argc, char* argv[]){
    char *str;
    printf("User input string: ");
    for(int i=1;i<argc;i++){
        str = argv[i];
        printf("%s",argv[i]);
    }
    printf("\n");
    printf("Length of user input string: %d\n", myStrlen(str));
}

int myStrlen(char* str){
    int count = 0;
	while(*str != '\0'){
		count++;
		str++;
	}
	return count;
}
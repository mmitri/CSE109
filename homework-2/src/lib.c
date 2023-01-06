#include <stdbool.h>
#include <unistd.h>

// access function
// see if the file exists and is executable

bool file_exists(char* path, int amode){
    int result = access(path,(F_OK & X_OK));
    if(result == -1){
        printf("Error: Cannot access file.");
    }else{
        printf("File access successful.");
    }
    return 0;
}
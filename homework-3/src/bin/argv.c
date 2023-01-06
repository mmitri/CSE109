#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    for(int i=1;i<argc;i++){
        printf("Input # %d | \"%s\" | Address location: %p\n", i, argv[i], (void *)&argv[i]);
    }
    return 0;
}
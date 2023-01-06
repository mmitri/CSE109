#include <stdio.h>
#include <stdlib.h>

void multiply_ptrs(int* x, int* y, int z);

int main(int argc, char* argv[]){
    int x = 0;
    int y = 0;
    int z;
    if(argc > 1)
        x = atoi(argv[1]);
    if(argc > 2)
        y = atoi(argv[2]);
    multiply_ptrs(&x,&y,z);
}

void multiply_ptrs(int* x, int* y, int z) {
    z = (*x * *y);
    printf("%d\n", z);
}
#include <stdio.h>
#include <stdlib.h>

int main(){
    char c = 163;
    char bar = 20;
    char foo = 10;
    char* b;
    char* a;
    char d = 96;
    b = &c;
    a = &d;
    *a = 33;
    *b = *a + c;
    printf("Variable foo | Address: %p Value: %x\n", &foo, foo);
    printf("Variable bar | Address: %p Value: %x\n", &bar, bar);
    printf("Variable c | Address: %p Value: %d\n", &c, c);
    printf("Variable *b | Address: %p Value: %x\n", &b, b);
    printf("Variable *a | Address: %p Value: %x\n", &a, a);
    printf("Variable d | Address: %p Value: %x\n", &d, d);
    printf("Variable b pointing to &c | Address: %p Value: %x Deref %d\n", &b, b, *b);
    printf("Variable a pointing to &d | Address: %p Value: %x Deref %d\n", &a, a, *a);
    printf("Variable *a = 33 | Address: %p Value: %x Deref %d\n", &a, a, *a);
    printf("Variable *b = *a + c | Address: %p Value: %x Deref %d\n", &b, b, *b);
}
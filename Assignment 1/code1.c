//. Write a program to use sizeof operator to check the sizes (in bytes) of the different datatypes.


#include <stdio.h>

int main() {
    printf("Size of char: %lu byte(s)\n", sizeof(char));
    printf("Size of int: %lu byte(s)\n", sizeof(int));
    printf("Size of float: %lu byte(s)\n", sizeof(float));
    printf("Size of double: %lu byte(s)\n", sizeof(double));
    printf("Size of long: %lu byte(s)\n", sizeof(long));
    printf("Size of long long: %lu byte(s)\n", sizeof(long long));
    printf("Size of short: %lu byte(s)\n", sizeof(short));
    printf("Size of unsigned int: %lu byte(s)\n", sizeof(unsigned int));
    printf("Size of void*: %lu byte(s)\n", sizeof(void*)); 

    return 0;
}

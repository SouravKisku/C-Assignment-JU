// Write a program to print value of z where
// i. a=5, b=6, z= a++ + b++
// ii. a=5, b=6, z= a++ + --b
// iii. a=5, z= a++ + ++a

#include <stdio.h>

int main() {
    int a, b, z; 

    // i. a = 5, b = 6, z = a++ + b++
    a = 5;
    b = 6;
    z = a++ + b++;
    printf("i. a=5, b=6, z=a++ + b++\n");
    printf("a = %d, b = %d, z = %d\n\n", a, b, z); 

    // ii. a = 5, b = 6, z = a++ + --b
    a = 5;
    b = 6;
    z = a++ + --b;
    printf("ii. a=5, b=6, z=a++ + --b\n");
    printf("a = %d, b = %d, z = %d\n\n", a, b, z); 

    // iii. a = 5, z = a++ + ++a
    a = 5;
    z = a++ + ++a;
    printf("iii. a=5, z=a++ + ++a\n");
    printf("a = %d, z = %d\n", a, z); 

    return 0;
}

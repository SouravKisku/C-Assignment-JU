// Write a program to calculate the real roots of any quadratic equation where a,b, c (i.e. the co-efficients)will be taken as input by the user.

#include <stdio.h>
#include <math.h> 

int main() {
    float a, b, c, discriminant, root1, root2;

    printf("Enter the coefficient a: ");
    scanf("%f", &a);
    
    printf("Enter the coefficient b: ");
    scanf("%f", &b);
    
    printf("Enter the coefficient c: ");
    scanf("%f", &c);

    discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("The equation has two real and distinct roots: %.2f and %.2f\n", root1, root2);
    } else if (discriminant == 0) {
        root1 = -b / (2 * a);
        printf("The equation has one real and repeated root: %.2f\n", root1);
    } else {
        printf("The equation has no real roots.\n");
    }

    return 0;
}

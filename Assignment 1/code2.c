//Write a program to find average of 3 integers. Input variables must be declared as the integer variables.

#include <stdio.h>

int main(){
    int num1, num2, num3;
    float average;

    printf("Enter the number's : ");
    scanf("%d %d %d", &num1, &num2, &num3);

    average = (num1+num2+num3)/3;
     printf("Average of %d, %d and %d is %.2f\n",num1, num2, num3, average);
    return 0;
}
// Write a program to find the reverse of any number & check whether the number is a palindrome or not

#include <stdio.h>

int main() {
    int num, originalNum, reversedNum = 0, remainder;

    printf("Enter a number: ");
    scanf("%d", &num);

    originalNum = num;  

    while (num != 0) {
        remainder = num % 10; 
        reversedNum = reversedNum * 10 + remainder;  
        num /= 10;  
    }

    printf("The reverse of the number is: %d\n", reversedNum);

    if (originalNum == reversedNum) {
        printf("The number is a palindrome.\n");
    } else {
        printf("The number is not a palindrome.\n");
    }

    return 0;
}

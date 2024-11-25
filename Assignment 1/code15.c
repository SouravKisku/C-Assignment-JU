// Write a program to convert the digits of a 3-digit number into words.for example, if input: 123 Output: One Two Three

#include <stdio.h>

void convertToWords(int digit) {
    switch (digit) {
        case 0: printf("Zero "); break;
        case 1: printf("One "); break;
        case 2: printf("Two "); break;
        case 3: printf("Three "); break;
        case 4: printf("Four "); break;
        case 5: printf("Five "); break;
        case 6: printf("Six "); break;
        case 7: printf("Seven "); break;
        case 8: printf("Eight "); break;
        case 9: printf("Nine "); break;
        default: printf("Invalid input "); break;
    }
}

int main() {
    int num;

    printf("Enter a 3-digit number: ");
    scanf("%d", &num);

    if (num < 100 || num > 999) {
        printf("Please enter a valid 3-digit number.\n");
        return 1; 
    }

    int hundreds = num / 100;        
    int tens = (num / 10) % 10;      
    int ones = num % 10;             

    convertToWords(hundreds);
    convertToWords(tens);
    convertToWords(ones);

    return 0;
}

// Write a program to convert an 8-digit number into words (consider both the Indian and International number system).

#include <stdio.h>
#include <string.h>

void convertToWordsIndian(int num) {
    char *ones[] = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", 
                     "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", 
                     "Seventeen", "Eighteen", "Nineteen" };
    char *tens[] = { "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };
    char *thousands[] = { "", "Thousand", "Lakh", "Crore" };

    int crore = num / 10000000;
    int lakh = (num / 100000) % 100;
    int thousand = (num / 1000) % 100;
    int hundred = (num / 100) % 10;
    int ten = (num / 10) % 10;
    int one = num % 10;

    if (crore > 0) {
        printf("%s Crore ", ones[crore]);
    }
    if (lakh > 0) {
        printf("%s Lakh ", ones[lakh]);
    }
    if (thousand > 0) {
        printf("%s Thousand ", ones[thousand]);
    }
    if (hundred > 0) {
        printf("%s Hundred ", ones[hundred]);
    }
    if (ten > 1) {
        printf("%s %s", tens[ten], ones[one]);
    } else if (ten == 1) {
        printf("%s", ones[ten * 10 + one]);
    } else if (one > 0) {
        printf("%s", ones[one]);
    }
    printf("\n");
}

void convertToWordsInternational(int num) {
    char *ones[] = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", 
                     "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", 
                     "Seventeen", "Eighteen", "Nineteen" };
    char *tens[] = { "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };
    char *thousands[] = { "", "Thousand", "Million", "Billion" };

    int billion = num / 1000000000;
    int million = (num / 1000000) % 1000;
    int thousand = (num / 1000) % 1000;
    int hundred = (num / 100) % 10;
    int ten = (num / 10) % 10;
    int one = num % 10;

    if (billion > 0) {
        printf("%s Billion ", ones[billion]);
    }
    if (million > 0) {
        printf("%s Million ", ones[million]);
    }
    if (thousand > 0) {
        printf("%s Thousand ", ones[thousand]);
    }
    if (hundred > 0) {
        printf("%s Hundred ", ones[hundred]);
    }
    if (ten > 1) {
        printf("%s %s", tens[ten], ones[one]);
    } else if (ten == 1) {
        printf("%s", ones[ten * 10 + one]);
    } else if (one > 0) {
        printf("%s", ones[one]);
    }
    printf("\n");
}

int main() {
    int num;

    printf("Enter an 8-digit number: ");
    scanf("%d", &num);

    printf("In Indian Number System: ");
    convertToWordsIndian(num);

    printf("In International Number System: ");
    convertToWordsInternational(num);

    return 0;
}

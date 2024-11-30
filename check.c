#include <stdio.h>
#include <string.h>

// Arrays for single digits, tens, and powers of ten
const char *single_digits[] = {
    "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
};

const char *two_digits[] = {
    "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"
};

const char *tens_multiple[] = {
    "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"
};

// Powers of ten for Indian and International systems
const char *indian_powers[] = {"hundred", "thousand", "lakh", "crore"};
const char *international_powers[] = {"hundred", "thousand", "million", "billion"};

// Function to convert numbers below 1000 to words
void convertToWords(int num, char *result) {
    if (num >= 100) {
        strcat(result, single_digits[num / 100]);
        strcat(result, " ");
        strcat(result, "hundred");
        strcat(result, " ");
        num %= 100;
    }

    if (num >= 20) {
        strcat(result, tens_multiple[num / 10]);
        strcat(result, " ");
        num %= 10;
    } else if (num >= 10) {
        strcat(result, two_digits[num - 10]);
        strcat(result, " ");
        return;
    }

    if (num > 0) {
        strcat(result, single_digits[num]);
        strcat(result, " ");
    }
}

// Function for Indian number system
void numberToWordsIndian(int num, char *result) {
    if (num >= 10000000) { // Crores
        convertToWords(num / 10000000, result);
        strcat(result, "crore ");
        num %= 10000000;
    }

    if (num >= 100000) { // Lakhs
        convertToWords(num / 100000, result);
        strcat(result, "lakh ");
        num %= 100000;
    }

    if (num >= 1000) { // Thousands
        convertToWords(num / 1000, result);
        strcat(result, "thousand ");
        num %= 1000;
    }

    if (num > 0) { // Remaining hundreds and below
        convertToWords(num, result);
    }
}

// Function for International number system
void numberToWordsInternational(int num, char *result) {
    if (num >= 1000000000) { // Billions
        convertToWords(num / 1000000000, result);
        strcat(result, "billion ");
        num %= 1000000000;
    }

    if (num >= 1000000) { // Millions
        convertToWords(num / 1000000, result);
        strcat(result, "million ");
        num %= 1000000;
    }

    if (num >= 1000) { // Thousands
        convertToWords(num / 1000, result);
        strcat(result, "thousand ");
        num %= 1000;
    }

    if (num > 0) { // Remaining hundreds and below
        convertToWords(num, result);
    }
}

int main() {
    int number, choice;
    char result[500] = "";

    printf("Enter a number (0 to 999999999): ");
    scanf("%d", &number);

    if (number < 0 || number > 999999999) {
        printf("Number out of range. Please enter a number between 0 and 999999999.\n");
        return 0;
    }

    printf("Choose number system:\n");
    printf("1. Indian\n");
    printf("2. International\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        numberToWordsIndian(number, result);
        printf("Indian Number System: %s\n", result);
    } else if (choice == 2) {
        numberToWordsInternational(number, result);
        printf("International Number System: %s\n", result);
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}

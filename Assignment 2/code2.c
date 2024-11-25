// In a banking system, there are the following denomination of notes: Rs. 10, Rs. 20. Rs. 50. Rs. 100.
// Write a program that will accept an amount and find the minimum number of each note required to pay the amount.

#include <stdio.h>

void calculateNotes(int amount) {
    int hundred, fifty, twenty, ten;

    hundred = amount / 100;
    amount = amount % 100;  

    fifty = amount / 50;
    amount = amount % 50;

    twenty = amount / 20;
    amount = amount % 20;

    ten = amount / 10;
    amount = amount % 10;

    printf("100 Rs. notes: %d\n", hundred);
    printf("50 Rs. notes: %d\n", fifty);
    printf("20 Rs. notes: %d\n", twenty);
    printf("10 Rs. notes: %d\n", ten);

    if (amount > 0) {
        printf("Remaining amount: %d (Cannot be paid with available notes)\n", amount);
    }
}

int main() {
    int amount;

    printf("Enter the amount: ");
    scanf("%d", &amount);

    if (amount < 10) {
        printf("Amount should be at least Rs. 10 to pay using available notes.\n");
        return 1;
    }

    calculateNotes(amount);

    return 0;
}

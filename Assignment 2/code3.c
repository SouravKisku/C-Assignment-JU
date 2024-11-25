// In a hotel, a professor lives in a room no. X. The room number are sequentially numbered from 1 to n (n can be any integer). The sum of the room numbers left to X is equal to the sum of the room numbers to the right of X. Write a program to find X.

#include <stdio.h>

int findRoomNumber(int n) {
    int total_sum = n * (n + 1) / 2;

    for (int X = 1; X <= n; X++) {
        int sum_left = (X - 1) * X / 2;  
        int sum_right = total_sum - sum_left - X;  

        if (sum_left == sum_right) {
            return X;
        }
    }
    return -1;  
}

int main() {
    int n;

    printf("Enter the total number of rooms: ");
    scanf("%d", &n);

    int X = findRoomNumber(n);
    if (X == -1) {
        printf("No such room number exists.\n");
    } else {
        printf("The room number X is: %d\n", X);
    }

    return 0;
}

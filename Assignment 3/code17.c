// WAP to input a line from keyboard then encode it to its next alphabet or digits, then print the newly generated line
// e.g. Input :--   today is 27 of September  Output:-- upebz jt 38 pg tfqufnafs


#include <stdio.h>

void encode(char str[]) {
    int i = 0;
    while (str[i] != '\0') {
        // If the character is a lowercase letter
        if (str[i] >= 'a' && str[i] <= 'z') {
            // Shift to the next letter, wrapping around if necessary
            if (str[i] == 'z') {
                str[i] = 'a';
            } else {
                str[i] = str[i] + 1;
            }
        }
        // If the character is an uppercase letter
        else if (str[i] >= 'A' && str[i] <= 'Z') {
            // Shift to the next letter, wrapping around if necessary
            if (str[i] == 'Z') {
                str[i] = 'A';
            } else {
                str[i] = str[i] + 1;
            }
        }
        // If the character is a digit
        else if (str[i] >= '0' && str[i] <= '9') {
            // Increment the digit by 1, wrapping around if necessary
            if (str[i] == '9') {
                str[i] = '0';
            } else {
                str[i] = str[i] + 1;
            }
        }
        // Leave spaces and other characters unchanged
        i++;
    }
}

int main() {
    char str[200];

    // Input the line from the user
    printf("Enter a line: ");
    fgets(str, sizeof(str), stdin);

    // Call the encode function to transform the string
    encode(str);

    // Print the encoded string
    printf("Encoded line: %s\n", str);

    return 0;
}

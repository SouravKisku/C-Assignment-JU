// Write a program to calculate the marks obtained by any student in 5 different
// subjects, entered form keyboard, finally the grade will be assigned depending on the
// following criteria on the average marks obtained:--
// i. If avg is greater than “90” but less than “100” assign grade as ‘A’
// ii. If avg is greater than “80” but less than “90” assign grade as ‘B’
// iii. If avg is greater than “70” but less than “80” assign grade as ‘C’
// iv. If avg is greater than “60” but less than “70” assign grade as ‘D’
// v. If avg is greater than “50” but less than “60” assign grade as ‘E’
// vi. If avg is less than “50” assign grade as ‘F’ and mention the student as
// a failed candidate.
// vii. Otherwise he/she will be considered as a successful one.

#include <stdio.h>

int main() {
    float marks[5], total = 0, avg; 
    char grade; 
    int i; 

    printf("Enter marks for 5 subjects (out of 100):\n");
    for (i = 0; i < 5; i++) {
        printf("Subject %d: ", i + 1);
        scanf("%f", &marks[i]);
        total += marks[i]; 
    }

    avg = total / 5;

    if (avg >= 90 && avg <= 100) {
        grade = 'A';
    } else if (avg >= 80 && avg < 90) {
        grade = 'B';
    } else if (avg >= 70 && avg < 80) {
        grade = 'C';
    } else if (avg >= 60 && avg < 70) {
        grade = 'D';
    } else if (avg >= 50 && avg < 60) {
        grade = 'E';
    } else {
        grade = 'F';
    }

    printf("\nTotal Marks: %.2f\n", total);
    printf("Average Marks: %.2f\n", avg);
    printf("Grade: %c\n", grade);

    if (grade == 'F') {
        printf("The student is a failed candidate.\n");
    } else {
        printf("The student is successful.\n");
    }

    return 0;
}

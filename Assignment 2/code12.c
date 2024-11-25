// Write a program to compute an union of two sorted list of integers so that the resultant list remain sorted

#include <stdio.h>

void unionSortedLists(int list1[], int len1, int list2[], int len2) {
    int i = 0, j = 0;
    
    printf("Union of the two sorted lists: ");
    
    while (i < len1 && j < len2) {
        if (list1[i] < list2[j]) {
            printf("%d ", list1[i]);
            i++;
        } else if (list1[i] > list2[j]) {
            printf("%d ", list2[j]);
            j++;
        } else {
            printf("%d ", list1[i]);
            i++;
            j++;
        }
    }

    while (i < len1) {
        printf("%d ", list1[i]);
        i++;
    }

    while (j < len2) {
        printf("%d ", list2[j]);
        j++;
    }

    printf("\n");
}

int main() {
    int list1[] = {1, 2, 4, 5, 6};
    int list2[] = {2, 3, 5, 7};
    
    int len1 = sizeof(list1) / sizeof(list1[0]);
    int len2 = sizeof(list2) / sizeof(list2[0]);

    unionSortedLists(list1, len1, list2, len2);

    return 0;
}

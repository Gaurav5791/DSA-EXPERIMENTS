#include <stdio.h>
void bubbleSortAsc(int nums[], int size) {
    int i, j, swap;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (nums[j] > nums[j + 1]) {
                swap = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = swap;
            }
        }
    }
}

int main() {
    int count, k;
    
    printf("Enter the total number of elements: ");
    scanf("%d", &count);

    int numbers[count];

    printf("Enter %d integers: ", count);
    for (k = 0; k < count; k++) {
        scanf("%d", &numbers[k]);
    }

    printf("\nOriginal Array: ");
    for (k = 0; k < count; k++) {
        printf("%d ", numbers[k]);
    }

    bubbleSortAsc(numbers, count);

    printf("\nSorted Array (Ascending): ");
    for (k = 0; k < count; k++) {
        printf("%d ", numbers[k]);
    }

    return 0;
}

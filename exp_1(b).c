#include <stdio.h>

// Function to perform Selection Sort in descending order
void selectionSortDesc(int data[], int length) {
    int i, j, pos, temp;

    for (i = 0; i < length - 1; i++) {
        pos = i; // Assume current index has the largest element
        for (j = i + 1; j < length; j++) {
            if (data[j] > data[pos]) {
                pos = j; // Found a larger element
            }
        }
        // Swap the largest found element with the current position
        temp = data[i];
        data[i] = data[pos];
        data[pos] = temp;
    }
}

int main() {
    int size, index;

    printf("Enter number of elements: ");
    scanf("%d", &size);

    int values[size];

    printf("Enter %d numbers: ", size);
    for (index = 0; index < size; index++) {
        scanf("%d", &values[index]);
    }

    printf("\nOriginal Array: ");
    for (index = 0; index < size; index++) {
        printf("%d ", values[index]);
    }

    selectionSortDesc(values, size);

    printf("\nSorted Array (Descending): ");
    for (index = 0; index < size; index++) {
        printf("%d ", values[index]);
    }

    return 0;
}
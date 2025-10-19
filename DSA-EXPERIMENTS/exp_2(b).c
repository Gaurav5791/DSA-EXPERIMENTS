#include <stdio.h>
int getFibonacci(int term) {
    if (term < 2) {
        return term;
    }
    return getFibonacci(term - 1) + getFibonacci(term - 2);
}
int main() {
    int terms, index;

    printf("How many Fibonacci terms do you want? \n");
    scanf("%d", &terms);

    printf("Fibonacci Sequence: ");
    for (index = 0; index < terms; index++) {
        printf("%d ", getFibonacci(index));
    }
    printf("\n");

    return 0;
}

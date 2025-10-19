#include <stdio.h>
int calcSum(int limit) {
    if (limit <= 0) {
        return 0;
    }
    return limit + calcSum(limit - 1);
}
int main() {
    int total, sumResult;
    printf("Enter a positive integer: ");
    scanf("%d", &total);
    sumResult = calcSum(total);
    printf("Sum of first %d natural numbers = %d\n", total, sumResult);
    return 0;
}

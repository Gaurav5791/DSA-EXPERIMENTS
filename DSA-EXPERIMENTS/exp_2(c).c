#include <stdio.h>
void solveHanoi(int disks, char source, char destination, char helper) {
    if (disks == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }
    solveHanoi(disks - 1, source, helper, destination);
    printf("Move disk %d from %c to %c\n", disks, source, destination);
    solveHanoi(disks - 1, helper, destination, source);
}

int main() {
    int totalDisks;

    printf("Enter number of disks for Tower of Hanoi: ");
    scanf("%d", &totalDisks);

    printf("\nSequence of moves:\n");
    solveHanoi(totalDisks, 'A', 'C', 'B');

    return 0;
}

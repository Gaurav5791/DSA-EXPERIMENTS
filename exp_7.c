#include <stdio.h>
#include <string.h>

#define MAX 5

int stack[MAX];
int top = -1;

void push(int x) {
    if (top == MAX - 1) printf("Overflow\n");
    else { stack[++top] = x; printf("%d pushed\n", x); }
}

int pop() {
    if (top == -1) { printf("Underflow\n"); return -1; }
    return stack[top--];
}

void display() {
    if (top == -1) printf("Empty\n");
    else for (int i = top; i >= 0; i--) printf("%d ", stack[i]);
    printf("\n");
}

void palindrome() {
    char str[50], rev[50];
    printf("Enter string: ");
    scanf("%s", str);
    int len = strlen(str);
    top = -1;
    for (int i = 0; i < len; i++) {
        if (top < MAX - 1) stack[++top] = str[i];
        else { printf("not palindrome\n"); return; }
    }
    for (int i = 0; i < len; i++) rev[i] = stack[top--];
    rev[len] = '\0';
    printf("%s\n", strcmp(str, rev) == 0 ? "Palindrome" : "Not Palindrome");
}

int main() {
    int ch, x;
    while (1) {
        printf("\n1.Push 2.Pop 3.Palindrome 4.Display 5.Exit\nChoice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: printf("Num: "); scanf("%d", &x); push(x); break;
            case 2: x = pop(); if (x != -1) printf("Popped: %d\n", x); break;
            case 3: palindrome(); break;
            case 4: display(); break;
            case 5: return 0;
            default: printf("Invalid\n");
        }
    }
}

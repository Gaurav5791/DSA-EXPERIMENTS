#include <stdio.h>

int stringLength(char str[]) {
    int len = 0;
    while (str[len] != '\0') len++;
    return len;
}

int stringCompare(char str1[], char str2[], int pos) {
    int i = 0;
    while (str2[i] != '\0') {
        if (str1[pos + i] != str2[i]) return 0;
        i++;
    }
    return 1;
}

void stringReplace(char str[], char pat[], char rep[]) {
    char result[200];
    int i = 0, j = 0, k, found;
    int lenStr = stringLength(str);
    int lenPat = stringLength(pat);
    int lenRep = stringLength(rep);

    while (i < lenStr) {
        found = stringCompare(str, pat, i);
        if (found) {
            for (k = 0; k < lenRep; k++)
                result[j++] = rep[k];
            i += lenPat;
        } else {
            result[j++] = str[i++];
        }
    }
    result[j] = '\0';
    printf("\nModified String: %s", result);
}

int main() {
    char str[100], pat[50], rep[50];

    printf("Enter the main string: ");
    gets(str);

    printf("Enter the pattern string: ");
    gets(pat);

    printf("Enter the replace string: ");
    gets(rep);

    if (stringLength(pat) == 0) {
        printf("Pattern string cannot be empty.");
        return 0;
    }

    stringReplace(str, pat, rep);
    return 0;
}


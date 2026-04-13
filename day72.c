#include <stdio.h>

int main() {
    char s[1000];

    printf("Enter a string: ");
    scanf("%s", s);

    for (int i = 0; s[i] != '\0'; i++) {
        for (int j = i + 1; s[j] != '\0'; j++) {
            if (s[i] == s[j]) {
                printf("First repeated character: %c\n", s[i]);
                return 0;
            }
        }
    }

    printf("-1\n");
    return 0;
}
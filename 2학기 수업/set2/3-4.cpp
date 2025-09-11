#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, i, maxLen = 0, maxIndex = 0;
    char buffer[100];
    char *strings[10];

    scanf("%d", &n);


    if (n > 10) n = 10;

    for (i = 0; i < n; i++) {
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = 0; // 개행 제거

        strings[i] = (char *)malloc(strlen(buffer) + 1);
        strcpy(strings[i], buffer);

        if ((int)strlen(buffer) > maxLen) {
            maxLen = strlen(buffer);
            maxIndex = i;
        }
    }

    printf("%s\n", strings[maxIndex]);

    for (i = 0; i < n; i++) {
        free(strings[i]);
    }

    return 0;
}

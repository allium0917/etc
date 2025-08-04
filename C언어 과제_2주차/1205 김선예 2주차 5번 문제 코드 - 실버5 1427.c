#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return *(char *)b - *(char *)a;
}

int main() {
    char n[11];

    scanf("%s", n);

    int len = strlen(n);
    qsort(n, len, sizeof(char), cmp);

    printf("%s", n);
    return 0;
}

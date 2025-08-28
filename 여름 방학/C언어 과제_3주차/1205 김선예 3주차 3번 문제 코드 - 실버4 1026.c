#include <stdio.h>
#include <stdlib.h>

int compareAsc(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int compareDesc(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

int main() {
    int n, i, AB = 0;
    int arrA[50], arrB[50];

    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &arrA[i]);
    for (i = 0; i < n; i++) scanf("%d", &arrB[i]);

    qsort(arrA, n, sizeof(int), compareDesc);
    qsort(arrB, n, sizeof(int), compareAsc);

    for (i = 0; i < n; i++) {
        AB += arrA[i] * arrB[i];
    }

    printf("%d", AB);
}

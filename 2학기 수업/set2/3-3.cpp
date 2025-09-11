#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, num, count = 0;
    int *evens;

    scanf("%d", &n);

    if (n > 15) n = 15;

    evens = (int *)malloc(0);

    for (i = 0; i < n; i++) {
        scanf("%d", &num);
        if (num % 2 == 0) {
            evens = (int *)realloc(evens, (count + 1) * sizeof(int));
            evens[count++] = num;
        }
    }

    for (i = 0; i < count; i++) {
        printf("%d ", evens[i]);
    }
    printf("\n");

    free(evens);
    return 0;
}

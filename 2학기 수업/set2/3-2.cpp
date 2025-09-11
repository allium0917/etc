#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j, k = 0;
    int *arr, *unique;

    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));
    unique = (int *)malloc(0);

    if (arr == NULL || unique == NULL) {
        printf("메모리 할당 실패\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n; i++) {
        int found = 0;
        for (j = 0; j < k; j++) {
            if (unique[j] == arr[i]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            unique = (int *)realloc(unique, (k + 1) * sizeof(int));
            unique[k++] = arr[i];
        }
    }

    for (i = 0; i < k; i++) {
        printf("%d ", unique[i]);
    }
    printf("\n");

    free(arr);
    free(unique);
    return 0;
}

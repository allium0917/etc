#include <stdio.h>

void sort_desc(int arr[], int order[], int size) {
    int i, j, temp;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - 1 - i; j++) {
            if (arr[j] < arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                temp = order[j];
                order[j] = order[j + 1];
                order[j + 1] = temp;
            }
        }
    }
}

void sort_asc(int arr[], int size) {
    int i, j, temp;
    for (i = 0; i < size -1; i++) {
        for (j = 0; j < size -1 - i; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int arr[8];
    int order[8];
    int i;
    int sum = 0;

    for (i = 0; i < 8; i++) {
        scanf("%d", &arr[i]);
        order[i] = i + 1;
    }

    sort_desc(arr, order, 8);

    for (i = 0; i < 5; i++) {
        sum += arr[i];
    }

    sort_asc(order, 5);

    printf("%d\n", sum);
    for (i = 0; i < 5; i++) {
        printf("%d ", order[i]);
    }
    printf("\n");

    return 0;
}

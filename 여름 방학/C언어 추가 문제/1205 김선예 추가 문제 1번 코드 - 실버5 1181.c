#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int compare(const void* arg1, const void* arg2) {
    if (strlen((const char*)arg1) > strlen((const char*)arg2)) return 1;
    else if (strlen((const char*)arg1) < strlen((const char*)arg2)) return -1;
    else return strcmp((char*)arg1, (char*)arg2);
}
int main(void){
    int size, length = 51;
    char arr[20000][51] = { 0 };
    scanf("%d", &size);

    for (int i = 0; i < size; i++)
        scanf("%s", arr[i]);
    qsort(arr, size, sizeof(arr[0]), compare);

    for (int i = 0; i < size; i++) {
        if (strcmp(arr[i], arr[i+1]) != 0 || i == size - 1)
            printf("%s\n", arr[i]);
    }
    return 0;
}
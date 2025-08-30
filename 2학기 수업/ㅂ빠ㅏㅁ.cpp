//二番目
#include <stdio.h>

int main() {
    char str[100];
    int sum = 0;

    scanf("%s", str);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 48 && str[i] <= 57) {
            sum += str[i] - 48;
        }
    }

    printf("%d\n", sum);
    return 0;
}

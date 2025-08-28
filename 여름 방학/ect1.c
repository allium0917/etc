#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    int result = 1;

    while (a != b) {
        if (b < a) {
            printf("-1\n");
            return 0;
        }

        if (b % 10 == 1) {
            b /= 10;
        } else if (b % 2 == 0) {
            b /= 2;
        } else {
            printf("-1\n");
            return 0;
        }
        result++;
    }

    printf("%d\n", result);
    return 0;
}

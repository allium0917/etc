#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int start = 1, end = 1, sum = 1, cnt = 0;

    while (start <= n / 2) {
        if (sum < n) {
            end++;
            sum += end;
        } else if (sum > n) {
            sum -= start;
            start++;
        } else {
            cnt++;
            sum -= start;
            start++;
        }
    }

    printf("%d\n", cnt + 1);
    return 0;
}
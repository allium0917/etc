#include <stdio.h>

int cnt_bits(int n) {
    int cnt = 0;
    while (n>0) {
        n &= (n-1);
        cnt++;
    }
    return cnt;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int bottles = 0;
    while (cnt_bits(n) > k) {
        n++;
        bottles++;
    }
    printf("%d\n", bottles);

    return 0;
}
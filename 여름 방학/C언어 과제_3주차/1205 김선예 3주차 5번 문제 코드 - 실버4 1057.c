#include <stdio.h>
int main() {
    int N, a, b;
    int cnt = 0;
    scanf("%d %d %d", &N, &a, &b);
    while (a!=b)
    {
        a = (a + 1) / 2;
        b = (b + 1) / 2;
        cnt++;
    }
    printf("%d", cnt);
}
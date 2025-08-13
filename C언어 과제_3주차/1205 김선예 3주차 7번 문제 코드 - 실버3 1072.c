#include <stdio.h>

int main() {
    long long X, Y;
    scanf("%lld %lld", &X, &Y);

    long long Z = (Y * 100) / X;

    if (Z >= 99) {
        printf("-1\n");
        return 0;
    }

    long long numerator = (Z + 1) * X - 100 * Y;
    long long denominator = 100 - (Z + 1);
    long long N = (numerator + denominator - 1) / denominator;

    printf("%lld\n", N);

    return 0;
}

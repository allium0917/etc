#include<stdio.h>

int main() {
    int N, M, i;
    int min[2] = {1000, 1000};
    int six, one, sum = 0;
    scanf("%d %d", &N, &M);

    for (i = 0; i < M; i++) {
        scanf("%d %d", &six, &one);
        if (six < min[0])
            min[0] = six;
        if (one < min[1])
            min[1] = one;
    }

    if (min[1] * 6 <= min[0])
        sum = min[1] * N;
    else {
        sum = (N / 6) * min[0];
        if (N % 6 != 0) {
            if (min[0] < min[1] * (N % 6))
                sum += min[0];
            else
                sum += min[1] * (N % 6);
        }
    }
    printf("%d", sum);
    return 0;
}
#include <stdio.h>

int main() {
    int n;
    int A[6];
    int i, j;
    long long sum = 0;

    scanf("%d", &n);
    for (i = 0; i < 6; i++) {
        scanf("%d", &A[i]);
    }

    int min1 = A[0], max1 = A[0];
    for (i = 1; i < 6; i++) {
        if (A[i] < min1) min1 = A[i];
        if (A[i] > max1) max1 = A[i];
    }

    int min2 = 1000000;
    for (i = 0; i < 6; i++) {
        for (j = i + 1; j < 6; j++) {
            if ((i + j) == 5 || (i == 1 && j == 4) || (i == 2 && j == 3)) continue;
            int sum2 = A[i] + A[j];
            if (sum2 < min2) min2 = sum2;
        }
    }

    int min3 = A[0] + A[1] + A[2];
    int faces[3];
    int combos[8][3] = {
        {0, 1, 2}, {0, 1, 3}, {0, 2, 4}, {0, 3, 4},
        {5, 1, 2}, {5, 1, 3}, {5, 2, 4}, {5, 3, 4}
    };
    for (i = 0; i < 8; i++) {
        int sum3 = A[combos[i][0]] + A[combos[i][1]] + A[combos[i][2]];
        if (sum3 < min3) min3 = sum3;
    }

    if (n == 1) {
        for (i = 0; i < 6; i++) sum += A[i];
        sum -= max1;
    } else {
        sum = (long long)min3 * 4 + (long long)min2 * 4 * (2 * n - 3) + (long long)min1 * (n - 2) * (5 * n - 6);
    }

    printf("%lld\n", sum);
    return 0;
}

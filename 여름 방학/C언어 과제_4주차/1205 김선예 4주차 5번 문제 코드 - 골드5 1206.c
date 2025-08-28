#include <stdio.h>
#include <string.h>

int N;
int A[50];
char s[20];

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%s", s);
        if (strlen(s) == 6) continue;
        int d1, d2;
         d1 = s[0] - '0';
        sscanf(s + 2, "%3d", &d2);
        A[i] = d1 * 1000 + d2;
    }

    for (int k = 1; k < 10001; k++) {
        int chk = 1;
        for (int i = 0; i < N; i++) {
            int L = 0, R = k * 10;
            while (L <= R) {
                int mid = (L + R) / 2;
                int val = 0;
                int temp = mid;
                for (int _ = 0; _ < 4; _++) {
                    val = val * 10 + temp / k;
                    temp %= k;
                    temp *= 10;
                }
                if (val < A[i]) L = (L + R) / 2 + 1;
                else if (val > A[i]) R = (L + R) / 2 - 1;
                else goto BREAK1;
            }
            chk = 0;
            goto BREAK2;
            BREAK1:;
        }
        BREAK2:
        if (chk) {
            printf("%d\n", k);
            return 0;
        }
    }
    return 0;
}

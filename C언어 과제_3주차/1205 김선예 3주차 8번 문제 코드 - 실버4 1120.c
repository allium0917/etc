#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int main() {
    char A[51], B[51];
    scanf("%s %s", A, B);

    int len_A = strlen(A);
    int len_B = strlen(B);
    int min_dif = len_A;

    for (int i = 0; i <= len_B - len_A; i++) {
        int dif = 0;
        for (int j = 0; j < len_A; j++) {
            if (A[j] != B[i + j]) {
                dif++;
            }
        }
        min_dif = min(min_dif, dif);
    }

    printf("%d\n", min_dif);

    return 0;
}
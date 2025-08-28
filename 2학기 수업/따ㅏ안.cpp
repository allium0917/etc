#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int arr[n][m];
    int num = 1;

    for(int d = 0; d <= n + m - 2; d++) {
        int start = d < n ? d : n - 1;
        int end = d < m ? 0 : d - m + 1;
        for(int i = start; i >= end; i--) {
            int j = d - i;
            arr[i][j] = num++;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            printf("%3d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}

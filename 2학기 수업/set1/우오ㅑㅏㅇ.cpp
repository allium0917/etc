//三番目
#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n][n];
    memset(arr, 0, sizeof(arr));

    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    int x = 0, y = 0, dir = 0;

    for (int i = 1; i <= n * n; i++) {
        arr[x][y] = i;

        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx < 0 || nx >= n || ny < 0 || ny >= n || arr[nx][ny] != 0) {
            dir = (dir + 1) % 4;
            nx = x + dx[dir];
            ny = y + dy[dir];
        }

        x = nx;
        y = ny;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%3d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}

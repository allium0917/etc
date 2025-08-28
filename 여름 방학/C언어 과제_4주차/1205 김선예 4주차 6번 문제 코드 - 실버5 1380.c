#include <stdio.h>
#include <string.h>

#define MAXN 100
#define MAXLEN 105

int main() {
    int t = 1;
    while (1) {
        int n;
        scanf("%d", &n);
        if (!n) break;

        char name[MAXN][MAXLEN];
        int m[MAXN];
        getchar();

        for (int i = 1; i <= n; i++) {
            fgets(name[i - 1], MAXLEN, stdin);
            int len = strlen(name[i - 1]);
            if (len > 0 && name[i - 1][len - 1] == '\n')
                name[i - 1][len - 1] = '\0';
            m[i] = 2;
        }

        for (int i = 0; i < 2 * n - 1; i++) {
            int a; char c;
            scanf("%d %c", &a, &c);
            m[a]--;
        }

        for (int i = 1; i <= n; i++) {
            if (m[i]) {
                printf("%d %s\n", t, name[i - 1]);
            }
        }
        t++;
    }
    return 0;
}

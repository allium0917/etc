#include <stdio.h>

int main() {
    int N, myscoure, P;
    int scourelist[100] = {0};
    int rankcount = 0, myrank = 1;

    scanf("%d %d %d", &N, &myscoure, &P);
    for (int i = 0; i < N; i++) scanf("%d", &scourelist[i]);

    for (int i = 0; i < N; i++) {
        if (myscoure < scourelist[i]) myrank++;
        else if (myscoure > scourelist[i]) break;
        rankcount++;
    }

    if (rankcount == P) myrank = -1;
    if (N == 0) myrank = 1;

    printf("%d\n", myrank);
    return 0;
}

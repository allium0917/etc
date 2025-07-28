#include<stdio.h>

void stick()
{
    int S = 64;
    int N;
    int cnt = 0;
    scanf("%d", &N);
    while (N>0)
    {
        if (S > N)
            S /= 2;
        else
        {
            cnt++;
            N -= S;
        }
    }
    printf("%d", cnt);
}
int main()
{
    stick();
}
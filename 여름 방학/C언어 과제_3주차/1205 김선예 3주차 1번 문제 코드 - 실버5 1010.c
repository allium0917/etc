#include<stdio.h>
int main(void)
{
    int k,n,m,d;
    scanf("%d", &k);
    for(int z=0; z<k; z++)
    {
        d=1;
        scanf("%d %d", &n, &m);
        for(int i=0; i<n; i++)
        {
            d*=m-i;
            d/=1+i;
        }
        printf("%d\n", d);
    }
}
//백준 1004번 | 어린 왕자

#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int x1,x2,y1,y2,c=0;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        int k;
        scanf("%d",&k);
        for(int j=0;j<k;j++)
        {
            int cx,cy,r,a,b;
            scanf("%d%d%d",&cx,&cy,&r);
            a=pow(cx-x1,2)+pow(cy-y1,2);
            b=pow(cx-x2,2)+pow(cy-y2,2);
            if((a>r*r&&b<=r*r)||(a<=r*r&&b>r*r)) c++;
        }
        printf("%d\n",c);
    }
}
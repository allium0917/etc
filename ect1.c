#include<stdio.h>

int main()
{
    char s1[10001],s2[10001];
    scanf("%s %s",s1,s2);

    long long int sum=0;
    for(int i=0; s1[i]; i++){
        for(int j=0; s2[j]; j++){
            sum+=(s1[i]-'0') * (s2[j]-'0');
        }
    }

    printf("%lld",sum);




    return 0;
}

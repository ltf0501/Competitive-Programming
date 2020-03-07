#include<cstdio>

int f[210];
int k(int a)
{
    if(a==1)return f[1]=1;
    if(a%2!=0)return f[a]=k(a-1)+1;
    return f[a]=k(a-1)+2;
}
main()
{
    k(205);
    int n;
    while(scanf("%d",&n)==1)
    {
        printf("%d\n",f[n]);
    }
    return 0;
}

#include<cstdio>

int f(int n)
{
    return n==1?1:f(n/2)+1;
}
main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        printf("%d\n",f(n));
    }
    return 0;
}

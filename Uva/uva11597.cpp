#include<cstdio>

main()
{
    int n,cas=0;
    while(scanf("%d",&n)==1 && n)
    {
        printf("Case %d: %d\n",++cas,n/2);
    }
    return 0;
}

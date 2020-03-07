#include<cstdio>

using namespace std;
#define inf 2147483647
main()
{
    int t,n,m;
    scanf("%d",&t);
    while(t--)
    {
        int flag=0;
        scanf("%d%d",&n,&m);
        int k;
        for(int i=1;i<=m;i++)
        {
            scanf("%d",&k);
            if(k<n)flag=1;
        }
        //printf("%d %d\n",n,cur);
        if(flag)printf("NOOOO!!! JACKY XX!\n");
        if(!flag)printf("YEEES!!! INKER!\n");
    }
    return 0;
}

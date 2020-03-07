#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int a[22],t[22];
main()
{
    int n;scanf("%d",&n);
    int x,y;
    while(~scanf("%d%d",&x,&y))
    {
        for(int i=1;i<=n;i++)
        {
            if(t[i])t[i]--;
            if(!t[i])a[i]=0;
        }
        a[0]=0;a[n+1]=0;
        int cnt=0;
        bool flag=0;
        for(int i=1;i<=n;i++)
            if(!a[i-1] && !a[i] && !a[i+1]){a[i]=x,t[i]=y,flag=1;break;}
        if(!flag)
        {
            for(int i=1;i<=n;i++)
            {
                if(!a[i]){a[i]=x,t[i]=y,flag=1;break;}
            }
        }
        if(!flag)puts("  Not enough");
        printf("Number:");
        for(int i=1;i<=n;i++)printf(" %d",a[i]);
        puts("");
        printf("  Time:");
        for(int i=1;i<=n;i++)printf(" %d",t[i]);
        puts("");
    }
    return 0;
}

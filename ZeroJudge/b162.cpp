#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 200000+10
main()
{
    int n,a[maxn],vis[maxn];
    while(scanf("%d",&n)==1)
    {
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++)scanf("%d",&a[i]);
        sort(a,a+n);
        //for(int i=0;i<n;i++)printf("%d ",a[i]);
        puts("");
        int l=0,r=0;
        while(r<=n)
        {
            if(a[r]==a[l])r++;
            else
            {
                int cnt=r-l;
                printf("%d %d\n",a[l],cnt);
                l=r;
            }
        }
    }
    return 0;
}

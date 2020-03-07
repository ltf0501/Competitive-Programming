#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 20000+5
#define INF 2147483647
struct node
{
    int w,h;
    bool operator < (const node& b)const
    {
        return w<b.w || (w==b.w && h>b.h);
    }
}d[maxn];
int g[maxn],dp[maxn];
main()
{
    int t,n;scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)scanf("%d%d",&d[i].w,&d[i].h);
        sort(d,d+n);
        fill(g+1,g+n+1,INF);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int k=lower_bound(g+1,g+n+1,d[i].h)-g;
            dp[i]=k;
            g[k]=d[i].h;
            ans=max(ans,dp[i]);
            //printf("now = %d\n",ans);
        }
        printf("%d\n",ans);
    }
    return 0;
}

#include<cstdio>
#include<algorithm>
using namespace std;
struct P
{
    int l,w,h;
}b[305];
int cnt;
bool cmp(P a,P b)
{
    if(a.l==b.l)return a.w<b.w;
    return a.l<b.l;
}
main()
{
    int cas=0,n;
    while(~scanf("%d",&n) && n)
    {
        cnt=0;
        for(int i=1;i<=n;i++)
        {
            int l,w,h;scanf("%d%d%d",&l,&w,&h);
            b[++cnt]={l,w,h};
            b[++cnt]={l,h,w};
            b[++cnt]={w,l,h};
            b[++cnt]={w,h,l};
            b[++cnt]={h,l,w};
            b[++cnt]={h,w,l};
        }
        sort(b+1,b+cnt+1,cmp);
        int dp[305],mx=0;
        for(int i=1;i<=cnt;i++)
        {
            dp[i]=b[i].h;
            for(int j=1;j<i;j++)
                if(b[i].l>b[j].l && b[i].w>b[j].w && dp[j]+b[i].h>dp[i])
                    dp[i]=dp[j]+b[i].h;
            mx=max(mx,dp[i]);
        }
        printf("Case %d: maximum height = %d\n",++cas,mx);
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define maxn 6010
#define INF 1000000000
struct P
{
    int w,p;
    bool operator < (const P& b)const
    {
        return p<b.p;
    }
}a[maxn];
int dp[maxn];
main()
{
    int n=0,w,p;
    while(~scanf("%d%d",&w,&p))
        a[++n]={w,p};
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)dp[i]=0x7ffffff;
    int mx=0;
    for(int i=1;i<=n;i++)for(int j=mx+1;j>0;j--)
        if(dp[j]>dp[j-1]+a[i].w && a[i].p>dp[j-1]+a[i].w)
            dp[j]=dp[j-1]+a[i].w,mx=max(mx,j);
    printf("%d\n",mx);
    return 0;
}

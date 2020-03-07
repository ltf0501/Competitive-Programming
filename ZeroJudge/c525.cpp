#include<bits/stdc++.h>
using namespace std;
const int maxn=21;
const double INF=1e9;
double dp[maxn][1<<maxn];
int n;
int x[maxn],y[maxn];
double dist(int i,int j)
{
    if(i==0 || j==0)return 0.0;
    return sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
}
main()
{
    //printf("%f\n",INF);
    int t;scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d%d",&x[i],&y[i]);
        for(int i=0;i<(1<<(n+1));i++)for(int j=0;j<=n;j++)dp[j][i]=INF;
        dp[0][1]=0.0;
        for(int j=1;j<(1<<(n+1));j++)
        {
            for(int i=1;i<=n;i++)if(!(j&(1<<i)))
            {
                for(int k=0;k<=n;k++)if(j&(1<<k))
                    dp[i][j^(1<<i)]=min(dp[i][j^(1<<i)],dp[k][j]+dist(i,k));
            }
        }
        double ans=INF;
        for(int i=1;i<=n;i++)ans=min(ans,dp[i][(1<<(n+1))-1]);
        cout<<fixed<<setprecision(2)<<ans<<'\n';
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define maxn 205
#define INF 1000000000
int d[maxn][maxn];
int dp[2][maxn][maxn];
int n;
void init(bool flag)
{
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dp[flag][i][j]=INF;
}
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)scanf("%d",&d[i][j]);
    init(0),init(1);
    int x,pre=1;
    bool flag=0,t=0;
    while(scanf("%d",&x)!=EOF)
    {
        flag^=1;
        init(flag);
        if(!t)
        {
            t=1;
            dp[flag][1][2]=dp[flag][2][1]=d[3][x];
            dp[flag][2][3]=dp[flag][3][2]=d[1][x];
            dp[flag][1][3]=dp[flag][3][1]=d[2][x];
            pre=x;
            continue;
        }
        for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
        {
            dp[flag][i][j]=min(dp[flag][i][j],dp[flag^1][i][j]+d[pre][x]);
            dp[flag][pre][j]=min(dp[flag][pre][j],dp[flag^1][i][j]+d[i][x]);
            dp[flag][pre][i]=min(dp[flag][pre][i],dp[flag^1][i][j]+d[j][x]);
        }
        pre=x;
        /*
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)printf("%d ",dp[flag][i][j]);puts("");
        }
        */
    }
    int ans=INF;
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)ans=min(ans,dp[flag][i][j]);
    printf("%d\n",ans);
    return 0;
}

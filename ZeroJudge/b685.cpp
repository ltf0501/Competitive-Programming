#include<bits/stdc++.h>
using namespace std;
#define maxn 1010
const int mod=1e6+7;
int dp[maxn][maxn];
int a[maxn],n,m;
bool vis[maxn];
int dfs(int st,int u)
{
    if(vis[u])return 0;
    vis[u]=1;
    if(!a[u])return 0;
    if(a[u]==st)return 1;
    return dfs(st,a[u]);
}
main()
{
    for(int i=0;i<=1000;i++)dp[i][0]=0,dp[i][i]=1;
    for(int i=1;i<=1000;i++)for(int j=1;j<i;j++)
        dp[i][j]=(dp[i-1][j-1]+(i-1)*dp[i-1][j])%mod;
    int t;scanf("%d",&t);
    while(t--)
    {
        memset(vis,0,sizeof(vis));
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        int cnt=0;
        for(int i=1;i<=n;i++)if(!a[i])cnt++;
        for(int i=1;i<=n;i++)if(a[i] && !vis[i])
            m-=dfs(i,i);
        printf("%d\n",dp[cnt][m]);
    }
    return 0;
}

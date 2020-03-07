#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
#define ll long long
const int mod=1e9+7;
int n,m,k,x;
int sz[maxn];
vector<int> g[maxn];
ll dp[maxn][11][3],tmp[11][3];
ll dfs(int u,int fa)
{
    sz[u]=1;
    dp[u][0][0]=k-1,dp[u][1][1]=1,dp[u][0][2]=m-k;
    for(int v : g[u])if(v!=fa)
    {
        dfs(v,u);
        for(int i=0;i<=x;i++)for(int j=0;j<3;j++)tmp[i][j]=0;
        for(int i=0;i<=sz[u];i++)for(int j=0;j<=sz[v];j++)if(i+j<=x)
        {
            tmp[i+j][0]=(tmp[i+j][0]+dp[u][i][0]*(dp[v][j][0]+dp[v][j][1]+dp[v][j][2]))%mod;
            tmp[i+j][1]=(tmp[i+j][1]+dp[u][i][1]*dp[v][j][0])%mod;
            tmp[i+j][2]=(tmp[i+j][2]+dp[u][i][2]*(dp[v][j][0]+dp[v][j][2]))%mod;
        }
        sz[u]=min(sz[u]+sz[v],x);
        for(int i=0;i<=sz[u];i++)for(int j=0;j<3;j++)dp[u][i][j]=tmp[i][j];
    }
}
main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<n;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        g[x].push_back(y),g[y].push_back(x);
    }
    scanf("%d%d",&k,&x);
    dfs(1,0);
    ll ans=0;
    for(int i=0;i<=x;i++)for(int j=0;j<3;j++)ans=(ans+dp[1][i][j])%mod;
    printf("%I64d\n",ans);
    return 0;
}

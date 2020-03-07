#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
#define maxn 100010
#define pii pair<int,int>
#define F first
#define S second
vector<pii> g[maxn];
int n,s,tot;
int dp[2][maxn];
void dfs1(int u,int fa)
{
    for(int i=0;i<g[u].size();i++)
    {
        pii v=g[u][i];
        if(v.F==fa)continue;
        dfs1(v.F,u);
        if(dp[0][v.F]+v.S>dp[0][u])dp[1][u]=dp[0][u],dp[0][u]=dp[0][v.F]+v.S;
        else if(dp[0][v.F]+v.S>dp[1][u])dp[1][u]=dp[0][v.F]+v.S;
    }
}
int dfs2(int u,int fa)
{
    int ret=0;
    for(int i=0;i<g[u].size();i++)
    {
        pii v=g[u][i];
        if(v.F==fa)continue;
        ret=max(ret,dfs2(v.F,u));
    }
    ret=max(ret,dp[0][u]+dp[1][u]);
    return ret;
}
int main()
{
    scanf("%d%d",&n,&s);
    for(int i=1;i<n;i++)
    {
        int x,y,d;scanf("%d%d%d",&x,&y,&d);
        g[x].push_back(pii(y,d)),g[y].push_back(pii(x,d));
        tot+=d;
    }
    dfs1(1,-1);
    s=dfs2(1,-1);
    printf("%d\n",2*tot-s);
    return 0;
}

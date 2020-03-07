#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
bool vis[maxn];
int dp[maxn],n,m,a[maxn];
vector<int> g[maxn];
int dfs(int u)
{
    if(vis[u])return dp[u];
    vis[u]=1;
    if(!g[u].size())return dp[u]=a[u];
    int mx=0;
    for(int v : g[u])
    {
        mx=max(mx,dfs(v)+(a[u] && !a[v]));
    }
    return dp[u]=mx;
}
main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=m;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        g[x].push_back(y);
    }
    for(int i=0;i<n;i++)
        if(!vis[i])dfs(i);
    int mx=0;
    for(int i=0;i<n;i++)mx=max(mx,dp[i]);
    //for(int i=0;i<n;i++)printf("%d ",dp[i]);puts("");
    printf("%d\n",mx);
    return 0;
}

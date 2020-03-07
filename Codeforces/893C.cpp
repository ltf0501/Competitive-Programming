#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
#define ll long long
vector<int> g[maxn];
int n,m;
int a[maxn],dp[maxn];
bool vis[maxn];
int dfs(int u)
{
    vis[u]=1;
    int ret=a[u];
    for(int v : g[u])if(!vis[v])ret=min(ret,dfs(v));
    return dp[u]=ret;
}
main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=m;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        g[x].push_back(y),g[y].push_back(x);
    }
    ll ans=0;
    for(int i=1;i<=n;i++)
        if(!vis[i])ans+=dfs(i);
    printf("%I64d\n",ans);
    return 0;
}

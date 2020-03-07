#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
#define ll long long
vector<int> g[maxn];
int a[maxn];
int n;
ll sz[maxn];
ll dp[maxn],dp2[maxn];
void dfs1(int u,int fa)
{
    sz[u]=a[u];
    for(int v : g[u])if(v!=fa)
    {
        dfs1(v,u);
        sz[u]+=sz[v];
        dp[u]+=dp[v]+sz[v];
    }
}
void dfs2(int u,int fa)
{
    if(fa)
    {
        dp2[u]=dp2[fa]+(sz[1]-sz[fa])+(dp[fa]-dp[u]-sz[u])+(sz[fa]-sz[u]);
    }
    for(int v : g[u])if(v!=fa)
        dfs2(v,u);
}
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<n;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        g[x].push_back(y),g[y].push_back(x);
    }
    dfs1(1,0);dfs2(1,0);
    ll ans=0;
    for(int i=1;i<=n;i++)ans=max(ans,dp[i]+dp2[i]);
    //for(int i=1;i<=n;i++)printf("%lld %lld\n",dp[i],dp2[i]);
    printf("%lld\n",ans);
    return 0;
}


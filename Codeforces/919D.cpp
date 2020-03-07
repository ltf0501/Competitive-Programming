#include<bits/stdc++.h>
using namespace std;
#define maxn 300010
char c[maxn];
int n,m;
vector<int> g[maxn];
int vis[maxn];
bool dfs1(int u)
{
    if(vis[u]==1)return 1;
    if(vis[u]==-1)return 0;
    vis[u]=-1;
    for(int v : g[u])
        if(!dfs1(v))return 0;
    vis[u]=1;
    return 1;
}
int dp[maxn][26],ans=0;
bool vis2[maxn];
void dfs2(int u)
{
    if(vis2[u])return ;
    vis2[u]=1;
    for(int v : g[u])
    {
        dfs2(v);
        for(int i=0;i<26;i++)dp[u][i]=max(dp[u][i],dp[v][i]);
    }
    dp[u][c[u]-'a']++;
    for(int i=0;i<26;i++)ans=max(ans,dp[u][i]);
}
main()
{
    scanf("%d%d",&n,&m);
    scanf("%s",c+1);
    for(int i=1;i<=m;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        g[x].push_back(y);
    }
    for(int i=1;i<=n;i++)if(!vis[i])
    {
        if(!dfs1(i))return 0*puts("-1");
    }
    for(int i=1;i<=n;i++)if(!vis2[i])
    {
        dfs2(i);
    }
    printf("%d\n",ans);
    return 0;
}

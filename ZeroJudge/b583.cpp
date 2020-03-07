#include<bits/stdc++.h>
using namespace std;
#define maxn 1010
vector<int> g[maxn];
int vis[maxn];
int n,m;
void init()
{
    for(int i=1;i<=n;i++)g[i].clear();
    memset(vis,0,sizeof(vis));
}
bool dfs(int u)
{
    if(vis[u]==1)return 1;
    if(vis[u]==-1)return 0;
    vis[u]=-1;
    for(int v : g[u])
        if(!dfs(v))return 0;
    vis[u]=1;
    return 1;
}
main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        init();
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++)
        {
            int x,y;scanf("%d%d",&x,&y);
            g[x].push_back(y);
        }
        bool ok=1;
        for(int i=1;i<=n;i++)
            if(!vis[i])ok&=dfs(i);
        puts(ok ? "W+W" : "O______O");
    }
    return 0;
}

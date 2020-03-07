#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
#define maxn 50000+5
vector<int> G[maxn];
int vis[maxn];
int dfs(int u)
{

    for(int i=0;i<G[u].size();i++)
    {
        int v=G[u][i];
        if(vis[v]==vis[u])return 0;
        if(!vis[v])
        {
            vis[v]=3-vis[u];
            if(!dfs(v))return 0;
        }
    }
    return 1;
}
main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)==2 && n+m)
    {
        for(int i=1;i<=n;i++)G[i].clear();
        memset(vis,0,sizeof(vis));
        while(m--)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            G[x].push_back(y);
            G[y].push_back(x);
        }
        vis[1]=1;
        puts(dfs(1) ? "Yes" : "No");
    }
    return 0;
}

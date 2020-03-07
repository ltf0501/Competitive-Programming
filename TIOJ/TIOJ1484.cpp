#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
vector<int> g[maxn];
int vis[maxn];
int low[maxn],lev[maxn];
bool dfs(int u,int dep)
{
    lev[u]=low[u]=dep;
    vis[u]=-1;
    int num=0;
    for(int v : g[u])
    {
        if(vis[v]==1)return 0;
        else if(vis[v]==-1)num++,low[u]=min(low[u],lev[v]);
        else
        {
            if(!dfs(v,dep+1))return 0;
            low[u]=min(low[u],low[v]);
            if(low[v]>lev[u])return 0;
            if(low[v]<lev[u])num++;
        }
    }
    vis[u]=1;
    return num<2;
}
main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int n,m;scanf("%d%d",&n,&m);
        fill(vis,vis+n,0);
        for(int i=0;i<n;i++)g[i].clear();
        for(int i=0;i<m;i++)
        {
            int x,y;scanf("%d%d",&x,&y);
            if(x!=y)g[x].push_back(y);
        }
        if(!dfs(0,0)){puts("NO");continue;}
        bool ok=1;
        for(int i=0;i<n;i++)
            if(!vis[i]){ok=0;break;}
        puts(ok ? "YES" : "NO");
    }

    return 0;
}

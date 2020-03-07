#include<bits/stdc++.h>
using namespace std;
#define maxn 1005
vector<int> g[maxn];
int pre[maxn],dfs_clock;
int dfs(int u,int fa)
{
    int lowu=pre[u]=++dfs_clock;
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(!pre[v])
        {
            int lowv=dfs(v,u);
            lowu=min(lowu,lowv);
            if(lowv>pre[u])printf("%d %d\n",u,v),printf("%d %d\n",v,u);
            else printf("%d %d\n",u,v);
        }
        else if(pre[v]<pre[u] && v!=fa)
        {
            lowu=min(lowu,pre[v]);
            printf("%d %d\n",u,v);
        }
    }
    return lowu;
}
main()
{
    int n,m,cas=0;
    while(~scanf("%d%d",&n,&m) && n+m)
    {
        dfs_clock=0;
        for(int i=1;i<=n;i++)g[i].clear();
        memset(pre,0,sizeof(pre));
        while(m--)
        {
            int x,y;scanf("%d%d",&x,&y);
            g[x].push_back(y),g[y].push_back(x);
        }
        printf("%d\n\n",++cas);
        dfs(1,-1);
        puts("#");
    }
}

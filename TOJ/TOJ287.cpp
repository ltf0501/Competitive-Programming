#include<bits/stdc++.h>
using namespace std;
#define maxn 205
vector<int> g[maxn];
int match[maxn];
bool vis[maxn];
int n,m,cnt;
bool dfs(int u)
{
    vis[u]=1;
    for(int v : g[u])if(!vis[match[v]])
    {
        if(!match[v] || dfs(match[v]))
        {
            if(!match[v])cnt++;
            match[v]=u;
            return 1;
        }
    }
    return 0;
}
main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)g[i].clear();
        for(int i=1;i<=m;i++)
        {
            int x,y;scanf("%d%d",&x,&y);
            g[x].push_back(y);
        }
        cnt=0;
        memset(match,0,sizeof(match));
        for(int i=1;i<=n;i++)
        {
            dfs(i);
            memset(vis,0,sizeof(vis));
        }
        printf("%d\n",n-cnt);
    }
    return 0;
}

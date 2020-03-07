#include<bits/stdc++.h>
using namespace std;
#define maxn 505
vector<int> g[maxn];
int match[maxn];
bool vis[maxn];
int cnt=0;
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
    int n,k;scanf("%d%d",&n,&k);
    for(int i=1;i<=k;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        g[x].push_back(y);
    }
    for(int i=1;i<=n;i++)
    {
        dfs(i);
        //for(int i=1;i<=n;i++)printf("%d ",match[i]);puts("");
        memset(vis,0,sizeof(vis));
    }
    printf("%d\n",cnt);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
int n,m;
vector<int> g[maxn];
int deg[maxn];
bool vis[maxn];
int cur=0;
vector<int> com[maxn];
void dfs(int u)
{
    vis[u]=1;
    com[cur].push_back(u);
    for(int v : g[u])
        if(!vis[v])dfs(v);
}
main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        g[x].push_back(y),g[y].push_back(x);
        deg[x]++,deg[y]++;
    }
    for(int i=1;i<=n;i++)
        if(!vis[i])cur++,dfs(i);
    int ans=0;
    for(int i=1;i<=cur;i++)
    {
        bool flag=1;
        for(int s : com[i])flag&=(deg[s]==2);
        ans+=flag;
    }
    printf("%d\n",ans);
    return 0;
}

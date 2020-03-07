#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
int n,ans[maxn];
vector<int> g[maxn],now;
bool vis[maxn];
int sz[maxn],mx[maxn];
void get_cen(int u)
{
    sz[u]=1,vis[u]=1,mx[u]=0;
    now.push_back(u);
    for(int v : g[u])if(!vis[v])
    {
        get_cen(v);
        sz[u]+=sz[v];
        mx[u]=max(mx[u],sz[v]);
    }
}
void dfs(int u,int d)
{
    get_cen(u);
    int cen=-1;
    int s=now.size();
    for(int w : now)
    {
        if(max(mx[w],s-sz[w])<=s/2)cen=w;
        vis[w]=0;
    }
    now.clear();
    if(cen==-1)return ;
    ans[cen]=d,vis[cen]=1;
    for(int v : g[cen])
        if(!vis[v])dfs(v,d+1);
}
main()
{
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        g[x].push_back(y),g[y].push_back(x);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++)printf("%c ",ans[i]+'A');
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
int n,m;
vector<int> g[maxn];
int a[maxn];
bool vis[maxn];
set<int> s;
void dfs(int u)
{
    s.insert(u);
    vis[u]=1;
    for(int v : g[u])if(!vis[v])
        dfs(v);
}
main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=m;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        g[x].push_back(y),g[y].push_back(x);
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])dfs(i);
        for(int k : s)if(s.find(a[k])!=s.end())ans++;
        s.clear();
    }
    printf("%d\n",ans);
    return 0;
}


#include<bits/stdc++.h>
using namespace std;
#define maxn 1005
vector<int> g[maxn];
int s[maxn],sum[maxn],val[maxn];
void dfs(int u,int fa)
{
    for(int v : g[u])if(v!=fa)
    {
        dfs(v,u);
        sum[u]+=sum[v];
    }
    if(!g[u].size())val[u]=s[u],sum[u]=val[u];
}
main()
{
    int n;scanf("%d",&n);
    for(int i=2;i<=n;i++)
    {
        int x;scanf("%d",&x);
        g[i].push_back(x),g[x].push_back(i);
    }
    for(int i=1;i<=n;i++)scanf("%d",&s[i]);
    return 0;
}

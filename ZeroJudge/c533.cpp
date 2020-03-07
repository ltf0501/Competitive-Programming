#include<bits/stdc++.h>
using namespace std;
#define maxn 1000010
int n,m,r;
vector<int> g[maxn];
int sz[maxn];
void dfs(int u,int fa)
{
    sz[u]=1;
    for(int v : g[u])if(v!=fa)
        dfs(v,u),sz[u]+=sz[v];
}
main()
{
    scanf("%d%d%d",&n,&m,&r);
    for(int i=1;i<n;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        g[x].push_back(y),g[y].push_back(x);
    }
    dfs(r,-1);
    while(m--)
    {
        int x;scanf("%d",&x);
        printf("%d\n",sz[x]);
    }
    return 0;
}

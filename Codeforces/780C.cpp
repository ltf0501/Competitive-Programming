#include<bits/stdc++.h>
using namespace std;
#define maxn 200000+10
int mx=1;
int c[maxn];
vector<int> g[maxn];
void dfs(int u,int fa)
{
    int col=1;
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(v==fa)continue;
        while(col==c[fa] || col==c[u])col++;
        c[v]=col++;
        dfs(v,u);
    }
    mx=max(mx,col-1);
}
main()
{
    int n;scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        g[x].push_back(y),g[y].push_back(x);
    }
    c[1]=1;
    dfs(1,0);
    printf("%d\n",mx);
    for(int i=1;i<=n;i++)printf("%d ",c[i]);puts("");
    return 0;
}

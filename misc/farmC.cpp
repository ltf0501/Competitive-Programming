#include<bits/stdc++.h>
using namespace std;
#define maxn 15
vector<int> g[maxn];
int cnt=0;
bool vis[maxn];
void dfs(int u,int k,int sz)
{
    vis[u]=1;
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(v<k)continue;
        if(vis[v])
        {
            if(v==k && sz>=3)cnt++;
            continue;
        }
        dfs(v,k,sz+1);
    }
    vis[u]=0;
}
main()
{
    int n,m;scanf("%d%d",&n,&m);
    while(m--)
    {
        int x,y;scanf("%d%d",&x,&y);
        g[x].push_back(y),g[y].push_back(x);
    }
    for(int i=1;i<=n;i++)dfs(i,i,1);
    printf("%d\n",cnt/2);
    return 0;
}

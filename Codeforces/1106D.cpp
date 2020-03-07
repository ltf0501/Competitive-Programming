#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
int n,m;
vector<int> g[maxn];
priority_queue<int,vector<int>,greater<int> > pq;
bool vis[maxn];
main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        g[x].push_back(y),g[y].push_back(x);
    }
    pq.push(1);
    while(!pq.empty())
    {
        int u=pq.top();pq.pop();
        if(vis[u])continue ;
        vis[u]=1;printf("%d ",u);
        for(int v : g[u])if(!vis[v])pq.push(v);
    }
    return 0;
}

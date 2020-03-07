#include<bits/stdc++.h>
#include"lib1481.h"
using namespace std;
#define maxn 2005
#define maxE 20005
struct E{int from,to;};
vector<E> edge;
vector<int> g[maxn];
bool vis[maxE];
int a[maxE],cnt=0;
void dfs(int x)
{
    for(int i : g[x])if(!vis[i])
    {
        int u=edge[i].from==x ? edge[i].to : edge[i].from;
        vis[i]=1;
        a[i]=++cnt;
        dfs(u);
    }
}
main()
{
    Init();
    int n,k;scanf("%d%d",&n,&k);
    for(int i=0;i<k;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        edge.push_back({x,y});
        g[x].push_back(i),g[y].push_back(i);
    }
    dfs(1);
    Possible();
    for(int i=0;i<k;i++)Number(a[i]);
    Finish();
    return 0;
}

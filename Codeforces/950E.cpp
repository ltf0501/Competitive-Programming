#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
vector<int> g[maxn];
int n,m,h;
int a[maxn];
int pre[maxn],lowlink[maxn],sccno[maxn],dfs_clock,scc_cnt,topo[maxn];
vector<int> scc_g[maxn],scc[maxn];
stack<int> S;
int sz[maxn];
void dfs(int u)
{
    pre[u]=lowlink[u]=++dfs_clock;
    S.push(u);
    for(int v : g[u])
    {
        if(!pre[v])
        {
            dfs(v);
            lowlink[u]=min(lowlink[u],lowlink[v]);
        }
        else if(!sccno[v])lowlink[u]=min(lowlink[u],pre[v]);
    }
    if(lowlink[u]==pre[u])
    {
        scc_cnt++;
        while(1)
        {
            int x=S.top();S.pop();
            sccno[x]=scc_cnt;
            scc[scc_cnt].push_back(x);
            sz[scc_cnt]++;
            if(x==u)break;
        }
    }
}
void find_scc()
{
    dfs_clock=scc_cnt=0;
    memset(sccno,0,sizeof(sccno));
    memset(pre,0,sizeof(pre));
    for(int i=1;i<=n;i++)
        if(!pre[i])dfs(i);
}
int deg[maxn];
void build()
{
    for(int u=1;u<=n;u++)for(int v : g[u])
        if(sccno[u]!=sccno[v])scc_g[sccno[u]].push_back(sccno[v]),deg[sccno[u]]++;
}
main()
{
    scanf("%d%d%d",&n,&m,&h);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=m;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        if((a[x]+1)%h==a[y])g[x].push_back(y);
        if((a[y]+1)%h==a[x])g[y].push_back(x);
    }
    find_scc();
    build();
    //printf("%d\n",scc_cnt);
    int mi=maxn,id=-1;
    for(int i=1;i<=scc_cnt;i++)
        if(sz[i]<mi && !deg[i])mi=sz[i],id=i;
    printf("%d\n",mi);
    for(int s : scc[id])printf("%d ",s);
    return 0;
}

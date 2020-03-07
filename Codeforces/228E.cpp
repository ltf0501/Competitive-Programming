#include<bits/stdc++.h>
using namespace std;
#define maxn 205
vector<int> g[maxn],scc_g[maxn];
int n,m;
int in[maxn],dfs_clock;
int sccno[maxn],scc_cnt;
stack<int> s;
int dfs1(int u)
{
    s.push(u);
    int lowu=in[u]=++dfs_clock;
    for(int v : g[u])
    {
        if(!in[v])lowu=min(lowu,dfs1(v));
        else if(!sccno[v])lowu=min(lowu,in[v]);
    }
    if(lowu==in[u])
    {
        scc_cnt++;
        while(1)
        {
            int x=s.top();s.pop();
            sccno[x]=scc_cnt;
            if(x==u)break;
        }
    }
    return lowu;
}
void find_scc()
{
    for(int i=0;i<2*n;i++)
        if(!in[i])dfs1(i);
}
void build()
{
    for(int u=0;u<2*n;u++)for(int v : g[u])
        if(sccno[u]!=sccno[v])g[sccno[u]].push_back(sccno[v]);
}
bool vis[maxn];
int topo[maxn],cur=0;
void dfs2(int u)
{
    if(vis[u])return ;
    vis[u]=1;
    for(int v : scc_g[u])dfs2(v);
    topo[u]=++cur;
}
vector<int> ans;
main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int x,y,d;scanf("%d%d%d",&x,&y,&d);
        x--,y--,d^=1;
        g[x<<1].push_back((y<<1)^d);
        g[y<<1].push_back((x<<1)^d);
        g[x<<1|1].push_back((y<<1)^(d^1));
        g[y<<1|1].push_back((x<<1)^(d^1));
    }
    find_scc();
    for(int i=0;i<2*n;i+=2)
        if(sccno[i]==sccno[i^1])return 0*puts("Impossible");
    build();
    for(int i=0;i<2*n;i++)
        if(!vis[i])dfs2(i);
    for(int i=0;i<2*n;i+=2)
        if(topo[sccno[i]]<topo[sccno[i^1]])ans.push_back(i>>1);
    printf("%d\n",ans.size());
    for(int s : ans)printf("%d ",s+1);
    return 0;
}

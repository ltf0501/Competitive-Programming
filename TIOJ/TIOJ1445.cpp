#include<bits/stdc++.h>
using namespace std;
#define maxn 1010
#define maxm 500010
#define INF 10000000000000
#define ll long long
struct E
{
    int u,v;
    ll w;
    bool operator < (const E& b)const
    {
        return w<b.w;
    }
}e[maxm];
bool tr[maxm];
int n,m;
struct node
{
    int to;
    ll dis;
    node(int to,ll dis):to(to),dis(dis){}
};
int p[maxn];
int finds(int x){return p[x]==x ? x : p[x]=finds(p[x]);}
vector<node> g[maxn];
ll kruskal()
{
    for(int i=1;i<=n;i++)p[i]=i;
    int cnt=0;
    ll ans=0;
    for(int i=1;i<=m;i++)
    {
        int x=finds(e[i].u),y=finds(e[i].v);
        if(x==y)continue;
        p[x]=y;cnt++;
        tr[i]=1;
        g[e[i].u].push_back(node(e[i].v,e[i].w));
        g[e[i].v].push_back(node(e[i].u,e[i].w));
        ans+=e[i].w;
        if(cnt==n-1)break;
    }
    if(cnt==n-1)return ans;
    return -1;
}
int anc[13][maxn];
ll ancdis[13][maxn];
int in[maxn],out[maxn],dfs_clock=0;
void dfs(int u,int fa)
{
    in[u]=++dfs_clock;
    for(auto v : g[u])
    {
        if(v.to==fa)continue;
        anc[0][v.to]=u;
        ancdis[0][v.to]=v.dis;
        dfs(v.to,u);
    }
    out[u]=++dfs_clock;
}
void build()
{
    for(int i=1;(1<<i)<=n;i++)for(int j=1;j<=n;j++)
    {
        anc[i][j]=anc[i-1][anc[i-1][j]];
        ancdis[i][j]=max(ancdis[i-1][j],ancdis[i-1][anc[i-1][j]]);
    }
}
bool ancestor(int x,int y){return in[x]<=in[y] && out[x]>=out[y];}
ll LCA(int x,int y)
{
    if(x==y)return -INF;
    if(ancestor(y,x))swap(x,y);
    ll ans=0;
    for(int i=12;i>=0;i--)
    {
        if(ancestor(anc[i][y],x))continue;
        ans=max(ans,ancdis[i][y]);
        y=anc[i][y];
    }
    ans=max(ans,ancdis[0][y]);
    y=anc[0][y];
    if(x==y)return ans;
    for(int i=12;i>=0;i--)
    {
        if(ancestor(anc[i][x],y))continue;
        ans=max(ans,ancdis[i][x]);
        x=anc[i][x];
    }
    ans=max(ans,ancdis[0][x]);
    return ans;
}
main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)scanf("%d%d%lld",&e[i].u,&e[i].v,&e[i].w);
    sort(e+1,e+m+1);
    ll k=kruskal();
    if(k==-1){puts("-1 -1");return 0;}
    if(m==n-1 && k!=-1){printf("%d -1\n",k);return 0;}
    dfs(1,0);
    out[0]=++dfs_clock;
    build();
    ll ans=INF;
    for(int i=1;i<=m;i++)if(!tr[i])
        ans=min(ans,k+e[i].w-LCA(e[i].u,e[i].v));
    printf("%lld %lld\n",k,ans);
    return 0;
}

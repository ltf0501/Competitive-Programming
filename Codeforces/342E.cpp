#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
vector<int> g[maxn],now;
int n,q;
int anc[20][maxn],p[maxn],dep[maxn];
int in[maxn],out[maxn],dfs_clock;
int sz[maxn],mx[maxn];
bool vis[maxn];
int ans[maxn];
void dfs0(int u,int fa,int d)
{
    in[u]=++dfs_clock;
    anc[0][u]=fa;
    dep[u]=d;
    for(int v : g[u])if(v!=fa)
        dfs0(v,u,d+1);
    out[u]=dfs_clock;
}
void pre()
{
    dfs0(1,0,0);
    for(int j=1;j<=17;j++)
        for(int i=1;i<=n;i++)anc[j][i]=anc[j-1][anc[j-1][i]];
}
bool ancestor(int x,int y){return in[x]<=in[y] && out[x]>=out[y];}
int LCA(int x,int y)
{
    if(ancestor(x,y))return x;
    if(ancestor(y,x))return y;
    for(int i=17;i>=0;i--)if(!ancestor(anc[i][x],y))
        x=anc[i][x];
    return anc[0][x];
}
int dis(int x,int y){return dep[x]+dep[y]-2*dep[LCA(x,y)];}
void get_cen(int u)
{
    vis[u]=1,sz[u]=1,mx[u]=0;
    now.push_back(u);
    for(int v : g[u])if(!vis[v])
    {
        get_cen(v);
        sz[u]+=sz[v];
        mx[u]=max(mx[u],sz[v]);
    }
}
void dfs1(int u,int fa)
{
    get_cen(u);
    int cen=-1;
    int s=now.size();
    for(int w : now)
    {
        if(max(s-sz[w],mx[w])<=s/2)cen=w;
        vis[w]=0;
    }
    now.clear();
    if(cen==-1)return ;
    p[cen]=fa;
    vis[cen]=1;
    for(int v : g[cen])if(!vis[v])
        dfs1(v,cen);
}
void update(int u)
{
    int x=u;
    while(x!=-1)
    {
        //printf("%d\n",x);
        ans[x]=min(ans[x],dis(x,u));
        x=p[x];
    }
}
int query(int u)
{
    int ret=maxn;
    int x=u;
    while(x!=-1)
    {
        //printf("%d\n",x);
        ret=min(ret,dis(x,u)+ans[x]);
        x=p[x];
    }
    return ret;
}
main()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<n;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        g[x].push_back(y),g[y].push_back(x);
    }
    pre();
    dfs1(1,-1);
    //for(int i=1;i<=n;i++)printf("%d: %d\n",i,p[i]);
    for(int i=1;i<=n;i++)ans[i]=maxn;
    update(1);
    while(q--)
    {
        int type,x;scanf("%d%d",&type,&x);
        if(type==1)update(x);
        else printf("%d\n",query(x));
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
#define ll long long
const ll INF=1e14;
vector<int> g[maxn];
int in[maxn],out[maxn],dep[maxn],dfs_clock;
int anc[20][maxn];
int sz[maxn],maxson[maxn],top[maxn];
int n,m,rt;
ll val[maxn];
void dfs1(int u,int fa,int d)
{
    sz[u]=1,dep[u]=d,anc[0][u]=fa;
    int mxer=0;
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(v==fa)continue;
        dfs1(v,u,d+1);
        sz[u]+=sz[v];
        if(sz[v]>sz[mxer])mxer=v;
    }
    maxson[u]=mxer;
}
void dfs2(int u,int tp)
{
    in[u]=++dfs_clock,top[u]=tp;
    if(maxson[u])dfs2(maxson[u],tp);
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(v==anc[0][u] || v==maxson[u])continue;
        dfs2(v,v);
    }
    out[u]=dfs_clock;
}
bool ancestor(int x,int y){return in[x]<=in[y] && out[x]>=out[y];}
int LCA(int x,int y)
{
    if(ancestor(x,y))return x;
    if(ancestor(y,x))return y;
    for(int i=17;i>=0;i--)
        if(!ancestor(anc[i][x],y))x=anc[i][x];
    return anc[0][x];
}
int finds(int x,int l)
{
    for(int i=17;i>=0;i--)
        if(!ancestor(anc[i][x],l))x=anc[i][x];
    return x;
}
ll seg[maxn<<2],tg[maxn<<2];
void push_up(int o){seg[o]=min(seg[o<<1],seg[o<<1|1]);}
void push_down(int o)
{
    if(!tg[o])return ;
    seg[o<<1]=tg[o],seg[o<<1|1]=tg[o];
    tg[o<<1]=tg[o],tg[o<<1|1]=tg[o];
    tg[o]=0;
}
void build(int l,int r,int o)
{
    if(l==r){seg[o]=val[l];return ;}
    int m=(l+r)>>1;
    build(l,m,o<<1),build(m+1,r,o<<1|1);
    push_up(o);
}
void update(int l,int r,int o,int ql,int qr,ll k)
{
    if(ql<=l && r<=qr){seg[o]=k,tg[o]=k;return ;}
    int m=(l+r)>>1;
    push_down(o);
    if(ql<=m)update(l,m,o<<1,ql,qr,k);
    if(qr>m)update(m+1,r,o<<1|1,ql,qr,k);
    push_up(o);
}
ll query(int l,int r,int o,int ql,int qr)
{
    if(ql>qr)return INF;
    if(ql<=l && r<=qr)return seg[o];
    int m=(l+r)>>1;
    push_down(o);
    if(qr<=m)return query(l,m,o<<1,ql,qr);
    if(ql>m)return query(m+1,r,o<<1|1,ql,qr);
    return min(query(l,m,o<<1,ql,qr),query(m+1,r,o<<1|1,ql,qr));
}
void modify(int x,int y,ll k)
{
    while(top[x]!=top[y])
    {
        if(ancestor(top[x],top[y]))swap(x,y);
        update(1,n,1,in[top[x]],in[x],k);
        x=anc[0][top[x]];
    }
    if(in[x]>in[y])swap(x,y);
    update(1,n,1,in[x],in[y],k);
}
main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<n;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        g[x].push_back(y),g[y].push_back(x);
    }
    dfs1(1,0,0);
    dfs2(1,1);
    out[0]=dfs_clock;
    for(int j=1;j<=17;j++)
        for(int i=1;i<=n;i++)anc[j][i]=anc[j-1][anc[j-1][i]];
    //for(int i=1;i<=n;i++)printf("%d ",in[i]);puts("");
    for(int i=1;i<=n;i++)scanf("%lld",&val[in[i]]);
    build(1,n,1);
    scanf("%d",&rt);
    while(m--)
    {
        int type;scanf("%d",&type);
        if(type!=2)
        {
            int x;scanf("%d",&x);
            if(type==1)rt=x;
            else
            {
                if(x==rt){printf("%lld\n",seg[1]);continue;}
                int l=LCA(x,rt);
                if(l!=x)printf("%lld\n",query(1,n,1,in[x],out[x]));
                else
                {
                    x=finds(rt,x);
                    printf("%lld\n",min(query(1,n,1,1,in[x]-1),query(1,n,1,out[x]+1,n)));
                }
            }
        }
        else
        {
            int x,y;ll k;
            scanf("%d%d%lld",&x,&y,&k);
            modify(x,y,k);
        }
    }
    return 0;
}

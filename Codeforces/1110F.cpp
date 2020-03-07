#include<bits/stdc++.h>
using namespace std;
#define maxn 500010
#define ll long long
#define pii pair<int,int>
#define F first
#define S second
const ll INF=1e16;
vector<pii> g[maxn];
int n,q;
bool is_leaf[maxn];
ll seg[maxn<<2],tg[maxn<<2];
bool not_leaf[maxn];
ll dis[maxn];
struct Q
{
    int id,l,r;
};
vector<Q> que[maxn];
ll ans[maxn];
void push_down(int o)
{
    if(!tg[o])return ;
    seg[o<<1]+=tg[o],seg[o<<1|1]+=tg[o];
    tg[o<<1]+=tg[o],tg[o<<1|1]+=tg[o];
    tg[o]=0;
}
void push_up(int o){seg[o]=min(seg[o<<1],seg[o<<1|1]);}
void build(int l,int r,int o)
{
    if(l==r){seg[o]=dis[l];return ;}
    int m=(l+r)>>1;
    build(l,m,o<<1),build(m+1,r,o<<1|1);
    push_up(o);
}
void update(int l,int r,int o,int ql,int qr,ll k)
{
    if(ql>r || qr<l)return ;
    if(ql<=l && r<=qr){seg[o]+=k,tg[o]+=k;return ;}
    push_down(o);
    int m=(l+r)>>1;
    if(ql<=m)update(l,m,o<<1,ql,qr,k);
    if(qr>m)update(m+1,r,o<<1|1,ql,qr,k);
    push_up(o);
}
ll query(int l,int r,int o,int ql,int qr)
{
    if(ql<=l && r<=qr)return seg[o];
    push_down(o);
    int m=(l+r)>>1;
    if(qr<=m)return query(l,m,o<<1,ql,qr);
    if(ql>m)return query(m+1,r,o<<1|1,ql,qr);
    return min(query(l,m,o<<1,ql,qr),query(m+1,r,o<<1|1,ql,qr));
}
int out[maxn],dfs_clock;
void pre_dfs(int u,int fa)
{
    ++dfs_clock;
    for(pii v : g[u])
        if(v.F!=fa)pre_dfs(v.F,u);
    out[u]=dfs_clock;
}
void dfs(int u,int fa)
{
    for(Q& s : que[u])
    {
        int id=s.id,l=s.l,r=s.r;
        ans[id]=query(1,n,1,l,r);
    }
    for(pii v : g[u])
    {
        update(1,n,1,v.F,out[v.F],-v.S);
        update(1,n,1,1,v.F-1,v.S);
        update(1,n,1,out[v.F]+1,n,v.S);
        dfs(v.F,u);
        update(1,n,1,v.F,out[v.F],v.S);
        update(1,n,1,1,v.F-1,-v.S);
        update(1,n,1,out[v.F]+1,n,-v.S);
    }
}
main()
{
    scanf("%d%d",&n,&q);
    for(int i=2;i<=n;i++)
    {
        int p,w;scanf("%d%d",&p,&w);
        not_leaf[p]=1;
        dis[i]=dis[p]+w;
        g[p].push_back(pii(i,w));
    }
    for(int i=1;i<=n;i++)
        if(not_leaf[i])dis[i]=INF;
    //for(int i=1;i<=n;i++)printf("%lld ",dis[i]);puts("");
    build(1,n,1);
    for(int i=1;i<=q;i++)
    {
        int x,l,r;scanf("%d%d%d",&x,&l,&r);
        que[x].push_back({i,l,r});
    }
    pre_dfs(1,0);
    dfs(1,0);
    for(int i=1;i<=q;i++)printf("%lld\n",ans[i]);
    return 0;
}

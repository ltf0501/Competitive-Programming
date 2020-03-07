#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
#define pii pair<int,int>
#define F first
#define S second
const int INF=1e9+5;
vector<int> g[maxn];
int n,r;
int a[maxn],b[maxn];
int in[maxn],out[maxn],dep[maxn],dfs_clock=0;
vector<pii> seg[maxn<<2];
vector<int> pp[maxn<<2];
void dfs(int u,int fa,int d)
{
    in[u]=++dfs_clock;
    b[dfs_clock]=u;
    dep[u]=d;
    for(int v : g[u])if(v!=fa)
        dfs(v,u,d+1);
    out[u]=dfs_clock;
}
void build(int l,int r,int o)
{
    if(l==r)
    {
        pp[o].push_back(INF);
        pp[o].push_back(a[b[l]]);
        seg[o].push_back(pii(dep[b[l]],a[b[l]]));
        return ;
    }
    int m=(l+r)>>1;
    build(l,m,o<<1),build(m+1,r,o<<1|1);
    for(auto s : seg[o<<1])seg[o].push_back(s);
    for(auto s : seg[o<<1|1])seg[o].push_back(s);
    sort(seg[o].begin(),seg[o].end());
    pp[o].push_back(INF);
    for(auto s : seg[o])pp[o].push_back(min(s.S,pp[o].back()));
}
int query(int l,int r,int o,int ql,int qr,int v)
{
    if(ql<=l && r<=qr)
    {
        int k=upper_bound(seg[o].begin(),seg[o].end(),pii(v,INF))-seg[o].begin();
        return pp[o][k];
    }
    int ret=INF;
    int m=(l+r)>>1;
    if(ql<=m)ret=min(ret,query(l,m,o<<1,ql,qr,v));
    if(qr>m)ret=min(ret,query(m+1,r,o<<1|1,ql,qr,v));
    return ret;
}
main()
{
    scanf("%d%d",&n,&r);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<n;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        g[x].push_back(y),g[y].push_back(x);
    }
    dfs(r,0,0);
    build(1,n,1);
    int q;scanf("%d",&q);
    int ans=0;
    while(q--)
    {
        int p,q;scanf("%d%d",&p,&q);
        int x=(ans+p)%n+1,k=(ans+q)%n;
        ans=query(1,n,1,in[x],out[x],k+dep[x]);
        printf("%d\n",ans);
    }
    return 0;
}

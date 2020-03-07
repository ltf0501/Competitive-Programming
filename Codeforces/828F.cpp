#include<bits/stdc++.h>
using namespace std;
const int INF=1e9+7;
#define maxn 200010
#define pii pair<int,int>
#define F first
#define S second
struct E
{
    int u,v,d,id;
    bool operator < (const E& rhs)const{return d<rhs.d;}
};
struct EE
{
    int to,d,id;
};
vector<E> e;
vector<EE> g[maxn];
bool inMST[maxn];
int n,m;
int ans[maxn];
int p[maxn],sz[maxn];
int finds(int x){return p[x]==x ? x : p[x]=finds(p[x]);}
bool Union(int x,int y)
{
    int a=finds(x),b=finds(y);
    if(a==b)return 0;
    if(sz[a]<sz[b])swap(a,b);
    sz[a]+=sz[b],p[b]=a;
    return 1;
}
int in[maxn],out[maxn],dfs_clock,up[maxn];
int anc[20][maxn],anc_max[20][maxn];
void dfs(int u,int fa)
{
    in[u]=++dfs_clock;
    for(EE v : g[u])if(v.to!=fa)
        dfs(v.to,u),anc[0][v.to]=u,anc_max[0][v.to]=v.d,up[v.to]=v.id;
    out[u]=dfs_clock;
}
void pre()
{
    for(int j=1;j<=17;j++)
        for(int i=1;i<=n;i++)
            anc[j][i]=anc[j-1][anc[j-1][i]],
            anc_max[j][i]=max(anc_max[j-1][i],anc_max[j-1][anc[j-1][i]]);
}
#define pii pair<int,int>
#define F first
#define S second
bool ancestor(int x,int y){return in[x]<=in[y] && out[x]>=out[y];}
pii LCA(int x,int y)
{
    int ret=0;
    if(ancestor(x,y))swap(x,y);
    for(int i=17;i>=0;i--)if(!ancestor(anc[i][x],y))
        ret=max(ret,anc_max[i][x]),x=anc[i][x];
    ret=max(ret,anc_max[0][x]),x=anc[0][x];
    if(x==y)return pii(x,ret);
    for(int i=17;i>=0;i--)if(!ancestor(anc[i][y],x))
        ret=max(ret,anc_max[i][y]),y=anc[i][y];
    ret=max(ret,anc_max[0][y]),y=anc[0][y];
    return pii(x,ret);
}
void update(int x,int l,int w)
{
    x=finds(x);
    while(!ancestor(x,l))
    {
        int fa=anc[0][x],id=up[x];
        ans[id]=min(ans[id],w);
        p[x]=finds(fa);
        x=finds(x);
    }
}
main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int x,y,d;scanf("%d%d%d",&x,&y,&d);
        e.push_back({x,y,d,i});
    }
    sort(e.begin(),e.end());
    for(int i=1;i<=n;i++)p[i]=i,sz[i]=1;
    for(E ee : e)
    {
        int x=ee.u,y=ee.v,d=ee.d,id=ee.id;
        if(Union(x,y))
        {
            g[x].push_back({y,d,id});
            g[y].push_back({x,d,id});
            inMST[id]=1;
        }
    }
    dfs(1,0);out[0]=dfs_clock;
    pre();
    for(int i=1;i<=n;i++)p[i]=i;
    for(int i=1;i<=m;i++)ans[i]=INF;
    for(E ee : e)
    {
        if(inMST[ee.id])continue;
        int x=ee.u,y=ee.v,d=ee.d,id=ee.id;
        pii l=LCA(x,y);
        ans[id]=min(ans[id],l.S-1);
        update(x,l.F,d-1),update(y,l.F,d-1);
    }
    for(int i=1;i<=m;i++)
        printf("%d ",ans[i]==INF ? -1 : ans[i]);
    return 0;
}

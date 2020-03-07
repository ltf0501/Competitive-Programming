#include<bits/stdc++.h>
using namespace std;
#define maxn 500010
#define ll long long
#define pii pair<int,int>
#define F first
#define S second
struct E
{
    int x,y;
    ll d;
    bool operator < (const E& b)const{return d<b.d;}
};
vector<pii> g[maxn];
vector<E> edge,umr;
bool is[maxn];
int p[maxn],sz[maxn];
int finds(int x){return p[x]==x ? x : p[x]=finds(p[x]);}
bool Union(int x,int y)
{
    int a=finds(x),b=finds(y);
    if(a==b)return 0;
    if(sz[a]<=sz[b])swap(a,b);
    sz[a]+=sz[b],p[b]=a;
    return 1;
}
int n,k,m;
int in[maxn],out[maxn],dfs_clock;
int anc[20][maxn];
void dfs(int u,int fa)
{
    in[u]=++dfs_clock,anc[0][u]=fa;
    for(pii v : g[u])if(v.F!=fa)
    {
         dfs(v.F,u);
         if(!v.S)is[v.F]=1;
    }
    out[u]=dfs_clock;
}
void pre()
{
    dfs(1,0);
    out[0]=dfs_clock;
    for(int j=1;j<=19;j++)
        for(int i=1;i<=n;i++)anc[j][i]=anc[j-1][anc[j-1][i]];
}
bool ancestor(int x,int y){return in[x]<=in[y] && out[x]>=out[y];}
int LCA(int x,int y)
{
    if(ancestor(x,y))return x;
    if(ancestor(y,x))return y;
    for(int i=19;i>=0;i--)if(!ancestor(anc[i][x],y))
        x=anc[i][x];
    return anc[0][x];
}
int ans[maxn];
int gao(int u,int x,int d)
{
    if(u!=p[u])return p[u]=gao(p[u],x,d);
    if(ancestor(u,x))return u;
    else
    {
        ans[u]=d;
        return p[u]=gao(anc[0][u],x,d);
    }
}
main()
{
    scanf("%d%d%d",&n,&k,&m);
    for(int i=1;i<=k;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        edge.push_back({x,y,0});
    }
    for(int i=1;i<=m;i++)
    {
        int x,y,d;scanf("%d%d%d",&x,&y,&d);
        edge.push_back({x,y,d});
    }
    sort(edge.begin(),edge.end());
    for(int i=1;i<=n;i++)p[i]=i,sz[i]=1;
    for(E e : edge)
    {
        int x=e.x,y=e.y,d=e.d;
        if(Union(x,y))
            g[x].push_back(pii(y,d)),g[y].push_back(pii(x,d));
        else umr.push_back(e);
    }
    pre();
    for(int i=1;i<=n;i++)p[i]=i;
    //for(E e : umr)printf("%d %d %d\n",e.x,e.y,e.d);
    //puts("");
    for(E e : umr)
    {
        int x=e.x,y=e.y,d=e.d;
        int u=LCA(x,y);
        //printf("%d %d %d\n",x,y,u);
        gao(x,u,d),gao(y,u,d);
    }
    ll sum=0;
    for(int i=2;i<=n;i++)if(is[i])
    {
        if(!ans[i])return 0*puts("-1");
        sum+=ans[i];
    }
    printf("%lld\n",sum);
    return 0;
}

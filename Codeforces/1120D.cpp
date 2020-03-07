#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
#define ll long long
#define pii pair<int,int>
#define F first
#define S second
struct E
{
    int u,v,d,id;
    bool operator < (const E& rhs)const{return d<rhs.d;}
};
vector<E> edge;
vector<int> g[maxn];
vector<pii> g2[maxn];
int n,L;
int cost[maxn];
int in[maxn],out[maxn],dfs_clock;
bool ok[maxn];
vector<int> leaf;
void dfs(int u,int fa)
{
    in[u]=++dfs_clock;
    if(u!=1 && g[u].size()==1)leaf.push_back(in[u]);
    for(int v : g[u])if(v!=fa)
        dfs(v,u);
    out[u]=dfs_clock;
}
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
int h[maxn],anc[20][maxn];
int anc_max[20][maxn];
void pre_dfs(int u,int fa)
{
    for(pii v : g2[u])if(v.F!=fa)
    {
        anc[0][v.F]=u;
        anc_max[0][v.F]=v.S;
        h[v.F]=h[u]+1;
        pre_dfs(v.F,u);
    }
}
void pre()
{
    memset(anc,-1,sizeof(anc));
    memset(anc_max,-1,sizeof(anc_max));
    pre_dfs(0,-1);
    for(int j=1;j<=18;j++)
        for(int i=0;i<L;i++)if(anc[j-1][i]!=-1)
        {anc[j][i]=anc[j-1][anc[j-1][i]],
            anc_max[j][i]=max(anc_max[j-1][i],anc_max[j-1][anc[j-1][i]]);}
}
int find_max(int u,int v)
{
    int res=0;
    if(h[u]<h[v])swap(u,v);
    for(int i=18;i>=0;i--)if(h[u]-(1<<i)>=h[v])
        res=max(res,anc_max[i][u]),u=anc[i][u];
    if(u==v)return res;
    for(int i=18;i>=0;i--)if(anc[i][u]!=anc[i][v])
        res=max(res,max(anc_max[i][u],anc_max[i][v])),u=anc[i][u],v=anc[i][v];
    res=max(res,max(anc_max[0][u],anc_max[0][v]));
    return res;
}
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&cost[i]);
    for(int i=1;i<n;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        g[x].push_back(y),g[y].push_back(x);
    }
    leaf.push_back(0);
    dfs(1,0);L=(int)leaf.size();
    //for(int x : leaf)printf("%d ",x);puts("");
    for(int i=1;i<=n;i++)
    {
        int l=lower_bound(leaf.begin(),leaf.end(),in[i])-leaf.begin();
        int r=upper_bound(leaf.begin(),leaf.end(),out[i])-leaf.begin();
        edge.push_back({l-1,r-1,cost[i],i});
    }
    //for(E e : edge)printf("%d %d %d %d\n",e.u,e.v,e.d,e.id);
    sort(edge.begin(),edge.end());
    for(int i=0;i<L;i++)p[i]=i,sz[i]=1;
    int cnt=0;
    ll ans=0;
    for(E e : edge)
    {
        int u=e.u,v=e.v,d=e.d;
        if(Union(u,v))
        {
            g2[u].push_back(pii(v,d)),g2[v].push_back(pii(u,d));
            ok[e.id]=1,ans+=e.d,cnt++;
        }
        if(cnt==L-1)break;
    }
    //printf("%d\n",L);
    /*
    for(int i=0;i<L;i++)
    {
        printf("%d: ",i);
        for(pii j : g2[i])printf("%d %d\n",j.F,j.S);
    }
    */
    pre();
    for(E e : edge)if(!ok[e.id])
    {
        if(find_max(e.u,e.v)==e.d)ok[e.id]=1;
        //printf("%d %d %d: %d, %d\n",e.u,e.v,k,e.d,e.id);
    }
    cnt=0;
    for(int i=1;i<=n;i++)if(ok[i])cnt++;
    printf("%lld %d\n",ans,cnt);
    for(int i=1;i<=n;i++)if(ok[i])printf("%d ",i);puts("");
    return 0;
}

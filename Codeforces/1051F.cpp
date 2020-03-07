#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
#define ll long long
#define pii pair<int,int>
#define F first
#define S second
int n,m;
vector<pii> g[maxn],g2[maxn];
vector<int> umr;
bool is[maxn];
int p[maxn],sz[maxn];
ll d[maxn][45],d2[45][45],dep[maxn];
int finds(int x){return p[x]==x ? x : p[x]=finds(p[x]);}
int in[maxn],out[maxn],dfs_clock;
int anc[20][maxn];
bool Union(int x,int y)
{
    int a=finds(x),b=finds(y);
    if(a==b)return 0;
    if(sz[a]<sz[b])swap(a,b);
    sz[a]+=sz[b],p[b]=a;
    return 1;
}
void dfs(int u,int fa)
{
    in[u]=++dfs_clock;
    for(pii v : g[u])if(v.F!=fa)
        dep[v.F]=dep[u]+v.S,dfs(v.F,u),anc[0][v.F]=u;
    out[u]=dfs_clock;
}
void pre()
{
    dfs(1,0);out[0]=dfs_clock;
    for(int j=1;j<=17;j++)
        for(int i=1;i<=n;i++)anc[j][i]=anc[j-1][anc[j-1][i]];
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
ll dis(int x,int y){return dep[x]+dep[y]-2*dep[LCA(x,y)];}
main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)p[i]=i,sz[i]=1;
    for(int i=1;i<=m;i++)
    {
        int x,y,d;scanf("%d%d%d",&x,&y,&d);
        if(Union(x,y))g[x].push_back(pii(y,d)),g[y].push_back(pii(x,d));
        else g2[x].push_back(pii(y,d)),g2[y].push_back(pii(x,d)),is[x]=1,is[y]=1;
    }
    for(int i=1;i<=n;i++)if(is[i])umr.push_back(i);
    pre();
    int s=umr.size();
    for(int i=1;i<=n;i++)
        for(int j=0;j<s;j++)d[i][j]=dis(i,umr[j]);
    for(int i=0;i<s;i++)
    {
        for(int j=0;j<s;j++)d2[i][j]=d[umr[i]][j];
        for(pii v : g2[umr[i]])
        {
            int k=lower_bound(umr.begin(),umr.end(),v.F)-umr.begin();
            d2[i][k]=min(d2[i][k],1ll*v.S);
        }
    }
    for(int k=0;k<s;k++)for(int i=0;i<s;i++)for(int j=0;j<s;j++)
        d2[i][j]=min(d2[i][j],d2[i][k]+d2[k][j]);
    int q;scanf("%d",&q);
    while(q--)
    {
        int x,y;scanf("%d%d",&x,&y);
        ll ans=dis(x,y);
        for(int i=0;i<s;i++)for(int j=0;j<s;j++)
            ans=min(ans,d[x][i]+d2[i][j]+d[y][j]);
        printf("%lld\n",ans);
    }
    return 0;
}

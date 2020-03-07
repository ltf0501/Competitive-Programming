#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
#define ll long long
const int mod=1e9+7;
ll val[maxn];
int sz[maxn],odd1[maxn],odd2[maxn];
int n;
vector<int> g[maxn];
ll ans;
void add(ll &a,ll b)
{
    b%=mod;
    a+=b;
    if(a>=mod)a-=mod;
}
void sub(ll &a,ll b)
{
    b%=mod;
    a-=b;
    if(a<0)a+=mod;
}
void dfs1(int u,int fa)
{
    sz[u]=1;
    for(int v : g[u])if(v!=fa)
    {
        dfs1(v,u);
        add(ans,1ll*2*(sz[u]-odd1[u])%mod*odd1[v]%mod*val[u]%mod);
        sub(ans,1ll*2*odd1[u]%mod*(sz[v]-odd1[v])%mod*val[u]%mod);
        sz[u]+=sz[v];
        odd1[u]+=(sz[v]-odd1[v]);
    }
}
void dfs2(int u,int fa)
{
    if(u!=1)
    {
        odd2[u]=((sz[fa]-odd1[fa])-odd1[u])+((n-sz[fa])-odd2[fa]);
    }
    for(int v : g[u])if(v!=fa)
        dfs2(v,u);
}
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%lld",&val[i]);
    for(int i=1;i<n;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        g[x].push_back(y),g[y].push_back(x);
    }
    dfs1(1,-1);
    dfs2(1,-1);
    //for(int i=1;i<=n;i++)printf("%d ",odd1[i]);puts("");
    //for(int i=1;i<=n;i++)printf("%d ",odd2[i]);puts("");
    for(int i=1;i<=n;i++)
    {
        add(ans,1ll*2*(sz[i]-odd1[i])*(n-sz[i]-odd2[i])%mod*val[i]%mod);
        sub(ans,1ll*2*odd1[i]*odd2[i]%mod*val[i]%mod);
    }
    for(int i=1;i<=n;i++)add(ans,val[i]);
    printf("%lld\n",ans);
    return 0;
}
/*
4
-4 1 5 -2
1 2
1 3
1 4
*/

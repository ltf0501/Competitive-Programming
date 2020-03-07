#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
#define ll long long
struct P{int u,v,w;};
vector<P> v;
vector<int> g[maxn];
int n,d[maxn],fa[maxn],t[maxn];
int mxer,mx,s;
ll ans=0;
void dfs1(int u,int p,int dep)
{
    d[u]=dep;
    fa[u]=p;
    for(int v : g[u])if(v!=p)
        dfs1(v,u,dep+1);
}
void dfs2(int u,int p,int k,int tt)
{
    for(int v : g[u])if(v!=p)
    {
        if(t[v])dfs2(v,u,v,t[v]);
        else dfs2(v,u,k,tt);
    }
    if(t[u])return ;
    if(tt==1)
    {
        ans+=d[u];
        v.push_back({u,s,u});
    }
    else
    {
        ans+=d[mxer]+d[u]-2*d[k];
        v.push_back({u,mxer,u});
    }
}
main()
{
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        g[x].push_back(y),g[y].push_back(x);
    }
    dfs1(1,0,0);
    for(int i=1;i<=n;i++)if(mx<d[i])mx=d[i],mxer=i;
    dfs1(mxer,0,0);
    s=mxer,mx=0;
    for(int i=1;i<=n;i++)if(mx<d[i])mx=d[i],mxer=i;
    ///printf("%d %d\n",s,mxer);
    int x=mxer;
    while(x)
    {
        if(d[x]>mx/2)t[x]=1;///§äs
        else t[x]=2;///§ämxer
        x=fa[x];
    }
    dfs2(s,0,s,t[s]);
    x=mxer;
    while(x!=s)
    {
        ans+=d[x];
        v.push_back({x,s,x});
        x=fa[x];
    }
    printf("%I64d\n",ans);
    for(auto z : v)printf("%d %d %d\n",z.u,z.v,z.w);
    return 0;
}

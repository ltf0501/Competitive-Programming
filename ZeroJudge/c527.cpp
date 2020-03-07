#include<bits/stdc++.h>
using namespace std;
#define maxn 500010
#define ll long long
#define pii pair<int,int>
#define F first
#define S second
vector<pii> g[maxn];
bool col[maxn];
ll dp1[maxn],dp2[maxn],dp3[maxn],dp4[maxn];
ll mx[maxn],secmx[maxn];
int sz[maxn];
void dfs1(int u,int fa)
{
    for(pii v : g[u])
        if(v.F!=fa)dfs1(v.F,u);
    sz[u]=col[u];
    for(pii v : g[u])if(v.F!=fa)
    {
        sz[u]+=sz[v.F];
        if(sz[v.F])
        {
            dp2[u]+=dp2[v.F]+2*v.S;
            ll t=dp2[v.F]-dp1[v.F]+v.S;
            if(t>=mx[u])secmx[u]=mx[u],mx[u]=t;
            else if(t>secmx[u])secmx[u]=t;
        }
    }
    for(pii v : g[u])if(v.F!=fa)
        dp1[u]=dp2[u]-mx[u];
}
void dfs2(int u,int fa,int d)
{
    if(fa && sz[1]!=sz[u])
    {
        dp4[u]=2*d+dp4[fa]+dp2[fa]-(sz[u] ? 2*d : 0)-dp2[u];
        ll t1=dp2[fa]-(sz[u] ? 2*d : 0)-dp2[u]+dp3[fa];
        ll t2=dp4[fa]+dp2[fa]-(sz[u] ? 2*d : 0)-dp2[u]-(dp2[u]-dp1[u]+d==mx[fa] ? secmx[fa] : mx[fa]);
        dp3[u]=d+min(t1,t2);
    }
    for(pii v : g[u])
        if(v.F!=fa)dfs2(v.F,u,v.S);
}
main()
{
    int n;scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int x,y,d;scanf("%d%d%d",&x,&y,&d);
        g[x].push_back(pii(y,d)),g[y].push_back(pii(x,d));
    }
    for(int i=1;i<=n;i++)scanf("%d",&col[i]);
    dfs1(1,0);
    dfs2(1,0,0);
    //for(int i=1;i<=n;i++)printf("%lld %lld %lld %lld\n",dp1[i],dp2[i],dp3[i],dp4[i]);
    for(int i=1;i<=n;i++)
        if(!col[i])printf("%lld\n",min(dp2[i]+dp3[i],dp4[i]+dp1[i]));
    return 0;
}
/*
7
1 2 1
2 3 1
1 4 1
4 5 1
4 6 1
6 7 1
1 0 1 0 1 0 1
*/

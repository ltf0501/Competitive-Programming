#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 300010
#define pii pair<int,int>
#define F first
#define S second
vector<int> g[maxn];
int n,m;
vector<pii> vv[maxn];
ll ans[maxn],dp[maxn];
int dep[maxn];
void dfs(int u,int fa,ll cur)
{
    cur-=dp[dep[u]];
    for(pii tmp : vv[u])
    {
        cur+=tmp.S;
        int id=min(maxn-1,dep[u]+tmp.F+1);
        dp[id]+=tmp.S;
    }
    ans[u]=cur;
    for(int v : g[u])if(v!=fa)
        dep[v]=dep[u]+1,dfs(v,u,cur);
    for(pii tmp : vv[u])
    {
        int id=min(n-1,dep[u]+tmp.F+1);
        dp[id]-=tmp.S;
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
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        int u,d,val;scanf("%d%d%d",&u,&d,&val);
        vv[u].push_back(pii(d,val));
    }
    dfs(1,0,0);
    for(int i=1;i<=n;i++)printf("%lld ",ans[i]);
    return 0;
}

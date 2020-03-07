#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
#define ll long long
int n,col[maxn];
vector<int> g[maxn];
int sz[maxn],son[maxn],cnt[maxn];
ll sum,mx,ans[maxn];
void dfs0(int u,int fa)
{
    sz[u]=1;
    for(int v : g[u])if(v!=fa)
    {
        dfs0(v,u);
        sz[u]+=sz[v];
        if(sz[v]>sz[son[u]])son[u]=v;
    }
}
void cal(int u,int fa,int val,int Son)
{
    cnt[col[u]]+=val;
    if(cnt[col[u]]>mx)mx=cnt[col[u]],sum=col[u];
    else if(cnt[col[u]]==mx)sum+=col[u];
    for(int v : g[u])
        if(v!=fa && v!=Son)cal(v,u,val,Son);
}
void dfs(int u,int fa,int k)
{
    for(int v : g[u])
        if(v!=fa && v!=son[u])dfs(v,u,0);
    if(son[u])dfs(son[u],u,1);
    cal(u,fa,1,son[u]);
    ans[u]=sum;
    if(!k)cal(u,fa,-1,0),mx=sum=0;
}
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&col[i]);
    for(int i=1;i<n;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        g[x].push_back(y),g[y].push_back(x);
    }
    dfs0(1,-1);
    dfs(1,-1,0);
    for(int i=1;i<=n;i++)printf("%lld ",ans[i]);
    return 0;
}

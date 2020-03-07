#include<bits/stdc++.h>
using namespace std;
#define maxn 500010
#define pii pair<int,int>
#define F first
#define S second
vector<int> g[maxn];
int n,q;
char c[maxn];
int num[maxn];
bool cnt[maxn][26],ans[maxn];
vector<pii> ask[maxn];
int sz[maxn],son[maxn],dep[maxn];
void dfs0(int u)
{
    sz[u]=1;
    for(int v : g[u])
    {
        dep[v]=dep[u]+1;
        dfs0(v);
        sz[u]+=sz[v];
        if(sz[v]>sz[son[u]])son[u]=v;
    }
}
void cal(int u,int x,int Son)
{
    num[dep[u]]-=cnt[dep[u]][c[u]-'a'];
    cnt[dep[u]][c[u]-'a']^=1;
    num[dep[u]]+=cnt[dep[u]][c[u]-'a'];
    for(int v : g[u])
        if(v!=Son)cal(v,x,Son);
}
void dfs(int u,int k)
{
    for(int v : g[u])
        if(v!=son[u])dfs(v,0);
    if(son[u])dfs(son[u],1);
    cal(u,1,son[u]);
    for(pii s : ask[u])
        ans[s.S]=num[s.F]<=1;
    if(!k)cal(u,-1,0);
}
main()
{
    scanf("%d%d",&n,&q);
    for(int i=2;i<=n;i++)
    {
        int p;scanf("%d",&p);
        g[p].push_back(i);
    }
    scanf("%s",c+1);
    for(int i=1;i<=q;i++)
    {
        int v,h;scanf("%d%d",&v,&h);
        ask[v].push_back(pii(h-1,i));
    }
    dfs0(1);
    //for(int i=1;i<=n;i++)printf("%d ",dep[i]);puts("");
    dfs(1,0);
    for(int i=1;i<=q;i++)puts(ans[i] ? "Yes" : "No");
    return 0;
}

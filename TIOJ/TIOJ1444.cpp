#include<bits/stdc++.h>
using namespace std;
#define maxn 5050
vector<int> g[maxn],ans,id;
int n,m;
int dp1[maxn],dp2[maxn],dp1n[maxn],dp2n[maxn];
void update(int p,int v,int x)
{
    if(dp1[p]<v)
    {
        dp2[p]=dp1[p],dp1[p]=v;
        dp2n[p]=dp1n[p],dp1n[p]=x;
    }
    else if(dp2[p]<v)dp2[p]=v,dp2n[p]=x;
}
void dfs1(int u,int f)
{
    dp1[u]=dp2[u]=0,dp1n[u]=dp2n[u]=-1;
    for(int v : g[u])
    {
        if(v==f)continue;
        dfs1(v,u);
        update(u,dp1[v]+1,v);
    }
}
void dfs2(int u,int f)
{
    if(f!=-1)
    {
        if(dp1n[f]==u)update(u,dp2[f]+1,f);
        else update(u,dp1[f]+1,f);
    }
    for(int v : g[u])
    {
        if(v==f)continue;
        dfs2(v,u);
    }
}
main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n-1;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        g[x].push_back(y),g[y].push_back(x);
    }
    dfs1(1,-1);
    dfs2(1,-1);
    //for(int i=1;i<=n;i++)printf("%d ",dp1[i]);puts("");
    int mi=1000000000,mx=-1;
    for(int i=1;i<=n;i++)
    {
        int d=dp1[i];
        if(d>mx){id.clear(),id.push_back(i),mx=d;}
        else if(d==mx)id.push_back(i);
        if(d<mi){ans.clear(),ans.push_back(i),mi=d;}
        else if(d==mi)ans.push_back(i);
    }
    for(int s : ans)printf("%d ",s);puts("");
    for(int s : id)printf("%d ",s);puts("");
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define maxn 50010
#define ll long long
vector<int> g[maxn],now,dis;
int n,k;
int sz[maxn],mx[maxn],d[maxn];
bool vis[maxn];
void get_cen(int u)
{
    sz[u]=1,vis[u]=1,mx[u]=0;
    now.push_back(u);
    for(int v : g[u])if(!vis[v])
    {
        get_cen(v);
        sz[u]+=sz[v];
        mx[u]=max(mx[u],sz[v]);
    }
}
void get_dis(int u,int fa)
{
    dis.push_back(d[u]);
    for(int v : g[u])if(v!=fa && !vis[v])
    {
        d[v]=d[u]+1;
        get_dis(v,u);
    }
}
ll cal(int u,int val)
{
    dis.clear(),d[u]=val;
    get_dis(u,-1);
    ll ret=0;
    sort(dis.begin(),dis.end());
    int m=dis.size();
    for(int l=0,r=m-1;l<r;)
    {
        if(dis[l]+dis[r]<=k)ret+=r-l++;
        else r--;
    }
    for(int l=0,r=m-1;l<r;)
    {
        if(dis[l]+dis[r]<=k-1)ret-=r-l++;
        else r--;
    }
    return ret;
}
ll dfs(int u)
{
    get_cen(u);
    int cen=-1;
    int s=now.size();
    for(int w : now)
    {
        if(max(mx[w],s-sz[w])<=s/2)cen=w;
        vis[w]=0;
    }
    now.clear();
    ll ret=0;
    ret+=cal(cen,0);
    vis[cen]=1;
    for(int v : g[cen])
        if(!vis[v])ret-=cal(v,1),ret+=dfs(v)
    return ret;
}
main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<n;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        g[x].push_back(y),g[y].push_back(x);
    }
    printf("%lld\n",dfs(1));
    return 0;
}

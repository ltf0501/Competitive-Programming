#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
#define maxn 10010
int sz[maxn],mx[maxn],d[maxn];
int n,k;
struct edge
{
    int to,d;
    edge(int to,int d):to(to),d(d){}
};
vector<edge> g[maxn];
bool vis[maxn];
vector<int> now;
void get_cen(int u)
{
    vis[u]=1;
    sz[u]=1;
    mx[u]=0;
    now.push_back(u);
    for(int i=0;i<g[u].size();i++)
    {
        edge v=g[u][i];
        if(!vis[v.to])
        {
            get_cen(v.to);
            sz[u]+=sz[v.to];
            mx[u]=max(mx[u],sz[v.to]);
        }
    }
}
vector<int> dis;
void get_dis(int u,int fa)
{
    dis.push_back(d[u]);
    for(int i=0;i<g[u].size();i++)
    {
        edge v=g[u][i];
        if(v.to!=fa && !vis[v.to])
        {
            d[v.to]=d[u]+v.d;
            get_dis(v.to,u);
        }
    }
}
int cal(int u,int val)
{
    dis.clear();d[u]=val;
    get_dis(u,0);
    int ret=0;
    sort(dis.begin(),dis.end());
    for(int l=0,r=dis.size()-1;l<r;)
    {
        if(dis[l]+dis[r]<=k)ret+=r-l++;
        else r--;
    }
    return ret;
}
int dfs(int u)
{
    get_cen(u);
    int s=now.size();
    int tmp=-1;//cen
    for(int i=0;i<now.size();i++)
    {
        int v=now[i];
        if(max(mx[v],s-sz[v])<=s/2)tmp=v;
        vis[v]=0;
    }
    now.clear();
    int ret=0;
    ret+=cal(tmp,0);
    vis[tmp]=1;
    for(int i=0;i<g[tmp].size();i++)
    {
        edge v=g[tmp][i];
        if(!vis[v.to])
        {
            ret-=cal(v.to,v.d);
            ret+=dfs(v.to);
        }
    }
    return ret;
}
void init()
{
    for(int i=1;i<=n;i++)g[i].clear();
    memset(vis,0,sizeof(vis));
    memset(sz,0,sizeof(sz));
    memset(mx,0,sizeof(mx));
}
int main()
{
    while(~scanf("%d%d",&n,&k) && n+k)
    {
        init();
        for(int i=1;i<n;i++)
        {
            int x,y,d;scanf("%d%d%d",&x,&y,&d);
            g[x].push_back(edge(y,d)),g[y].push_back(edge(x,d));
        }
        printf("%d\n",dfs(1));
        //for(int i=1;i<=n;i++)printf("%d ",dp[i]);puts("");
    }
    return 0;
}


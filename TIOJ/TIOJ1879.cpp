#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
#define maxn 10000+10
#define pii pair<int,int>
#define mkp make_pair
#define F first
#define S second
vector<pii> g[maxn];
vector<int> s[maxn];
bool vis[maxn],b[4*maxn];
int pre[maxn],dfs_clock=0;
int dfs(int u,int fa)
{
    int lowu=pre[u]=++dfs_clock;
    int ch=0;
    for(int i=0;i<g[u].size();i++)
    {
        pii v=g[u][i];
        if(!pre[v.S])
        {
            ch++;
            int lowv=dfs(v.S,u);
            lowu=min(lowu,lowv);
            if(lowv>pre[u])b[v.F]=1;
        }
        else if(pre[v.S]<pre[u] && v.S!=fa)
        {
            lowu=min(lowu,pre[v.S]);
        }
    }
    return lowu;
}
void dfs2(int u,int d)
{
    vis[u]=1;
    s[d].push_back(u);
    for(int i=0;i<g[u].size();i++)
    {
        pii v=g[u][i];
        if(vis[v.S] || b[v.F])continue;
        dfs2(v.S,d);
    }
}
main()
{
    int n,m;scanf("%d%d",&n,&m);
    while(m--)
    {
        int a,b;scanf("%d%d",&a,&b);
        g[a].push_back(mkp(m,b)),g[b].push_back(mkp(m,a));
    }
    dfs(0,-1);
    //for(int i=0;i<n;i++)printf("%d ",low[i]);puts("");
    int cnt=0;
    for(int i=0;i<n;i++)
        if(!vis[i])dfs2(i,++cnt);
    for(int i=1;i<=cnt;i++)sort(s[i].begin(),s[i].end());
    for(int u=1;u<=cnt;u++)
    {
        printf("%d:",u);
        for(int i=0;i<s[u].size();i++)printf(" %d",s[u][i]);
        puts("");
    }
    return 0;
}


#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
#define pii pair<int,int>
#define F first
#define S second
vector<pii> edge;
int to(int u,int id){return u^edge[id].F^edge[id].S;}
vector<int> g[maxn];
int n,m;
int s[maxn],sum;
int p[maxn],sz[maxn],ans[maxn];
int finds(int x){return p[x]==x ? x : p[x]=finds(p[x]);}
void Union(int x,int y,int id)
{
    int a=finds(x),b=finds(y);
    if(a==b)return ;
    if(sz[a]<sz[b])swap(a,b);
    sz[a]+=sz[b];p[b]=a;
    g[x].push_back(id),g[y].push_back(id);
}
int dfs(int u,int fa,int ii)
{
    for(int id : g[u])
    {
        int v=to(u,id);
        if(v==fa)continue;
        s[u]-=dfs(v,u,id);
    }
    int ret=-s[u];
    if(u==1)return ret;
    if(edge[ii].F==u)ans[ii]=ret;
    else ans[ii]=-ret;
    return ret;
}
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&s[i]),sum+=s[i];
    if(sum)return 0*puts("Impossible");
    for(int i=1;i<=n;i++)p[i]=i,sz[i]=1;
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        edge.push_back(pii(x,y));
        Union(x,y,i);
    }
    puts("Possible");
    dfs(1,-1,-1);
    for(int i=0;i<m;i++)printf("%d\n",ans[i]);
    return 0;
}

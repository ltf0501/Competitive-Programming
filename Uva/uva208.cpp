#include<bits/stdc++.h>
using namespace std;
#define maxn 25
vector<int> g[maxn];
bool vis[maxn];
int ans=0,x,v[maxn];
int p[maxn];
int finds(int x){return p[x]==x ? x : p[x]=finds(p[x]);}
void dfs(int u,int cur)
{
    if(vis[u])return ;
    vis[u]=1;
    v[cur]=u;
    if(u==x)
    {
        for(int i=1;i<cur;i++)printf("%d ",v[i]);
        printf("%d\n",v[cur]);
        ans++;
        return ;
    }
    for(int v : g[u])if(!vis[v] && finds(v)==finds(x))
    {
        dfs(v,cur+1);
        vis[v]=0;
    }
}
void init()
{
    for(int i=1;i<=21;i++)g[i].clear();
    memset(vis,0,sizeof(vis));
    ans=0;
    for(int i=1;i<=21;i++)p[i]=i;
}
main()
{
    int cas=0;
    while(~scanf("%d",&x))
    {
        init();
        int a,b;
        while(~scanf("%d%d",&a,&b) && a+b)
        {
            g[a].push_back(b),g[b].push_back(a);
            int aa=finds(a),bb=finds(b);
            if(aa!=bb)p[aa]=bb;
        }
        for(int i=1;i<=21;i++)sort(g[i].begin(),g[i].end());
        //puts("");
        //for(int i=1;i<e.size();i++)printf("%d ",mark[i]);puts("");
        printf("CASE %d:\n",++cas);
        dfs(1,1);
        printf("There are %d routes from the firestation to streetcorner %d.\n",ans,x);
    }
    return 0;
}

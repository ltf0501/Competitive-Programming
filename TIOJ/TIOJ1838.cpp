#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
struct edge{int to,d;}f[maxn];
vector<edge> g[maxn];
int n,m,l;
int sz[maxn],z[5];
bool vis[maxn];
edge dfs(int u,int fa)
{
    vis[u]=1;
    edge ret={u,0};
    f[u]=ret;
    for(auto v : g[u])if(v.to!=fa)
    {
        edge tmp=dfs(v.to,u);
        tmp.d+=v.d;
        if(tmp.d>ret.d)ret=tmp,f[u]=v;
    }
    return ret;
}
int ans;
void init()
{
    memset(vis,0,sizeof(vis));
    ans=0;
    for(int i=1;i<=n;i++)g[i].clear();
    memset(z,0,sizeof(z));
}
main()
{
    while(~scanf("%d%d%d",&n,&m,&l))
    {
        init();
        for(int i=1;i<=m;i++)
        {
            int x,y,d;scanf("%d%d%d",&x,&y,&d);
            x++,y++;
            g[x].push_back({y,d}),g[y].push_back({x,d});
        }
        for(int i=1;i<=n;i++)if(!vis[i])
        {
            int a=dfs(i,0).to;
            int tmp=dfs(a,0).d;
            ans=max(ans,tmp);
            int sum=0,id=3;
            if(tmp)while(sum+f[a].d<=tmp/2)sum+=f[a].d,a=f[a].to;
            tmp=min(tmp-sum,sum+f[a].d);
            while(id && tmp>z[id-1])z[id]=z[id-1],id--;
            z[id]=tmp;
        }
        if(n-m>1)
        {
            ans=max(ans,z[0]+l+z[1]);
            if(n-m>2)ans=max(ans,z[1]+z[2]+l*2);
        }
        printf("%d\n",ans);
    }

    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define maxn 30010
#define maxm 50010
int fa[maxn],n;
int finds(int x){return fa[x]==x ? x : fa[x]=finds(fa[x]);}
struct edge
{
    int from,to,dis;
    bool operator < (const edge& b)const
    {
        return dis<b.dis;
    }
}e[maxm];
struct node{int to,dis;};
vector<node> g[maxn];
int anc[20][maxn],ancdis[20][maxn];
int in[maxn],out[maxn],dfs_clock=0;
void dfs(int u,int f)
{
    in[u]=++dfs_clock;
    for(auto v : g[u])
    {
        if(v.to==f)continue;
        anc[0][v.to]=u;
        ancdis[0][v.to]=v.dis;
        dfs(v.to,u);
    }
    out[u]=++dfs_clock;
}
bool ancestor(int x,int y){return in[x]<=in[y] && out[x]>=out[y];}
void build()
{
    memset(anc[0],-1,sizeof(anc[0]));
    for(int i=0;i<=17;i++)anc[i][0]=0;
    for(int i=1;i<=n;i++)if(anc[0][i]==-1)
    {
        anc[0][i]=0;
        ancdis[0][i]=0;
        dfs(i,0);
    }
    for(int i=1;(1<<i)<=n;i++)for(int j=1;j<=n;j++)
    {
        anc[i][j]=anc[i-1][anc[i-1][j]];
        ancdis[i][j]=max(ancdis[i-1][j],ancdis[i-1][anc[i-1][j]]);
    }
}
int LCA(int x,int y)
{
    if(x==y)return 0;
    if(ancestor(y,x))swap(x,y);
    int ret=0;
    for(int i=17;i>=0;i--)
    {
        if(ancestor(anc[i][y],x))continue;
        ret=max(ret,ancdis[i][y]);
        y=anc[i][y];
    }
    ret=max(ret,ancdis[0][y]);y=anc[0][y];
    if(x==y)return ret;
    for(int i=17;i>=0;i--)
    {
        if(ancestor(anc[i][x],y))continue;
        ret=max(ret,ancdis[i][x]);
        x=anc[i][x];
    }
    ret=max(ret,ancdis[0][x]);
    return ret;
}
main()
{
    int m;scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)scanf("%d%d%d",&e[i].from,&e[i].to,&e[i].dis);
    for(int i=1;i<=n;i++)fa[i]=i;
    sort(e+1,e+m+1);
    for(auto i : e)
    {
        int x=finds(i.from),y=finds(i.to);
        if(x==y)continue;
        fa[x]=y;
        g[i.from].push_back((node){i.to,i.dis});
        g[i.to].push_back((node){i.from,i.dis});
    }
    /*
    for(int u=1;u<=n;u++)
    {
        printf("%d: ",u);
        for(auto v : g[u])printf("%d ",v.to);
        puts("");
    }
    */
    int q;scanf("%d",&q);
    in[0]=0;
    build();
    out[0]=++dfs_clock;
    /*
    for(int u=1;u<=n;u++)
    {
        printf("%d: ",u);
        for(int i=0;i<=3;i++)printf("%d ",anc[i][u]);
        puts("");
    }
    */
    while(q--)
    {
        int x,y;scanf("%d%d",&x,&y);
        if(finds(x)!=finds(y))puts("-1");
        else printf("%d\n",LCA(x,y));
    }
    return 0;
}

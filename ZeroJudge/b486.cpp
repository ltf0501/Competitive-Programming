#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
int n,m;
int p[maxn];
vector<int> g[maxn];
int anc[18][maxn];
int in[maxn],out[maxn],dfs_clock,dep[maxn];
bool vis[maxn];
void init()
{
    for(int i=1;i<=n;i++)p[i]=i;
    for(int i=1;i<=n;i++)g[i].clear();
    memset(anc,0,sizeof(anc));
    memset(in,0,sizeof(in));
    memset(out,0,sizeof(out));
    memset(vis,0,sizeof(vis));
    memset(dep,0,sizeof(dep));
    dfs_clock=0;
}
int finds(int x){return p[x]==x ? x : p[x]=finds(p[x]);}
struct Q
{
    char c;
    int x,y;
}query[maxn];
void dfs(int u,int fa,int d)
{
    in[u]=++dfs_clock;
    dep[u]=d;
    vis[u]=1;
    for(int v : g[u])if(v!=fa)
    {
        anc[0][v]=u;
        dfs(v,u,d+1);
    }
    out[u]=++dfs_clock;
}
void pre()
{
    for(int i=1;i<=17;i++)
        for(int j=1;j<=n;j++)anc[i][j]=anc[i-1][anc[i-1][j]];
}
bool ancestor(int x,int y){return in[x]<=in[y] && out[x]>=out[y];}
int LCA(int x,int y)
{
    if(ancestor(x,y))return x;
    if(ancestor(y,x))return y;
    for(int i=17;i>=0;i--)if(!ancestor(anc[i][x],y))
        x=anc[i][x];
    return anc[0][x];
}
/*
int dist(int x,int y)//x必定y的後輩
{
    if(x==y)return 1;
    int ret=1;
    for(int i=17;i>=0;i--)if(!ancestor(anc[i][x],y))
        x=anc[i][x],ret+=(1<<i);
    return ret+1;
}
int origin(int x)
{
    int a=finds(x);
    for(int i=17;i>=0;i--)if(finds(anc[i][x])==a)
        x=anc[i][x];
    return x;
}
*/
main()
{
    while(~scanf("%d%d",&n,&m))
    {
        init();
        for(int i=1;i<=m;i++)
        {
            char c[5];int x,y;
            scanf("%s %d %d",c,&x,&y);
            query[i].c=c[0],query[i].x=x,query[i].y=y;
            if(c[0]=='n')
                g[x].push_back(y),g[y].push_back(x);
        }
        //for(int i=1;i<=m;i++)printf("%s %d %d\n",query[i].c,query[i].x,query[i].y);
        for(int i=1;i<=n;i++)if(!vis[i])dfs(i,0,1);
        out[0]=++dfs_clock;
        pre();
        for(int i=1;i<=m;i++)
        {
            if(query[i].c=='n')
            {
                int u=finds(query[i].x),v=finds(query[i].y);
                p[u]=v;
            }
            else
            {
                int u=finds(query[i].x),v=finds(query[i].y);
                if(u!=v){puts("-1");continue;}
                if(u>v)swap(u,v);
                int l=LCA(query[i].x,query[i].y);
                //int o=origin(l);
                int s=2*(dep[l]-dep[u]+1),t=(dep[query[i].x]-dep[u]+1)+(dep[query[i].y]-dep[u]+1);
                int g=__gcd(s,t);s/=g,t/=g;
                printf("%d/%d\n",s,t);
            }
        }
    }
    return 0;
}
/*
5 9
news 3 2
news 4 2
sim 3 4
sim 3 5
news 2 1
news 5 4
sim 3 4
sim 3 5
sim 4 4
*/

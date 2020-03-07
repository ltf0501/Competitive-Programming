#include<bits/stdc++.h>
using namespace std;
#define maxn 1000010
#define maxd 18
vector<int> g[maxn];
int n,m,k,q;
int anc[maxd][maxn],dep[maxn];
int p[maxn];
int finds(int x){return p[x]==x ? x : p[x]=finds(p[x]);}
void dfs(int u,int fa,int d)
{
    dep[u]=d;
    anc[0][u]=fa;
    for(int v : g[u])if(v!=fa)
        dfs(v,u,d+1);
}
void build()
{
    for(int i=1;(1<<i)<=n && i<maxd;i++)for(int j=1;j<=n;j++)
        anc[i][j]=anc[i-1][anc[i-1][j]];
}
int query_fa(int u,int dis)
{
    if(!dis)return u;
    for(int i=maxd-1;dis;i--)while(dis>=(1<<i))
    {
        u=anc[i][u];
        dis-=(1<<i);
    }
    return u;
}
int LCA(int x,int y)
{
    if(x==y)return x;
    if(dep[x]<dep[y])return LCA(x,query_fa(y,dep[y]-dep[x]));
    if(dep[x]>dep[y])return LCA(query_fa(x,dep[x]-dep[y]),y);
    for(int i=maxd-1;i>=0;i--)while(anc[i][x]!=anc[i][y])
        x=anc[i][x],y=anc[i][y];
    return anc[0][x];
}
main()
{
    scanf("%d%d%d%d",&n,&m,&k,&q);
    for(int i=1;i<n;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        g[x].push_back(y),g[y].push_back(x);
    }
    dfs(1,0,0);
    build();
    for(int i=1;i<=n;i++)p[i]=i;
    while(k--)
    {
        int x,y;scanf("%d%d",&x,&y);
        if(finds(x)==finds(y))continue;
        int u=LCA(x,y);
        u=finds(u);
        while(1)
        {
            int a=finds(x);
            if(dep[a]<=dep[u])break;
            p[a]=u;
            x=anc[0][a];
        }
        while(1)
        {
            int b=finds(y);
            if(dep[b]<=dep[u])break;
            p[b]=u;
            y=anc[0][b];
        }
    }
    while(q--)
    {
        int x,y;scanf("%d%d",&x,&y);
        puts(finds(x)==finds(y) ? "1" : "0");
    }
    return 0;
}

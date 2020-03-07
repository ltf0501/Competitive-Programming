#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
#define pii pair<int,int>
#define F first
#define S second
vector<pii> e;
vector<int> g[maxn],bcc_g[maxn];
int n,m,q;
int bccno[maxn],bcc_cnt;
int pre[maxn],cur;
stack<int> S;
int to(int x,int id){return e[id].F^e[id].S^x;}
int dfs1(int u,int fa)
{
    S.push(u);
    int lowu=pre[u]=++cur;
    for(int v : g[u])if(v!=fa)
    {
        int p=to(u,v);
        if(!pre[p])lowu=min(lowu,dfs1(p,v));
        else lowu=min(lowu,pre[p]);
    }
    if(lowu==pre[u])
    {
        bcc_cnt++;
        while(1)
        {
            int x=S.top();S.pop();
            bccno[x]=bcc_cnt;
            if(x==u)break;
        }
    }
    return lowu;
}
int p[maxn],sz[maxn];
int finds(int x){return p[x]==x ? x : p[x]=finds(p[x]);}
void Union(int x,int y)
{
    int a=finds(x),b=finds(y);
    if(a==b)return ;
    if(sz[a]<sz[b])swap(a,b);
    sz[a]+=sz[b],p[b]=a;
}
int anc[20][maxn];
int in[maxn],out[maxn],dfs_clock;
void dfs2(int u,int fa)
{
    in[u]=++dfs_clock;
    anc[0][u]=fa;
    for(int v : bcc_g[u])if(v!=fa)
        dfs2(v,u);
    out[u]=dfs_clock;
}
void preprocess()
{
    for(int i=1;i<=18;i++)
        for(int j=1;j<=bcc_cnt;j++)anc[i][j]=anc[i-1][anc[i-1][j]];
}
bool ancestor(int x,int y){return in[x]<=in[y] && out[x]>=out[y];}
int LCA(int x,int y)
{
    if(ancestor(x,y))return x;
    if(ancestor(y,x))return y;
    for(int i=18;i>=0;i--)if(!ancestor(anc[i][x],y))
        x=anc[i][x];
    return anc[0][x];
}
int down[maxn],up[maxn];
void dfs3(int u,int fa)
{
    for(int v : bcc_g[u])if(v!=fa)
    {
        dfs3(v,u);
        up[u]+=up[v],down[u]+=down[v];
    }
}
main()
{
    scanf("%d%d%d",&n,&m,&q);
    e.push_back(pii(0,0));
    for(int i=1;i<=m;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        e.push_back(pii(x,y));
        g[x].push_back(i),g[y].push_back(i);
    }
    for(int i=1;i<=n;i++)if(!pre[i])dfs1(i,0);
    //for(int i=1;i<=n;i++)printf("%d ",bccno[i]);puts("");
    for(int i=1;i<=bcc_cnt;i++)p[i]=i,sz[i]=1;
    for(pii v : e)if(bccno[v.F]!=bccno[v.S])
    {
        bcc_g[bccno[v.F]].push_back(bccno[v.S]),
        bcc_g[bccno[v.S]].push_back(bccno[v.F]);
        Union(bccno[v.F],bccno[v.S]);
    }
    for(int i=1;i<=bcc_cnt;i++)
        if(!in[i])dfs2(i,i);
    preprocess();
    for(int i=1;i<=q;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        x=bccno[x],y=bccno[y];
        if(x==y)continue;
        if(finds(x)!=finds(y))return 0*puts("No");
        int l=LCA(x,y);
        up[x]++,up[l]--;
        down[y]++,down[l]--;
    }
    for(int i=1;i<=bcc_cnt;i++)
        if(anc[0][i]==i)dfs3(i,0);
    for(int i=1;i<=bcc_cnt;i++)
        if(up[i]>0 && down[i]>0)return 0*puts("No");
    puts("Yes");
    return 0;
}
/*
8 7 8
6 3
4 5
2 5
7 3
7 8
4 7
1 5
6 3
5 2
6 3
6 4
6 3
6 3
1 5
5 2
*/

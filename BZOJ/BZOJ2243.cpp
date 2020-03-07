#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
vector<int> g[maxn];
int in[maxn],out[maxn],dfs_clock;
int sz[maxn],maxson[maxn],top[maxn],p[maxn];
int n,m;
int col[maxn],b[maxn];
void dfs1(int u,int fa)
{
    sz[u]=1,p[u]=fa;
    int mxer=0;
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(v==fa)continue;
        dfs1(v,u);
        sz[u]+=sz[v];
        if(sz[v]>sz[mxer])mxer=v;
    }
    maxson[u]=mxer;
}
void dfs2(int u,int tp)
{
    in[u]=++dfs_clock,top[u]=tp;
    if(maxson[u])dfs2(maxson[u],tp);
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(v==p[u] || v==maxson[u])continue;
        dfs2(v,v);
    }
    out[u]=dfs_clock;
}
int seg[maxn<<2],le[maxn<<2],ri[maxn<<2],tg[maxn<<2];
void push_up(int o)
{
    seg[o]=seg[o<<1]+seg[o<<1|1]-(ri[o<<1]==le[o<<1|1]);
    le[o]=le[o<<1],ri[o]=ri[o<<1|1];
}
void push_down(int o)
{
    if(tg[o]==-1)return ;
    le[o<<1]=ri[o<<1]=le[o<<1|1]=ri[o<<1|1]=tg[o];
    tg[o<<1]=tg[o<<1|1]=tg[o];
    seg[o<<1]=seg[o<<1|1]=1;
    tg[o]=-1;
}
void build(int l,int r,int o)
{
    if(l==r){seg[o]=1,le[o]=ri[o]=b[l];return ;}
    int m=(l+r)>>1;
    build(l,m,o<<1),build(m+1,r,o<<1|1);
    push_up(o);
}
void update(int l,int r,int o,int ql,int qr,int k)
{
    if(ql<=l && r<=qr){seg[o]=1,tg[o]=k;return ;}
    int m=(l+r)>>1;
    push_down(o);
    if(ql<=m)update(l,m,o<<1,ql,qr,k);
    if(qr>m)update(m+1,r,o<<1|1,ql,qr,k);
    push_up(o);
}
int query(int l,int r,int o,int ql,int qr)
{
    if(ql<=l && r<=qr)return seg[o];
    int m=(l+r)>>1;
    push_down(o);
    if(qr<=m)return query(l,m,o<<1,ql,qr);
    if(ql>m)return query(m+1,r,o<<1|1,ql,qr);
    return query(l,m,o<<1,ql,qr)+query(m+1,r,o<<1|1,ql,qr)-(ri[o<<1]==le[o<<1|1]);
}
int find_col(int l,int r,int o,int x)
{
    if(l==r)return le[o];
    int m=(l+r)>>1;
    push_down(o);
    if(x<=m)return find_col(l,m,o<<1,x);
    else return find_col(m+1,r,o<<1|1,x);
}
bool ancestor(int x,int y){return in[x]<=in[y] && out[x]>=out[y];}
void modify(int x,int y,int k)
{
    while(top[x]!=top[y])
    {
        if(ancestor(top[x],top[y]))swap(x,y);
        update(1,n,1,in[top[x]],in[x],k);x=p[top[x]];
    }
    if(in[x]>in[y])swap(x,y);
    update(1,n,1,in[x],in[y],k);
}
int query(int x,int y)
{
    int colx=-1,coly=-1;
    int ans=0;
    while(top[x]!=top[y])
    {
        if(ancestor(top[x],top[y]))swap(x,y),swap(colx,coly);
        int k;
        ans+=k=query(1,n,1,in[top[x]],in[x])-(find_col(1,n,1,in[x])==colx);
        printf("%d %d %d\n",top[x],x,k);
        colx=find_col(1,n,1,in[top[x]]),x=p[top[x]];
    }
    if(in[x]>in[y])swap(x,y),swap(colx,coly);
    int k,a,b;
    ans+=k=query(1,n,1,in[x],in[y])-(a=find_col(1,n,1,in[x])==colx)-(b=find_col(1,n,1,in[y])==coly);
    printf("%d %d %d %d %d %d %d\n",x,y,k,a,colx,b,coly);
    return ans;
}
main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&col[i]);
    for(int i=1;i<n;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        g[x].push_back(y),g[y].push_back(x);
    }
    dfs1(1,0);
    dfs2(1,1);out[0]=dfs_clock;
    for(int i=1;i<=n;i++)b[in[i]]=col[i];
    build(1,n,1);
    for(int i=1;i<(maxn<<2);i++)tg[i]=-1;
    while(m--)
    {
        char c[2];scanf("%s",c);
        int x,y;scanf("%d%d",&x,&y);
        if(c[0]=='C')
        {
            int k;scanf("%d",&k);
            modify(x,y,k);
        }
        else printf("%d\n",query(x,y));
    }
    return 0;
}

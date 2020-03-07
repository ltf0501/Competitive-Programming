#include<bits/stdc++.h>
using namespace std;
#define maxn 50010
#define ll long long
vector<int> g[maxn];
ll val[maxn];
int fa[maxn],sz[maxn],dep[maxn],top[maxn],maxson[maxn];
int in[maxn],num=0;
void dfs1(int u,int f,int d)
{
    sz[u]=1;
    maxson[u]=0;
    fa[u]=f;
    dep[u]=d;
    int tmp=0;
    for(int v : g[u])
    {
        if(v==f)continue;
        dfs1(v,u,d+1);
        sz[u]+=sz[v];
        if(sz[v]>tmp)sz[v]=tmp,maxson[u]=v;
    }
}
void dfs2(int u,int tp)
{
    in[u]=++num;top[u]=tp;
    if(maxson[u])dfs2(maxson[u],tp);
    for(int v : g[u])
    {
        if(v==fa[u] || v==maxson[u])continue;
        dfs2(v,v);
    }
}
ll sum[maxn<<2];
void push_up(int id)
{
    sum[id]=sum[id<<1]+sum[id<<1|1];
}
void build(int l,int r,int id)
{
    if(l==r)
    {
        sum[id]=val[l];
        return ;
    }
    int m=(l+r)>>1;
    build(l,m,id<<1),build(m+1,r,id<<1|1);
    push_up(id);
}
void update(int l,int r,int id,int p,int x)
{
    if(l==r)
    {
        sum[id]=(ll)x;
        return ;
    }
    int m=(l+r)>>1;
    if(p<=m)update(l,m,id<<1,p,x);
    else update(m+1,r,id<<1|1,p,x);
    push_up(id);
}
ll find_sum(int l,int r,int id,int ql,int qr)
{
    if(ql<=l && r<=qr)return sum[id];
    int m=(l+r)>>1;
    ll ret=0;
    if(ql<=m)ret+=find_sum(l,m,id<<1,ql,qr);
    if(qr>m)ret+=find_sum(m+1,r,id<<1|1,ql,qr);
    return ret;
}
ll query(int u,int v)
{
    int tp1=top[u],tp2=top[v];
    ll ret=0;
    while(tp1!=tp2)
    {
        if(dep[tp1]<dep[tp2])swap(tp1,tp2),swap(u,v);
        ret+=find_sum(1,num,1,in[tp1],in[u]);
        u=fa[tp1];
        tp1=top[u];
    }
    if(dep[u]>dep[v])swap(u,v);
    ret+=find_sum(1,num,1,in[u],in[v]);
    return ret;
}
main()
{
    int n,m;scanf("%d%d",&n,&m);
    for(int i=1;i<n;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        g[x].push_back(y),g[y].push_back(x);
    }
    dfs1(1,0,1);
    dfs2(1,1);
    for(int i=1;i<=n;i++)
    {
        ll v;scanf("%lld",&v);
        val[in[i]]=v;
    }
    build(1,num,1);
    ll ans=0;
    while(m--)
    {
        char s[2];scanf("%s",s);
        if(s[0]=='C')
        {
            int x,w;scanf("%d%d",&x,&w);
            update(1,num,1,in[x],w);
        }
        else
        {
            int x;scanf("%d",&x);
            ans+=query(1,x);
            //printf("now = %d\n",query(1,x));
        }
    }
    printf("%lld",ans);
    return 0;
}
/*
5 10
3 2
3 1
5 3
5 4
-24
-20
-75
7
-87
C 4 43
C 3 63
C 5 35
G 2
G 2
G 4
C 2 90
G 3
C 2 -23
G 5
*/

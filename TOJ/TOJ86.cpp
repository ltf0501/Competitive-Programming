#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
int fa[maxn],sz[maxn],dep[maxn],top[maxn],maxson[maxn];
int in[maxn];
int num=0;
vector<int> g[maxn];
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
        if(sz[v]>tmp)maxson[u]=v,tmp=sz[v];
    }
}
void dfs2(int u,int tp)
{
    top[u]=tp;in[u]=++num;
    if(maxson[u])dfs2(maxson[u],tp);
    for(int v : g[u])
    {
        if(v==maxson[u] || v==fa[u])continue;
        dfs2(v,v);
    }
}
int lazy[maxn<<2],sum[maxn<<2];
void push_down(int l,int r,int id)
{
    if(lazy[id]>0)
    {
        lazy[id<<1]+=lazy[id];
        lazy[id<<1|1]+=lazy[id];
        int m=(l+r)>>1;
        sum[id<<1]+=lazy[id]*(m-l+1);
        sum[id<<1|1]+=lazy[id]*(r-m);
        lazy[id]=0;
    }
}
void push_up(int id)
{
    sum[id]=sum[id<<1]+sum[id<<1|1];
}
void update(int l,int r,int id,int ul,int ur)
{
    if(ul<=l && r<=ur)
    {
        lazy[id]++;
        sum[id]+=(r-l+1);
        return ;
    }
    push_down(l,r,id);
    int m=(l+r)>>1;
    if(ur<=m)update(l,m,id<<1,ul,ur);
    else if(ul>m)update(m+1,r,id<<1|1,ul,ur);
    else
        update(l,m,id<<1,ul,m),
        update(m+1,r,id<<1|1,m+1,ur);
    push_up(id);
}
int find_sum(int l,int r,int id,int ql,int qr)
{
    if(ql==l && r==qr)
    {
        return sum[id];
    }
    int m=(l+r)>>1;
    push_down(l,r,id);
    int ret=0;
    if(qr<=m)return find_sum(l,m,id<<1,ql,qr);
    if(ql>m)return find_sum(m+1,r,id<<1|1,ql,qr);
    return find_sum(l,m,id<<1,ql,m)+find_sum(m+1,r,id<<1|1,m+1,qr);
}
void modify(int u,int v)
{
    int tp1=top[u],tp2=top[v];
    while(tp1!=tp2)
    {
        if(dep[tp1]<dep[tp2])swap(tp1,tp2),swap(u,v);
        update(1,num,1,in[tp1],in[u]);
        u=fa[tp1];
        tp1=top[u];
    }
    if(u==v)return ;
    if(dep[u]>dep[v])swap(u,v);
    update(1,num,1,in[maxson[u]],in[v]);
}
int query(int u,int v)
{
    int tp1=top[u],tp2=top[v];
    int ans=0;
    while(tp1!=tp2)
    {
        if(dep[tp1]<dep[tp2])swap(tp1,tp2),swap(u,v);
        ans+=find_sum(1,num,1,in[tp1],in[u]);
        u=fa[tp1];
        tp1=top[u];
    }
    if(u==v)return ans;
    if(dep[u]>dep[v])swap(u,v);
    ans+=find_sum(1,num,1,in[maxson[u]],in[v]);
    return ans;
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
    while(m--)
    {
        char c[2];int x,y;
        scanf("%s %d %d",c,&x,&y);
        if(c[0]=='P')
        {
            modify(x,y);
        }
        else
        {
            printf("%d\n",query(x,y));
        }
        /*
        for(int i=1;i<=n*3;i++)printf("%d ",sum[i]);puts("");
        for(int i=1;i<=n*3;i++)printf("%d ",lazy[i]);puts("");
        */
    }
    return 0;
}
/*
4 6
1 4
2 4
3 4
P 2 3
P 1 3
Q 3 4
P 1 4
Q 2 4
Q 1 4
*/

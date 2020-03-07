#include<bits/stdc++.h>
using namespace std;
#define maxn 500010
vector<int> g[maxn];
int in[maxn],out[maxn],dfs_clock,p[maxn];
void dfs(int u,int fa)
{
    in[u]=++dfs_clock;
    for(int v : g[u])
        if(v!=fa)dfs(v,u),p[v]=u;
    out[u]=dfs_clock;
}
int seg[maxn<<2],tg[maxn<<2];
void push_up(int o){seg[o]=seg[o<<1]+seg[o<<1|1];}
void push_down(int l,int r,int o)
{
    if(tg[o]==-1)return ;
    int m=(l+r)>>1;
    seg[o<<1]=tg[o]*(m-l+1),seg[o<<1|1]=tg[o]*(r-m);
    tg[o<<1]=tg[o],tg[o<<1|1]=tg[o];
    tg[o]=-1;
}
void update(int l,int r,int o,int ql,int qr,int k)
{
    if(ql<=l && r<=qr){tg[o]=k;seg[o]=k*(r-l+1);return ;}
    push_down(l,r,o);
    int m=(l+r)>>1;
    if(ql<=m)update(l,m,o<<1,ql,qr,k);
    if(qr>m)update(m+1,r,o<<1|1,ql,qr,k);
    push_up(o);
}
int query(int l,int r,int o,int ql,int qr)
{
    if(qr<l || ql>r)return 0;
    if(ql<=l && r<=qr)return seg[o];
    push_down(l,r,o);
    int m=(l+r)>>1;
    return query(l,m,o<<1,ql,qr)+query(m+1,r,o<<1|1,ql,qr);
}
main()
{
    int n;scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        g[x].push_back(y),g[y].push_back(x);
    }
    dfs(1,0);
    /*
    for(int i=1;i<=n;i++)printf("%d ",in[i]);puts("");
    for(int i=1;i<=n;i++)printf("%d ",out[i]);puts("");
    */
    for(int i=1;i<(maxn<<2);i++)tg[i]=-1;
    int q;scanf("%d",&q);
    while(q--)
    {
        int type,v;scanf("%d%d",&type,&v);
        if(type==1)
        {
            int k=query(1,n,1,in[v],out[v]);
            update(1,n,1,in[v],out[v],1);
            if(v!=1 && k!=out[v]-in[v]+1)update(1,n,1,in[p[v]],in[p[v]],0);
        }
        else if(type==2)
        {
            update(1,n,1,in[v],in[v],0);
        }
        else
        {
            int k=query(1,n,1,in[v],out[v]);
            printf("%d\n",k==out[v]-in[v]+1);
        }
    }
    return 0;
}


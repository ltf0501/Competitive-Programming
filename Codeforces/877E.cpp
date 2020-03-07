#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
vector<int> g[maxn];
bool a[maxn];
int b[maxn];
int in[maxn],out[maxn],dfs_clock=0;
void dfs(int u)
{
    in[u]=++dfs_clock;
    b[dfs_clock]=u;
    for(int v : g[u])dfs(v);
    out[u]=dfs_clock;
}
int seg[maxn<<2];
bool tg[maxn<<2];
void push_up(int o)
{
    seg[o]=seg[o<<1]+seg[o<<1|1];
}
void push_down(int l,int r,int o)
{
    if(!tg[o])return ;
    int m=(l+r)>>1;
    seg[o<<1]=(m-l+1)-seg[o<<1];
    seg[o<<1|1]=(r-m)-seg[o<<1|1];
    tg[o<<1]^=1,tg[o<<1|1]^=1;
    tg[o]=0;
}
void build(int l,int r,int o)
{
    if(l==r){seg[o]=a[b[l]];return ;}
    int m=(l+r)>>1;
    build(l,m,o<<1),build(m+1,r,o<<1|1);
    push_up(o);
}
void update(int l,int r,int o,int ql,int qr)
{
    if(ql<=l && r<=qr){tg[o]^=1;seg[o]=(r-l+1)-seg[o];return ;}
    push_down(l,r,o);
    int m=(l+r)>>1;
    if(ql<=m)update(l,m,o<<1,ql,qr);
    if(qr>m)update(m+1,r,o<<1|1,ql,qr);
    push_up(o);
}
int query(int l,int r,int o,int ql,int qr)
{
    if(ql<=l && r<=qr)return seg[o];
    push_down(l,r,o);
    int m=(l+r)>>1;
    int ret=0;
    if(ql<=m)ret+=query(l,m,o<<1,ql,qr);
    if(qr>m)ret+=query(m+1,r,o<<1|1,ql,qr);
    return ret;
}
main()
{
    int n;scanf("%d",&n);
    for(int i=2;i<=n;i++)
    {
        int x;scanf("%d",&x);
        g[x].push_back(i);
    }
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    dfs(1);
    build(1,n,1);
    int q;scanf("%d",&q);
    while(q--)
    {
        char c[5];int x;
        scanf("%s%d",c,&x);
        if(c[0]=='p')update(1,n,1,in[x],out[x]);
        else printf("%d\n",query(1,n,1,in[x],out[x]));
    }
    return 0;
}
/*
10
1 2 3 4 2 4 1 7 8
1 1 0 1 1 0 0 0 1 1
10
pow 1
get 2
pow 2
pow 8
get 6
pow 6
pow 10
get 6
pow 8
pow 3
*/

#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
#define ll long long
const ll NO=-1e18;
int a[maxn];
ll k[maxn];
ll pre[maxn];
int n,q;
ll seg[maxn<<2],tg[maxn<<2];
void push_up(int o){seg[o]=seg[o<<1]+seg[o<<1|1];}
void gao(int l,int r,int o,ll lz)
{
    if(lz==NO)return ;
    seg[o]=1ll*(r-l+1)*lz+pre[r+1]-pre[l];
    tg[o]=lz;
}
void push_down(int l,int r,int o)
{
    if(tg[o]==NO)return ;
    int m=(l+r)>>1;
    gao(l,m,o<<1,tg[o]);
    gao(m+1,r,o<<1|1,tg[o]);
    tg[o]=NO;
}
void build(int l,int r,int o)
{
    tg[o]=NO;
    if(l==r){seg[o]=a[l];return ;}
    int m=(l+r)>>1;
    build(l,m,o<<1);build(m+1,r,o<<1|1);
    push_up(o);
}
void update(int l,int r,int o,int ql,int qr,ll x)
{
    if(ql<=l && r<=qr)
    {
        gao(l,r,o,x); return ;
    }
    push_down(l,r,o);
    int m=(l+r)>>1;
    if(ql<=m)update(l,m,o<<1,ql,qr,x);
    if(qr>m)update(m+1,r,o<<1|1,ql,qr,x);
    push_up(o);
}
ll query(int l,int r,int o,int ql,int qr)
{
    if(ql<=l && r<=qr)return seg[o];
    push_down(l,r,o);
    int m=(l+r)>>1;
    if(qr<=m)return query(l,m,o<<1,ql,qr);
    if(ql>m)return query(m+1,r,o<<1|1,ql,qr);
    return query(l,m,o<<1,ql,qr)+query(m+1,r,o<<1|1,ql,qr);
}
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=2;i<=n;i++)scanf("%lld",&k[i]),k[i]+=k[i-1];
    for(int i=2;i<=n+1;i++)pre[i]=pre[i-1]+k[i-1];
    build(1,n,1);
    scanf("%d",&q);
    while(q--)
    {
        char c[2];scanf("%s",c);
        if(c[0]=='+')
        {
            int id,x;scanf("%d%d",&id,&x);
            ll d=query(1,n,1,id,id);
            int l=id,r=n;
            while(l<r)
            {
                int m=(l+r+1)>>1;
                if(d+x+k[m]-k[id]>query(1,n,1,m,m))l=m;
                else r=m-1;
            }
            update(1,n,1,id,r,d+x-k[id]);
        }
        else
        {
            int l,r;scanf("%d%d",&l,&r);
            printf("%lld\n",query(1,n,1,l,r));
        }
    }
    return 0;
}

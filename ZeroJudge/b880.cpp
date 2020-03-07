#include<bits/stdc++.h>
using namespace std;
#define maxn 1000010
#define inf 1000000000
int x[maxn],y[maxn];
int n,q;
struct node
{
    int lz,mv,ym;
}tr[maxn*4];
void build(int l,int r,int o)
{
    if(l==r){tr[o]=(node){inf,x[l]+y[l],y[l]};return ;}
    int m=(l+r)>>1;
    build(l,m,o<<1),build(m+1,r,o<<1|1);
    tr[o]=(node){inf,min(tr[o<<1].mv,tr[o<<1|1].mv),min(tr[o<<1].ym,tr[o<<1|1].ym)};
}
int gets(int o)
{
    return min(tr[o].mv,tr[o].ym+tr[o].lz);
}
void update(int l,int r,int o,int ql,int qr,int v)
{
    if(v>=tr[o].lz)return ;
    if(ql<=l && r<=qr){tr[o].lz=v;return ;}
    int m=(l+r)>>1;
    if(ql<=m)update(l,m,o<<1,ql,qr,v);
    if(qr>m)update(m+1,r,o<<1|1,ql,qr,v);
    tr[o].mv=min(gets(o<<1),gets(o<<1|1));
}
int query(int l,int r,int o,int ql,int qr,int v=inf)
{
    v=min(v,tr[o].lz);
    if(ql<=l && r<=qr)return min(tr[o].mv,v+tr[o].ym);
    int m=(l+r)>>1;
    int ret=inf;
    if(ql<=m)ret=min(ret,query(l,m,o<<1,ql,qr,v));
    if(qr>m)ret=min(ret,query(m+1,r,o<<1|1,ql,qr,v));
    return ret;
}
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&x[i]);
    for(int i=1;i<=n;i++)scanf("%d",&y[i]);
    int q;scanf("%d",&q);
    build(1,n,1);
    while(q--)
    {
        char c;cin>>c;
        if(c=='q')
        {
            int l,r;scanf("%d%d",&l,&r);
            printf("%d\n",query(1,n,1,l,r));
        }
        else
        {
            int l,r,d;scanf("%d%d%d",&l,&r,&d);
            update(1,n,1,l,r,d);
        }
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
int a[maxn];
int seg[maxn<<2];
int n;
void push_up(int o){seg[o]=min(seg[o<<1],seg[o<<1|1]);}
void build(int l,int r,int o)
{
    if(l==r){seg[o]=a[l];return ;}
    int m=(l+r)>>1;
    build(l,m,o<<1),build(m+1,r,o<<1|1);
    push_up(o);
}
int query(int l,int r,int o,int ql,int qr)
{
    if(ql<=l && r<=qr)return seg[o];
    int m=(l+r)>>1;
    if(qr<=m)return query(l,m,o<<1,ql,qr);
    if(ql>m)return query(m+1,r,o<<1|1,ql,qr);
    return min(query(l,m,o<<1,ql,qr),query(m+1,r,o<<1|1,ql,qr));
}
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    build(1,n,1);
    for(int i=1;i<=n;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        printf("%d\n",query(1,n,1,x,y)+1);
    }
    return 0;
}

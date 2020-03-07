#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
#define ll long long
int n,q,a[maxn];
ll sum[maxn<<2],mx[maxn<<2],tg[maxn<<2];
void push_up(int o)
{
    sum[o]=sum[o<<1]+sum[o<<1|1];
    mx[o]=max(mx[o<<1],mx[o<<1|1]);
}
void push_down(int o)
{
    if(!tg[o])return ;
    mx[o<<1]+=tg[o],mx[o<<1|1]+=tg[o];
    tg[o<<1]+=tg[o],tg[o<<1|1]+=tg[o];
    tg[o]=0;
}
void build(int l,int r,int o,ll cur)
{
    if(l==r){sum[o]=a[l];mx[o]=a[l]-cur;return ;}
    int m=(l+r)>>1;
    build(l,m,o<<1,cur),build(m+1,r,o<<1|1,cur+sum[o<<1]);
    push_up(o);
}
void update1(int l,int r,int o,int p,int k,ll cur)
{
    if(l==r){sum[o]=k,mx[o]=k-cur;return ;}
    push_down(o);
    int m=(l+r)>>1;
    if(p<=m)update1(l,m,o<<1,p,k,cur);
    else update1(m+1,r,o<<1|1,p,k,cur+sum[o<<1]);
    push_up(o);
}
void update2(int l,int r,int o,int ql,int qr,int k)
{
    if(ql<=l && r<=qr){mx[o]+=k,tg[o]+=k;return ;}
    push_down(o);
    int m=(l+r)>>1;
    if(ql<=m)update2(l,m,o<<1,ql,qr,k);
    if(qr>m)update2(m+1,r,o<<1|1,ql,qr,k);
    push_up(o);
}
int query(int l,int r,int o)
{
    if(mx[o]<0)return -1;
    if(l==r)
    {
        return mx[o]==0 ? l : -1;
    }
    push_down(o);
    int m=(l+r)>>1;
    int ret=-1;
    if(mx[o<<1]>=0)ret=query(l,m,o<<1);
    if(ret==-1 && mx[o<<1|1]>=0)ret=query(m+1,r,o<<1|1);
    return ret;
}
main()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    build(1,n,1,0);
    while(q--)
    {
        int id,x;scanf("%d%d",&id,&x);
        update1(1,n,1,id,x,0);
        if(id<n)update2(1,n,1,id+1,n,a[id]-x);
        a[id]=x;
        printf("%d\n",query(1,n,1));
        //for(int i=1;i<=5;i++)printf("%d ",mx[i]);puts("");
        //for(int i=1;i<=5;i++)printf("%d ",tg[i]);puts("");
    }
    return 0;
}

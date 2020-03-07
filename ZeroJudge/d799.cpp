#include<bits/stdc++.h>
using namespace std;
#define maxn 500010
#define ll long long
int a[maxn];
ll sum[maxn*3],tag[maxn*3];
void push_down(int l,int r,int o)
{
    if(!tag[o])return ;
    tag[o<<1]+=tag[o];
    tag[o<<1|1]+=tag[o];
    int m=(l+r)>>1;
    sum[o<<1]+=tag[o]*(m-l+1);
    sum[o<<1|1]+=tag[o]*(r-m);
    tag[o]=0;
}
void push_up(int o)
{
    sum[o]=sum[o<<1]+sum[o<<1|1];
}
void build(int l,int r,int o)
{
    if(l==r){sum[o]=a[l];return;}
    int m=(l+r)>>1;
    build(l,m,o<<1),build(m+1,r,o<<1|1);
    push_up(o);
}
void update(int l,int r,int o,int ql,int qr,int k)
{
    if(ql<=l && r<=qr){tag[o]+=k;sum[o]+=k*(r-l+1);return ;}
    push_down(l,r,o);
    int m=(l+r)>>1;
    if(ql<=m)update(l,m,o<<1,ql,qr,k);
    if(qr>m)update(m+1,r,o<<1|1,ql,qr,k);
    push_up(o);
}
ll query(int l,int r,int o,int ql,int qr)
{
    if(ql<=l && r<=qr)return sum[o];
    push_down(l,r,o);
    int m=(l+r)>>1;
    ll ans=0;
    if(ql<=m)ans+=query(l,m,o<<1,ql,qr);
    if(qr>m)ans+=query(m+1,r,o<<1|1,ql,qr);
    return ans;
}
main()
{
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    build(1,n,1);
    /*
    printf("sum: ");
    for(int i=1;i<=7;i++)printf("%d ",sum[i]);puts("");
    printf("tag: ");
    for(int i=1;i<=7;i++)printf("%d ",tag[i]);puts("");
    */
    int q;scanf("%d",&q);
    while(q--)
    {
        int v;scanf("%d",&v);
        if(v==1)
        {
            int x,y,k;scanf("%d%d%d",&x,&y,&k);
            update(1,n,1,x,y,k);
        }
        else
        {
            int x,y;scanf("%d%d",&x,&y);
            printf("%lld\n",query(1,n,1,x,y));
        }
        /*
        printf("sum: ");
        for(int i=1;i<=15;i++)printf("%d ",sum[i]);puts("");
        printf("tag: ");
        for(int i=1;i<=15;i++)printf("%d ",tag[i]);puts("");
        */
    }
    return 0;
}

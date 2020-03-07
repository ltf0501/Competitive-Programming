#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 1000010
ll a[maxn],sum[maxn];
ll mx[maxn<<2];
int n;
ll k;
void build(int l,int r,int o)
{
    if(l==r){mx[o]=a[l];return ;}
    int m=(l+r)>>1;
    build(l,m,o<<1),build(m+1,r,o<<1|1);
    mx[o]=max(mx[o<<1],mx[o<<1|1]);
}
ll query(int l,int r,int o,int ql,int qr)
{
    if(ql<=l && r<=qr)return mx[o];
    int m=(l+r)>>1;
    ll ret=0;
    if(ql<=m)ret=max(ret,query(l,m,o<<1,ql,qr));
    if(qr>m)ret=max(ret,query(m+1,r,o<<1|1,ql,qr));
    return ret;
}
bool check(int s)
{
    for(int i=1;i+s-1<=n;i++)
    {
        ll mx=query(1,n,1,i,i+s-1);
        if(mx*s-(sum[i+s-1]-sum[i-1])<=k)return 1;
    }
    return 0;
}
main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        scanf("%d %lld",&n,&k);
        memset(mx,0,sizeof(mx));
        memset(sum,0,sizeof(sum));
        for(int i=1;i<=n;i++)scanf("%lld",&a[i]),sum[i]=sum[i-1]+a[i];
        build(1,n,1);
        int l=1,r=n+1;
        while(r-l>1)
        {
            int m=(l+r)>>1;
            if(check(m))l=m;
            else r=m;
        }
        printf("%d\n",l);
    }

    return 0;
}

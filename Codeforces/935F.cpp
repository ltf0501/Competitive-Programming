#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
#define ll long long
ll ans,a[maxn],b[maxn];
int n;
ll seg[maxn<<2];
void push_up(int o){seg[o]=min(seg[o<<1],seg[o<<1|1]);}
void build(int l,int r,int o)
{
    if(l==r){seg[o]=b[l];return ;}
    int m=(l+r)>>1;
    build(l,m,o<<1),build(m+1,r,o<<1|1);
    push_up(o);
}
void update(int l,int r,int o,int v,ll x)
{
    if(l==r){seg[o]=x;return ;}
    int m=(l+r)>>1;
    if(v<=m)update(l,m,o<<1,v,x);
    else update(m+1,r,o<<1|1,v,x);
    push_up(o);
}
ll query(int l,int r,int o,int ql,int qr)
{
    if(ql<=l && r<=qr)return seg[o];
    int m=(l+r)>>1;
    if(qr<=m)return query(l,m,o<<1,ql,qr);
    if(ql>m)return query(m+1,r,o<<1|1,ql,qr);
    return min(query(l,m,o<<1,ql,m),query(m+1,r,o<<1|1,m+1,qr));
}
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    for(int i=n;i>=1;i--)a[i]-=a[i-1];
    for(int i=2;i<=n;i++)ans+=abs(a[i]);
    for(int i=1;i<=n;i++)b[i]=max(a[i+1],0ll)+max(-a[i],0ll);
    build(1,n,1);
    int q;scanf("%d",&q);
    while(q--)
    {
        int type,l,r;ll x;scanf("%d%d%d%lld",&type,&l,&r,&x);
        if(type==1)
        {
            if(l==r)
            {
                if(l==n)printf("%lld\n",ans-abs(a[n])+abs(a[n]+x));
                else
                {
                    ll tmp=ans;
                    tmp-=(abs(a[l])+abs(a[l+1]));
                    tmp+=(abs(a[l]+x)+abs(a[l+1]-x));
                    printf("%lld\n",tmp);
                }
            }
            else
            {
                ll s=query(1,n,1,l,r);
                s=min(s,x);
                printf("%lld\n",ans+(x-s)*2);
            }
        }
        else
        {
            ans-=(abs(a[l])+abs(a[r+1]));
            a[l]+=x,a[r+1]-=x;
            ans+=(abs(a[l])+abs(a[r+1]));
            update(1,n,1,l,max(a[l+1],0ll)+max(-a[l],0ll));
            if(l>1)update(1,n,1,l-1,max(a[l],0ll)+max(-a[l-1],0ll));
            update(1,n,1,r,max(a[r+1],0ll)+max(-a[r],0ll));
            if(r<n)update(1,n,1,r+1,max(a[r+2],0ll)+max(-a[r+1],0ll));
        }
    }
    return 0;
}

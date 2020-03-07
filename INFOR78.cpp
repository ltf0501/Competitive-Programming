#include<bits/stdc++.h>
using namespace std;
#define maxn 300010
#define ll long long
typedef tuple<ll,ll,ll,ll> T;
int n,q,M;
ll a[maxn];
ll pre[maxn<<2],suf[maxn<<2],ans[maxn<<2],prod[maxn<<2];
void push_up(int o)
{
    pre[o]=(pre[o<<1]+prod[o<<1]*pre[o<<1|1]%M)%M;
    suf[o]=(suf[o<<1|1]+prod[o<<1|1]*suf[o<<1]%M)%M;
    prod[o]=pre[o<<1]*prod[o<<1|1]*M;
    ans[o]=(ans[o<<1]+ans[o<<1|1])%M;
    ans[o]=(ans[o]+suf[o<<1]*pre[o<<1|1]%M)%M;
}
void build(int l,int r,int o)
{
    if(l==r){pre[o]=suf[o]=prod[o]=ans[o]=a[l];return ;}
    int m=(l+r)>>1;
    build(l,m,o<<1),build(m+1,r,o<<1|1);
    push_up(o);
}
T query(int l,int r,int o,int ql,int qr)
{
    if(ql<=l && r<=qr)return make_tuple(ans[o],pre[o],suf[o],prod[o]);
    int m=(l+r)>>1;
    if(qr<=m)return query(l,m,o<<1,ql,qr);
    if(ql>m)return query(m+1,r,o<<1|1,ql,qr);
    T le,ri;
    if(ql<=m)le=query(l,m,o<<1,ql,qr);
    if(qr>m)ri=query(m+1,r,o<<1|1,ql,qr);
    T res;
    get<0>(res)=(get<0>(le)+get<0>(ri))%M;
    (get<0>(res)+=get<2>(le)*get<1>(ri)%M)%=M;
    get<1>(res)=(get<1>(le)+get<3>(le)*get<1>(ri)%M)%M;
    get<2>(res)=(get<2>(ri)+get<3>(ri)*get<2>(le)%M)%M;
    get<3>(res)=get<3>(le)*get<3>(ri)%M;
    return res;
}
main()
{
    scanf("%d%d%d",&n,&q,&M);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    build(1,n,1);
    while(q--)
    {
        int l,r;scanf("%d%d",&l,&r);
        T ans=query(1,n,1,l,r);
        printf("%lld\n",get<0>(ans));
    }
    return 0;
}

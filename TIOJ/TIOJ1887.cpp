#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7;
const int maxn=500010;
ll x[maxn],y[maxn];
int n;
int lmx[maxn*4],rmx[maxn*4],mxid[maxn];
bool lmod[maxn*4],rmod[maxn*4];
ll do_mod(ll a,bool &tag)
{
    if(a>=maxn)tag=1;
    a%=maxn;
}
void push_up(int o)
{
    lmod[o]=rmod[o]=0;
    ll mmx;
    bool mmod=rmod[o<<1] || lmod[o<<1|1];
    mmx=do_mod(rmx[o<<1]*lmx[o<<1|1],mmod);
    if(rmod[o<<1] || lmod[o<<1|1] || mmod || y[mxid[o<<1]]<mmx*y[mxid[o<<1|1]])
    {
        mxid[o]=mxid[o<<1|1];
        lmx[o]=do_mod(lmx[o<<1]*mmx,lmod[o]);
        lmod[o]|=(lmod[o<<1] || mmod);
        rmx[o]=rmx[o<<1|1];
        rmod[o]=rmod[o<<1|1];
    }
    else
    {
        mxid[o]=mxid[o<<1];
        rmx[o]=do_mod(mmx*rmx)
    }
}
void build(int l,int r,int o)
{
    if(l==r)
    {
        lmx[o]=x[l];
        rmx[o]=1;
        lmod[o]=rmod[o]=0;
        return ;
    }
    int m=(l+r)>>1;
    build(l,m,o<<1),build(n+1,r,o<<1|1);
    push_up(o);
}
main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",&x[i]);
        for(int i=1;i<=n;i++)scanf("%d",&y[i]);
    }
    return 0;
}

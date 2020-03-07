#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
#define INF 1000000000
#define ll long long
int n,a,b;
ll seg[maxn<<2],tg[maxn<<2];
void push_down(int o)
{
    if(tg[o])
    {
        seg[o<<1]+=tg[o],seg[o<<1|1]+=tg[o];
        tg[o<<1]+=tg[o],tg[o<<1|1]+=tg[o];
        tg[o]=0;
    }
}
void push_up(int o){seg[o]=max(seg[o<<1],seg[o<<1|1]);}
void update1(int l,int r,int o,int ql,int qr,ll x)
{
    if(ql<=l && r<=qr){seg[o]+=x,tg[o]+=x;return ;}
    push_down(o);
    int m=(l+r)>>1;
    if(ql<=m)update1(l,m,o<<1,ql,qr,x);
    if(qr>m)update1(m+1,r,o<<1|1,ql,qr,x);
    push_up(o);
}
void update2(int l,int r,int o,int v,ll x)
{
    if(l==r){seg[o]=max(seg[o],x);return ;}
    push_down(o);
    int m=(l+r)>>1;
    if(v<=m)update2(l,m,o<<1,v,x);
    else update2(m+1,r,o<<1|1,v,x);
    push_up(o);
}
ll query(int l,int r,int o,int ql,int qr)
{
    if(ql<=l && r<=qr)return seg[o];
    push_down(o);
    int m=(l+r)>>1;
    ll ret=-INF;
    if(ql<=m)ret=max(ret,query(l,m,o<<1,ql,qr));
    if(qr>m)ret=max(ret,query(m+1,r,o<<1|1,ql,qr));
    return ret;
}
main()
{
    scanf("%d%d%d",&n,&a,&b);
    int pre=0;
    update1(0,maxn,1,1,maxn,-INF);
    for(int i=1;i<=n;i++)
    {
        int x;scanf("%d",&x);
        if(i==1){pre=x;continue;}
        ll le=query(0,maxn,1,1,x-1);
        ll ri=query(0,maxn,1,x+1,maxn);
        ll s=query(0,maxn,1,x,x);
        ll t=max({query(0,maxn,1,0,0),max(le,ri)+b,s+a});
        if(x==pre)update1(0,maxn,1,0,maxn,a);
        else update1(0,maxn,1,0,maxn,b);
        update2(0,maxn,1,pre,t);
        pre=x;
        //printf("%lld\n",seg[1]);
    }
    printf("%lld\n",seg[1]);
    return 0;
}
/*
5 3 1
3 3 2 1 2
*/

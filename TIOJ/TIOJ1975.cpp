#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
#define maxc 1000010
#define ll long long
#define pii pair<int,int>
#define F first
#define S second
pii a[maxn],b[maxn],cc[maxn<<1];
int n,mm;
bool cmp(pii x,pii y){return x.S<y.S;}
ll seg[maxc<<2],tg[maxc<<2],num[maxc];
void push_up(int o){seg[o]=seg[o<<1]+seg[o<<1|1];}
void push_down(int l,int r,int o)
{
    if(tg[o])
    {
        int m=(l+r)>>1;
        tg[o<<1]+=tg[o],tg[o<<1|1]+=tg[o];
        seg[o<<1]+=tg[o]*(m-l+1),seg[o<<1|1]+=tg[o]*(r-m);
        tg[o]=0;
    }
}
void update(int l,int r,int o,int ql,int qr,int d)
{
    if(ql<=l && r<=qr){seg[o]+=d,tg[o]+=d;return ;}
    push_down(l,r,o);
    int m=(l+r)>>1;
    if(ql<=m)update(l,m,o<<1,ql,qr,d);
    if(qr>m)update(m+1,r,o<<1|1,ql,qr,d);
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
bool solve(int x)
{
    for(int i=1;i<=mm;i++)
    {
        if(1ll*x*b[i].S-cur<b[i].F)return 0;
        cur+=b[i].F;
    }
    return 1;
}
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&a[i].F,&a[i].S);
        update(1,maxc,1,a[i].F,a[i].S,1);
        a[i].S++;
        cc[2*i-1]=pii(a[i].F,1);
        cc[2*i]=pii(a[i].S,-1);
    }
    for(int i=1;i<maxc;i++)num[i]=query(1,maxc,1,1,i);
    sort(a+1,a+n+1,cmp);
    sort(cc+1,cc+2*n+1);
    int mx=0,sum=0;
    for(int i=1;i<=2*n;i++)sum+=cc[i].S,mx=max(mx,sum);
    scanf("%d",&mm);
    for(int i=1;i<=mm;i++)scanf("%d%d",&b[i].F,&b[i].S);
    sort(b+1,b+mm+1,cmp);
    int l=mx,r=mm+n;
    while(r>l)
    {
        int m=(l+r)>>1;
        if(solve(m))r=m;
        else l=m+1;
    }
    printf("%d\n",l);
    return 0;
}
/*
1
2 5
2
3 6
4 6
*/

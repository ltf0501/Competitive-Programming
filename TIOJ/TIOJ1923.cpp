#include<bits/stdc++.h>
using namespace std;
#define maxn 400010
#define ll long long
const ll inf=4e14+5;
int m[maxn],d[maxn];
int n;
struct seg
{
    ll val,tg;
    int pos;
}c[maxn<<2];
void push_up(int o)
{
    c[o].val=min(c[o<<1].val,c[o<<1|1].val);
    c[o].pos=c[o<<1].val<c[o<<1|1].val ? c[o<<1].pos : c[o<<1|1].pos;
}
void push_down(int o)
{
    if(!c[o].tg)return ;
    c[o<<1].val+=c[o].tg,c[o<<1|1].val+=c[o].tg;
    c[o<<1].tg+=c[o].tg,c[o<<1|1].tg+=c[o].tg;
    c[o].tg=0;
}
void build(int l,int r,int o)
{
    if(l==r){c[o].val=0,c[o].tg=0,c[o].pos=l;return ;}
    int m=(l+r)>>1;
    build(l,m,o<<1),build(m+1,r,o<<1|1);
    push_up(o);
}
void update(int l,int r,int o,int ql,int qr,ll v)
{
    if(ql>qr)return ;
    if(ql<=l && r<=qr){c[o].val+=v,c[o].tg+=v;return ;}
    push_down(o);
    int m=(l+r)>>1;
    if(ql<=m)update(l,m,o<<1,ql,qr,v);
    if(qr>m)update(m+1,r,o<<1|1,ql,qr,v);
    push_up(o);
}
vector<int> ans;
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d%d",&m[i],&d[i]);
    build(1,n,1);
    for(int i=1;i<=n;i++)
    {
        if(i-d[i]<1)update(1,n,1,1,i-1,m[i]),update(1,n,1,i-d[i]+n,n,m[i]);
        else update(1,n,1,i-d[i],i-1,m[i]);
        if(i+d[i]>n)update(1,n,1,i+1,n,m[i]),update(1,n,1,1,i+d[i]-n,m[i]);
        else update(1,n,1,i+1,i+d[i],m[i]);
    }
    for(int i=1;i<=n;i++)
    {
        push_down(1);
        int k=c[1].pos;
        if(k-d[k]<1)update(1,n,1,1,k-1,-m[k]),update(1,n,1,k-d[k]+n,n,-m[k]);
        else update(1,n,1,k-d[k],k-1,-m[k]);
        if(k+d[k]>n)update(1,n,1,k+1,n,-m[k]),update(1,n,1,1,k+d[k]-n,-m[k]);
        else update(1,n,1,k+1,k+d[k],-m[k]);
        ans.push_back(k);
        update(1,n,1,k,k,inf);
    }
    reverse(ans.begin(),ans.end());
    for(int i : ans)printf("%d ",i);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
#define ll long long
int n;
struct node
{
    int l,r,h,d;
    bool operator < (const node& b)const{return h<b.h;}
}a[maxn*2];
ll c[maxn*2];
ll s[maxn*4],tg[maxn*4];
void push_up(int l,int r,int id)
{
    if(tg[id])s[id]=c[r+1]-c[l];
    else s[id]=s[id<<1]+s[id<<1|1];
}
void update(int l,int r,int id,int ql,int qr,int val)
{
    if(ql<=l && r<=qr){tg[id]+=val;push_up(l,r,id);return ;}
    int m=(l+r)>>1;
    if(ql<=m)update(l,m,id<<1,ql,qr,val);
    if(qr>m)update(m+1,r,id<<1|1,ql,qr,val);
    push_up(l,r,id);
}
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int L,R,D,U;scanf("%d%d%d%d",&L,&R,&D,&U);
        a[2*i-1]={L,R,D,1};
        a[2*i]={L,R,U,-1};
        c[2*i-1]=L,c[2*i]=R;
    }
    sort(a+1,a+2*n+1);
    sort(c+1,c+2*n+1);
    int m=unique(c+1,c+2*n+1)-c-1;
    ll ans=0;
    for(int i=1;i<2*n;i++)
    {
        int l=lower_bound(c+1,c+m+1,a[i].l)-c;
        int r=lower_bound(c+1,c+m+1,a[i].r)-c;
        if(l<r)update(1,m,1,l,r-1,a[i].d);
        ans+=s[1]*(a[i+1].h-a[i].h);
    }
    printf("%lld\n",ans);
    return 0;
}

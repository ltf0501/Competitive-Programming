#include<bits/stdc++.h>
using namespace std;
#define maxn 1000010
#define ll long long
int n,m;
int a[maxn],w[maxn];
int nxt[maxn],now[maxn];
int c[maxn];
struct node
{
    ll pre,sum;
}st[maxn<<2];
void push_up(int o)
{
    st[o].sum=st[o<<1].sum+st[o<<1|1].sum;
    st[o].pre=max(st[o<<1].pre,st[o<<1].sum+st[o<<1|1].pre);
}
void build(int l,int r,int o)
{
    if(l==r){st[o].pre=st[o].sum=c[l];return ;}
    int m=(l+r)>>1;
    build(l,m,o<<1),build(m+1,r,o<<1|1);
    push_up(o);
}
void update(int l,int r,int o,int pos,int val)
{
    if(pos<l || pos>r)return ;
    if(l==r){st[o].pre+=val,st[o].sum+=val;return ;}
    int m=(l+r)>>1;
    if(pos<=m)update(l,m,o<<1,pos,val);
    else update(m+1,r,o<<1|1,pos,val);
    push_up(o);
}
main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=m;i++)scanf("%d",&w[i]);
    for(int i=1;i<=n;i++)now[i]=n+1;
    for(int i=n;i>=1;i--)nxt[i]=now[a[i]],now[a[i]]=i;
    for(int i=1;i<=n;i++)c[now[a[i]]]=w[a[i]],c[nxt[now[a[i]]]]=-w[a[i]];
    //for(int i=1;i<=n;i++)printf("%d ",c[i]);puts("");
    build(1,n,1);
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        //for(int i=1;i<=n;i++)printf("%d ",c[i]);puts("");
        ans=max(ans,st[1].pre);
        //for(int i=1;i<=15;i++)printf("%lld ",st[i].pre);puts("");
        update(1,n,1,i,-c[i]);
        update(1,n,1,nxt[i],2*c[i]);
        update(1,n,1,nxt[nxt[i]],-c[i]);
        c[nxt[nxt[i]]]=c[nxt[i]],c[nxt[i]]=c[i],c[i]=0;
    }
    printf("%lld\n",ans);
    return 0;
}
/*
8 4
2 3 1 1 4 1 2 4
5 3 6 6
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1e5+5,S=65,mod=1e9+7;
int SIZE;
struct Q
{
    int l,r,id,block;
    void input(int i)
    {
        scanf("%d%d",&l,&r);
        id=i,block=l/SIZE;
    }
    bool operator < (const Q& b)const
    {
        if(block!=b.block)return block<b.block;
        return r<b.r;
    }
}que[maxn];
ll inv[maxn];
int a[maxn];
ll pw(ll a,int n)
{
    if(n==1)return a;
    ll ret=pw(a,n>>1);
    ret=ret*ret%mod;
    if(n&1)ret=ret*a%mod;
    return ret;
}
vector<int> p;
bool vis[maxn];
void prime()
{
    for(int i=2;i*i<maxn;i++)if(!vis[i])
    {
        p.push_back(i);
        for(int j=i*i;j<maxn;j+=i)vis[j]=1;
    }
}
struct P
{
    int a[S];
    P(){fill(a,a+S,1);}
}seg[maxn<<2];
P cal(P x,P y)
{
    P ret;
    for(int i=0;i<S;i++)
        ret.a[i]=max(x.a[i],y.a[i]);
    return ret;
}
void build(int l,int r,int o)
{
    if(l==r)
    {
        for(int i=0;i<S;i++)
            while(a[l]%p[i]==0)seg[o].a[i]*=p[i],a[l]/=p[i];
        return ;
    }
    int m=(l+r)>>1;
    build(l,m,o<<1);
    build(m+1,r,o<<1|1);
    seg[o]=cal(seg[o<<1],seg[o<<1|1]);
}
P query(int l,int r,int o,int ql,int qr)
{
    if(ql==l && r==qr)return seg[o];
    int m=(l+r)>>1;
    if(qr<=m)return query(l,m,o<<1,ql,qr);
    else if(ql>m)return query(m+1,r,o<<1|1,ql,qr);
    else return cal(query(l,m,o<<1,ql,m),query(m+1,r,o<<1|1,m+1,qr));
}
int pp[maxn],cnt[maxn];
ll ans[maxn],cur_ans=1;
void add(int x)
{
    if(!x)return ;
    if(!(cnt[x]++))cur_ans=cur_ans*x%mod;
}
void sub(int x)
{
    if(!x)return ;
    if(!(--cnt[x]))cur_ans=cur_ans*inv[x]%mod;
}
main()
{
    prime();
    for(int i=1;i<maxn;i++)if(!vis[i])inv[i]=pw(i,mod-2);
    int n,q;scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    build(1,n,1);
    for(int i=1;i<=n;i++)if(a[i]!=1)pp[i]=a[i];
    SIZE=(int)sqrt(n+0.5);
    for(int i=1;i<=q;i++)
    {
        que[i].input(i);
        ans[i]=1;
        P t=query(1,n,1,que[i].l,que[i].r);
        //for(int j=0;j<p.size();j++)printf("%d ",t.a[j]);puts("");
        for(int j=0;j<S;j++)ans[i]=ans[i]*t.a[j]%mod;
        //printf("%d\n",ans[i]);
    }
    sort(que+1,que+q+1);
    cur_ans=1;
    for(int i=1,L=1,R=0;i<=q;i++)
    {
        while(R<que[i].r)add(pp[++R]);
        while(L>que[i].l)add(pp[--L]);
        while(R>que[i].r)sub(pp[R--]);
        while(L<que[i].l)sub(pp[L++]);
        ans[que[i].id]=ans[que[i].id]*cur_ans%mod;
    }
    for(int i=1;i<=q;i++)printf("%lld\n",ans[i]);
    return 0;
}
/*
5 2
2 3 5 7 4
1 4
1 5
210
420
*/

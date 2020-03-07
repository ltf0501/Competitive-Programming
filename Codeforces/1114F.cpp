#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 400010
#define pll pair<ll,ll>
#define F first
#define S second
const int mod=1e9+7;
int p[305],id[305];
ll di[70];
vector<int> pr;
int n,q,a[maxn];
ll pw(ll a,int n)
{
    ll res=1;
    while(n)
    {
        if(n&1)res=res*a%mod;
        a=a*a%mod,n>>=1;
    }
    return res;
}
ll INV(ll a){return pw(a,mod-2);}
void pre()
{
    for(int i=2;i<=300;i++)
    {
        if(!p[i])pr.push_back(i);
        for(int j=0;j<(int)pr.size() && i*pr[j]<=300;j++)
        {
            p[i*pr[j]]=pr[j];
            if(i%pr[j]==0)break;
        }
    }
    for(int i=0;i<(int)pr.size();i++)
        di[i]=1ll*(pr[i]-1)*INV(pr[i])%mod;
}
ll seg[maxn<<2],cur[maxn<<2];
ll seg_tg[maxn<<2],cur_tg[maxn<<2];
ll ok[305];
ll cal(int x)
{
    if(x==1)return 0;
    if(ok[x])return ok[x];
    for(int i=0;i<(int)pr.size();i++)
        if(x%pr[i]==0)ok[x]|=(1ll<<i);
    return ok[x];
}
void push_down(int l,int r,int o)
{
    if(!cur_tg[o])return ;
    int m=(l+r)>>1;
    seg[o<<1]=seg[o<<1]*pw(seg_tg[o],m-l+1)%mod;
    seg[o<<1|1]=seg[o<<1|1]*pw(seg_tg[o],r-m)%mod;
    seg_tg[o<<1]=seg_tg[o<<1]*seg_tg[o]%mod;
    seg_tg[o<<1|1]=seg_tg[o<<1|1]*seg_tg[o]%mod;

    cur[o<<1]|=cur_tg[o],cur[o<<1|1]|=cur_tg[o];
    cur_tg[o<<1]|=cur_tg[o],cur_tg[o<<1|1]|=cur_tg[o];
    seg_tg[o]=1,cur_tg[o]=0;
}
void push_up(int o)
{
    seg[o]=seg[o<<1]*seg[o<<1|1]%mod;
    cur[o]=cur[o<<1]|cur[o<<1|1];
}
void build(int l,int r,int o)
{
    seg_tg[o]=1;
    if(l==r){seg[o]=a[l],cur[o]=cal(a[l]);return ;}
    int m=(l+r)>>1;
    build(l,m,o<<1),build(m+1,r,o<<1|1);
    push_up(o);
}
void update(int l,int r,int o,int ql,int qr,int x,ll xx)
{
    if(ql<=l && r<=qr)
    {
        seg[o]=seg[o]*pw(x,r-l+1)%mod;
        seg_tg[o]=seg_tg[o]*x%mod;
        cur[o]|=xx,cur_tg[o]|=xx;
        return ;
    }
    push_down(l,r,o);
    int m=(l+r)>>1;
    if(ql<=m)update(l,m,o<<1,ql,qr,x,xx);
    if(qr>m)update(m+1,r,o<<1|1,ql,qr,x,xx);
    push_up(o);
}
pll query(int l,int r,int o,int ql,int qr)
{
    if(ql<=l && r<=qr)return pll(seg[o],cur[o]);
    push_down(l,r,o);
    int m=(l+r)>>1;
    if(qr<=m)return query(l,m,o<<1,ql,qr);
    if(ql>m)return query(m+1,r,o<<1|1,ql,qr);
    pll res_l=query(l,m,o<<1,ql,qr);
    pll res_r=query(m+1,r,o<<1|1,ql,qr);
    return pll(res_l.F*res_r.F%mod,res_l.S|res_r.S);
}
ll get_ans(int l,int r)
{
    pll res=query(1,n,1,l,r);
    ll ans=res.F;
    for(int i=0;i<(int)pr.size();i++)
        if(res.S&(1ll<<i))ans=ans*di[i]%mod;
    return ans;
}
main()
{
    pre();
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    build(1,n,1);
    while(q--)
    {
        char c[10];
        scanf("%s",c);
        if(c[0]=='M')
        {
            int l,r,x;scanf("%d%d%d",&l,&r,&x);
            update(1,n,1,l,r,x,cal(x));
        }
        else
        {
            int l,r;scanf("%d%d",&l,&r);
            printf("%lld\n",get_ans(l,r));
        }
    }
    return 0;
}

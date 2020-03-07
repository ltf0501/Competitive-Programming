#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 1500000
const ll INF=1e18;
vector<ll> v;
ll pw(ll x,ll d)
{
    ll ret=1;
    while(d)
    {
        if(d&1)ret=ret*x;
        x=x*x;
        d>>=1;
    }
    return ret;
}
ll sqt(ll x)
{
    ll ret=(ll)pow(x,0.5);
    //printf("%lld %d %lld\n",x,d,ret);
    while(ret*ret>x)ret--;
    while(ret*ret<=x)ret++;
    return ret-1;
}
ll query(ll x)
{
    int s=upper_bound(v.begin(),v.end(),x)-v.begin();
    return s+sqt(x);
}
bool vis[maxn];
void pre()
{
    for(int i=2;i<maxn;i++)
    {
        if(vis[i])continue;
        ll sqr=1ll*i*i;
        ll x=i;
        while((double)INF/(double)sqr>=x)
        {
            x*=sqr;
            if(x<maxn)vis[x]=1;
            v.push_back(x);
        }
        x=1;
        while((double)maxn/(double)sqr>=x)
        {
            x*=sqr;
            if(x<maxn)vis[x]=1;
            else break;
        }
    }
    sort(v.begin(),v.end());
//    for(int i=0;i<100;i++)printf("%lld ",v[i]);
}

main()
{
    pre();
    int q;scanf("%d",&q);
    while(q--)
    {
        ll l,r;scanf("%lld%lld",&l,&r);
        printf("%lld\n",query(r)-query(l-1));
//        printf("%lld %lld\n",sqt(r),sqt(l-1));
    }
    return 0;
}

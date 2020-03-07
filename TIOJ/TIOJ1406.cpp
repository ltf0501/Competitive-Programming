#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
#define ll long long
ll a[maxn],s[maxn],sum;
int n;
bool check(ll k)
{
    ll cur=s[1];
    for(int i=1;i<n;i++)
    {
        ll d=cur-k;
        ll t=d-(a[i+1]-a[i]);
        if(d>=0)t=max(t,0ll);
        cur=s[i+1]+t;
    }
    return cur>=k;
}
main()
{
    while(~scanf("%d",&n))
    {
        sum=0;
        ll mi=1e12,mx=0ll;
        for(int i=1;i<=n;i++)scanf("%lld%lld",&a[i],&s[i]),mi=min(mi,s[i]),mx=max(mx,s[i]);
        ll l=mi,r=mx;
        if(!check(l)){puts("0");continue;}
        while(r-l>1)
        {
            ll m=(l+r)>>1;
            if(check(m))l=m;
            else r=m;
        }
        printf("%lld\n",l);
    }
    return 0;
}

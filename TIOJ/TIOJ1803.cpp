#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1e9+7,maxn=1e6+10;
ll f[maxn],invf[maxn];
ll mypow(ll a,int n)
{
    ll ret=1;
    while(n)
    {
        if(n&1)ret=ret*a%mod;
        n>>=1;
        a=a*a%mod;
    }
    return ret;
}
int n,k;
void init()
{
    f[0]=1,invf[0]=1;
    for(int i=1;i<=(int)1e6;i++)f[i]=f[i-1]*i%mod,invf[i]=mypow(f[i],mod-2);
    ///for(int i=1;i<=10;i++)printf("%lld ",f[i]);puts("");
    ///for(int i=1;i<=10;i++)printf("%lld ",invf[i]);puts("");
}
ll query(int n,int s)
{
    ll ret=f[n]*invf[n/s]%mod;
    ll t=mypow(s,n/s);
    ret=ret*mypow(t,mod-2)%mod;
    ///printf("%lld\n",t);
    ///printf("%d %lld\n",s,ret);
    return ret;
}
main()
{
    init();
    while(~scanf("%d%d",&n,&k))
    {
        ll ans=0;
        int g=__gcd(n,k);
        for(int i=2;i<=g;i++)if(g%i==0)
            ans=(ans+query(n,i))%mod;
        printf("%lld\n",ans);
    }
}

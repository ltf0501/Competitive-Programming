#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1e9+7;
ll pw(ll a,ll n)
{
    ll ret=1;
    while(n)
    {
        if(n&1)ret=ret*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return ret;
}
main()
{
    ll x,k;scanf("%lld%lld",&x,&k);
    if(!x)return 0*puts("0");
    x%=mod;
    printf("%lld\n",(1ll*x*pw(2,k+1)%mod-pw(2,k)+1+mod)%mod);
    return 0;
}

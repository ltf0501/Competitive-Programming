#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 1000010
const int mod=998244353;
ll fac[maxn],inv[maxn],dp[maxn];
ll pw(ll a,int n)
{
    ll ret=1;
    while(n)
    {
        if(n&1)ret=ret*a%mod;
        a=a*a%mod;n>>=1;
    }
    return ret;
}
ll INV(ll a){return pw(a,mod-2);}
void pre()
{
    fac[0]=1;
    for(int i=1;i<maxn;i++)fac[i]=fac[i-1]*i%mod;
    inv[maxn-1]=INV(fac[maxn-1]);
    for(int i=maxn-2;i>=0;i--)inv[i]=inv[i+1]*(i+1)%mod;
}
main()
{
    int n;scanf("%d",&n);
    pre();
    ll ans=fac[n];
    for(int i=1;i<=n;i++)dp[i]=fac[n]*inv[i]%mod;
    for(int i=1;i<n;i++)
    {
        dp[i]=(dp[i]-dp[i+1])%mod;
        if(dp[i]<0)dp[i]+=mod;
    }
    //for(int i=1;i<=n;i++)printf("%lld ",dp[i]);puts("");
    for(int i=1;i<=n-1;i++)ans=(ans+1ll*(n-1-i)*dp[i]%mod)%mod;
    printf("%lld\n",ans);
    return 0;
}

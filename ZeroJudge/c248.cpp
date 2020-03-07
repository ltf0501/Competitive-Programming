#include<bits/stdc++.h>
using namespace std;
#define maxn 2100000
#define ll long long
const int mod=1e9+7;
ll fac[maxn],inv[maxn];
ll pw(ll a,int n)
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
ll INV(ll a){return pw(a,mod-2);}
void pre()
{
    fac[0]=inv[0]=1;
    for(int i=1;i<maxn;i++)fac[i]=fac[i-1]*i%mod;
    inv[maxn-1]=INV(fac[maxn-1]);
    for(int i=maxn-2;i>=1;i--)inv[i]=inv[i+1]*(i+1)%mod;
}
ll C(int n,int m)
{
    return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
main()
{
    pre();
    int t;scanf("%d",&t);
    while(t--)
    {
        int n;scanf("%d",&n);
        printf("%lld\n",C(2*n,n)*INV(n+1)%mod);
    }
    return 0;
}

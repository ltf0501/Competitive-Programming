#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 2010
const int mod=998244353;
int n,m,k;
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
    fac[0]=1;
    for(int i=1;i<maxn;i++)fac[i]=fac[i-1]*i%mod;
    inv[maxn-1]=INV(fac[maxn-1]);
    for(int i=maxn-2;i>=0;i--)inv[i]=inv[i+1]*(i+1)%mod;
}
ll C(int n,int m)
{
    return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
main()
{
    pre();
    scanf("%d%d%d",&n,&m,&k);
    printf("%lld\n",1ll*C(n-1,k)%mod*m%mod*pw(m-1,k)%mod);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 100010
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
    fac[0]=1;
    for(int i=1;i<maxn;i++)fac[i]=fac[i-1]*i%mod;
    inv[maxn-1]=INV(fac[maxn-1]);
    for(int i=maxn-2;i>=0;i--)inv[i]=(i+1)*inv[i+1]%mod;
}
ll C(int n,int m){return fac[n]*(inv[m]*inv[n-m]%mod)%mod;}
main()
{
    pre();
    int t;scanf("%d",&t);
    while(t--)
    {
        int n,a,b;ll k;
        scanf("%d%d%d%lld",&n,&a,&b,&k);
        ll ans=0;
        for(int i=0;i<=n && 1ll*i*a<=k;i++)
        {
            int j;
            if((k-1ll*i*a)%b==0 && (j=(k-1ll*i*a)/b)<=n)ans=(ans+C(n,i)*C(n,j)%mod)%mod;
        }
        printf("%lld\n",ans);
    }
    return 0;
}


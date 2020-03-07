#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
#define ll long long
const ll mod=1e9+7;
ll fac[maxn],inv[maxn];
int n,k;
ll sum;
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
ll C(int n,int m)
{
    return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
ll S(int n,int k)
{
    if(k>n)return 0;
    ll ret=0;
    for(int i=k;i;i--)
    {
        ll t=C(k,i)*pw(i,n)%mod;
        if((k-i)&1)ret=(ret+mod-t)%mod;
        else ret=(ret+t)%mod;
    }
    return ret*inv[k]%mod;
}
main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        int x;scanf("%d",&x);
        sum=(sum+x)%mod;
    }
    fac[0]=1,inv[0]=1;
    for(int i=1;i<maxn;i++)fac[i]=fac[i-1]*i%mod;
    inv[maxn-1]=INV(fac[maxn-1]);
    for(int i=maxn-2;i>=1;i--)inv[i]=inv[i+1]*(i+1)%mod;
    ll ans=(S(n,k)+(n-1)*S(n-1,k)%mod)%mod;
    printf("%lld\n",sum*ans%mod);
    return 0;
}

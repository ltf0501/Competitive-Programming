#include<bits/stdc++.h>
using namespace std;
#define maxn 1000010
#define ll long long
const int mod=1e9+7;
ll fac[maxn],inv[maxn];
void add(ll &a,ll b)
{
    a+=b;
    if(a>=mod)a-=mod;
}
void sub(ll &a,ll b)
{
    a-=b;
    if(a<0)a+=mod;
}
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
    fac[0]=1;
    for(int i=1;i<maxn;i++)fac[i]=fac[i-1]*i%mod;
    inv[maxn-1]=INV(fac[maxn-1]);
    for(int i=maxn-2;i>=0;i--)inv[i]=inv[i+1]*(i+1)%mod;
}
ll C(int n,int m)
{
    if(n<m)return 0;
    return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
ll P(int n,int m)
{
    return fac[n]*inv[n-m]%mod;
}
ll f(int n,int m)
{
    if(n==m)return 1;
    return 1ll*m*pw(n,n-m-1)%mod;
}
main()
{
    pre();
    int n,m,a,b;scanf("%d%d%d%d",&n,&m,&a,&b);
    ll ans=0;
    for(int i=1;i<=min(m,n-1);i++)
        add(ans,1ll*C(m-1,i-1)*P(n-2,i-1)%mod*f(n,i+1)%mod*pw(m,n-1-i)%mod);
    printf("%lld\n",ans);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define maxn 300010
#define ll long long
const int mod=1e9+7;
int n;
ll dp[maxn];
int cnt[maxn];
ll fac[maxn],inv[maxn];
ll pw(ll a,int n)
{
    ll ret=1;
    while(n)
    {
        if(n&1)ret=ret*a%mod;
        n>>=1,a=a*a%mod;
    }
    return ret;
}
ll INV(ll a){return pw(a,mod-2);}
ll C(int n,int m)
{
    if(n<m)return 0;
    return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
void pre()
{
    for(int i=1;i<maxn;i++)
        for(int j=i*2;j<maxn;j+=i)cnt[i]+=cnt[j];
    fac[0]=1;
    for(int i=1;i<maxn;i++)fac[i]=fac[i-1]*i%mod;
    inv[maxn-1]=INV(fac[maxn-1]);
    for(int i=maxn-2;i>=0;i--)inv[i]=inv[i+1]*(i+1)%mod;
}
main()
{
    scanf("%d",&n);
    int g=0;
    for(int i=1;i<=n;i++)
    {
        int x;scanf("%d",&x);
        g=__gcd(g,x);
        cnt[x]++;
    }
    if(g!=1)return 0*puts("-1");
    pre();
    for(int i=1;;i++)
    {
        for(int j=300000;j>=1;j--)
        {
            dp[j]=C(cnt[j],i);
            for(int k=2;k*j<=300000;k++)dp[j]=(dp[j]-dp[k*j]+mod)%mod;
        }
        if(dp[1]>0)return 0*printf("%d\n",i);
    }
    return 0;
}

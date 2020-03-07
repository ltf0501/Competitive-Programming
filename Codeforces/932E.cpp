#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 5010
const int mod=1e9+7;
int n,k;
vector<ll> v,tmp;
ll inv2[maxn],g[maxn],f[maxn];
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
void init()
{
    inv2[0]=pw(2,n);
    ll t=pw(2,mod-2);
    for(int i=1;i<=min(n,k);i++)inv2[i]=inv2[i-1]*t%mod;
    g[0]=1;
    for(int i=1;i<=min(n,k);i++)g[i]=g[i-1]*(n-i+1)%mod;
    for(int i=1;i<=min(n,k);i++)f[i]=g[i]*inv2[i]%mod;
}
main()
{
    scanf("%d%d",&n,&k);
    init();
    v.push_back(1ll);
    for(int i=2;i<=k;i++)
    {
        tmp.clear();
        tmp.push_back(v[0]);
        int m=v.size();
        //printf("%d\n",m);
        for(int j=1;j<m;j++)
            tmp.push_back((v[j-1]+(j+1)*v[j])%mod);
        tmp.push_back(v[m-1]);
        v.clear();
        v=tmp;
        //for(ll s : v)printf("%lld ",s);puts("");
    }
    ll ans=0;
    //printf("%d\n",v.size());
    for(int i=0;i<v.size();i++)ans=(ans+v[i]*f[i+1]%mod)%mod;
    printf("%lld\n",ans);
    return 0;
}

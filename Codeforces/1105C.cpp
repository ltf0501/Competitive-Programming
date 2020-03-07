#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
#define ll long long
const int mod=1e9+7;
int n,l,r;
ll num[3];
ll a[maxn],b[maxn];
ll pre[maxn];
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
main()
{
    scanf("%d%d%d",&n,&l,&r);
    l--;
    num[0]=r/3-l/3;
    num[1]=(r+2)/3-(l+2)/3;
    num[2]=(r+1)/3-(l+1)/3;
    ll sum=num[0]+num[1]+num[2];
    //for(int i=0;i<3;i++)printf("%lld ",num[i]);puts("");
    ll ans=1;
    for(int i=1;i<=n;i++)ans=ans*sum%mod;
    ll t=(2*num[0]-num[1]-num[2])%mod;
    if(t<0)t+=mod;
    ll s=(num[0]*num[0]+num[1]*num[1]+num[2]*num[2]-num[0]*num[1]-num[1]*num[2]-num[2]*num[0])%mod;
    if(s<0)s+=mod;
    pre[0]=2,pre[1]=t;
    for(int i=2;i<=n;i++)
    {
        pre[i]=(t*pre[i-1]-s*pre[i-2])%mod;
        if(pre[i]<0)pre[i]+=mod;
    }
    //for(int i=1;i<=n;i++)printf("%lld ",pre[i]);puts("");
    ans=(ans+pre[n])%mod;
    ans=ans*INV(3)%mod;
    printf("%lld\n",ans);
    ///ans=((a+b+c)^n+(a+wb+w^2c)^n+(a+w^2b+wc)^n))/3
    return 0;
}

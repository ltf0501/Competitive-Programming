#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
#define ll long long
#define maxn 1000010
#define F first
#define S second
map<int,int> mp;
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
main()
{
    int n;scanf("%d",&n);
    int mx=0;
    ll fac=1;
    for(int i=1;i<=n;i++)
    {
        fac=fac*i%mod;
        int x;scanf("%d",&x);
        mx=max(mx,x);
        mp[x]++;
    }
    int cnt=0;
    ll ans=0;
    for(auto p : mp)
    {
        if(p.F==mx)break;
        ans=(ans+p.F*p.S%mod*fac%mod*pw(n-cnt,mod-2)%mod)%mod;
        cnt+=p.S;
    }
    printf("%lld\n",ans);
    return 0;
}

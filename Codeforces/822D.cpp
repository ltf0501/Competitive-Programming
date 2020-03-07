#include<bits/stdc++.h>
using namespace std;
#define maxn 5000010
#define ll long long
const int mod=1e9+7;
ll t,dp[maxn];
ll l,r;
bool vis[maxn];
vector<int> prime;
void gao()
{
    for(int i=2;i<=r;i++)
    {
        if(!vis[i])
        {
            prime.push_back(i);
            dp[i]=1ll*i*(i-1)/2%mod;
        }
        for(int j=0;i*prime[j]<=r && j<prime.size();j++)
        {
            vis[i*prime[j]]=1;
            dp[i*prime[j]]=(dp[i]+(1ll*prime[j]*(prime[j]-1)/2)%mod*i%mod)%mod;
            if(i%prime[j]==0)break;
        }
    }
}
main()
{
    scanf("%I64d%I64d%I64d",&t,&l,&r);
    gao();
    ll ans=0,tt=1;
    for(int i=l;i<=r;i++)
        ans=(ans+dp[i]*tt%mod)%mod,
        tt=tt*t%mod;
    //for(int i=1;i<=r;i++)printf("%I64d ",dp[i]);puts("");
    printf("%I64d\n",ans);
    return 0;
}

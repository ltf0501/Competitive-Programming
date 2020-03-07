#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[55],s[55];
bool dp[55][55];
int n,k;
bool check(ll x)
{
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(int i=1;i<=n;i++)for(int t=0;t<i;t++)
    {
        if(((s[i]-s[t])&x)==x)
        {
            for(int l=0;l<k;l++)
                if(dp[t][l])dp[i][l+1]=1;
        }
    }
    return dp[n][k];
}
main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]),s[i]=s[i-1]+a[i];
    ll ans=0;
    for(int i=55;i>=0;i--)
    {
        if(check(ans+(1ll<<i)))ans+=1ll<<i;
    }
    printf("%lld\n",ans);
    return 0;
}

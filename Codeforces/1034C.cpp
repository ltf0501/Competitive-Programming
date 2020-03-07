#include<bits/stdc++.h>
using namespace std;
#define maxn 1000010
#define ll long long
const int mod=1e9+7;
int p[maxn],num[maxn],num2[maxn];
ll s[maxn],dp[maxn];
bool ok[maxn];
main()
{
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%lld",&s[i]);
    for(int i=2;i<=n;i++)scanf("%d",&p[i]);
    for(int i=n;i>1;i--)s[p[i]]+=s[i];
    for(int i=1;i<=n;i++)
    {
        ll tmp=s[1]/__gcd(s[1],s[i]);
        if(tmp<=n)num[tmp]++;
    }
    for(int i=1;i<=n;i++)if(num[i])
        for(int j=i;j<=n;j+=i)num2[j]+=num[i];
    for(int i=1;i<=n;i++)ok[i]=(num2[i]>=i);
    //for(int i=1;i<=n;i++)if(ok[i])printf("%d ",i);puts("");
    dp[1]=1;
    for(int i=1;i<=n;i++)if(ok[i])
    {
        for(int j=2*i;j<=n;j+=i)if(ok[j])
            (dp[j]+=dp[i])%=mod;
    }
    ll ans=0;
    for(int i=1;i<=n;i++)if(ok[i])(ans+=dp[i])%=mod;
    printf("%lld\n",ans);
    return 0;
}

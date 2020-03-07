#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
#define maxn 505
#define ll long long
ll dp[maxn][maxn];

main()
{
    int n,k;scanf("%d%d",&n,&k);
    dp[0][0]=1;
    for(int i=0;i<n;i++)
        for(int j=0;j<=i;j++)
            for(int p=1;p+i<=n;p++)(dp[p+i][max(j,p)]+=dp[i][j])%=mod;
    ll ans=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n && i*j<k;j++)(ans+=dp[n][i]*dp[n][j])%=mod;
    printf("%lld\n",ans*2%mod);
    return 0;
}

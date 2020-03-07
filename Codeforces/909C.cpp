#include<bits/stdc++.h>
using namespace std;
#define maxn 5010
#define ll long long
const int mod=1e9+7;
char c[maxn];
int n;
ll dp[maxn][maxn];
main()
{
    scanf("%d\n",&n);
    for(int i=1;i<=n;i++)
        c[i]=getchar(),getchar();
    dp[1][0]=1;
    for(int i=2;i<=n;i++)
    {
        if(c[i-1]=='f')
        {
            for(int j=1;j<n;j++)dp[i][j]=dp[i-1][j-1];
        }
        else
        {
            ll sum=0;
            for(int j=n-1;j>=0;j--)
            {
                sum=(sum+dp[i-1][j])%mod;
                dp[i][j]=sum;
            }
        }
    }
    ll ans=0;
    for(int i=0;i<n;i++)ans=(ans+dp[n][i])%mod;
    printf("%I64d\n",ans);
    return 0;
}

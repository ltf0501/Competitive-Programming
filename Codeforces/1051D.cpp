#include<bits/stdc++.h>
using namespace std;
#define maxn 1010
#define ll long long
const int mod=998244353;
ll dp[maxn][maxn<<1][2];
int n,k;
main()
{
    scanf("%d%d",&n,&k);
    dp[1][1][0]=1,dp[1][2][1]=1;
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=k;j++)
        {
            dp[i][j][0]=(dp[i-1][j][0]+dp[i-1][j][1]+dp[i-1][j][1]+(j ? dp[i-1][j-1][0] : 0 ))%mod;
            dp[i][j][1]=((j ? dp[i-1][j-1][0] : 0)+dp[i-1][j][1]+(j>=2 ? dp[i-1][j-2][1] : 0)+(j ? dp[i-1][j-1][0] : 0))%mod;
        }
    }
    /*
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=k;j++)
        {
            for(int l=0;l<2;l++)printf("%lld ",dp[i][j][l]);printf("\t");
        }puts("");
    }
    */
    ll ans=0;
    for(int i=0;i<2;i++)(ans+=dp[n][k][i])%=mod;
    ans=ans*2%mod;
    printf("%lld\n",ans);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define maxn 5010
#define int long long
const int INF=1e16;
int a[maxn],sum[maxn];
int dp[maxn][maxn];
main()
{
    int n,m,k;scanf("%I64d%I64d%I64d",&n,&m,&k);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),sum[i]=sum[i-1]+a[i];
    for(int i=0;i<=n;i++)for(int j=0;j<=k;j++)dp[i][j]=-INF;
    dp[0][0]=0;
    for(int i=1;i<=n;i++)for(int j=0;j<=k;j++)
    {
        dp[i][j]=dp[i-1][j];
        if(i>=m && j>=1)
			dp[i][j]=max(dp[i][j],dp[i-m][j-1]+sum[i]-sum[i-m]);
		if(dp[i][j]<0)dp[i][j]=-INF;
    }
    printf("%I64d\n",dp[n][k]);
    return 0;
}

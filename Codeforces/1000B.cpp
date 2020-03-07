#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
int n,m,a[maxn];
int dp[2][maxn];
main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    a[n+1]=m;
    for(int i=1;i<=n+1;i++)
    {
        dp[0][i]=dp[0][i-1]+(i&1 ? a[i]-a[i-1] : 0);
        dp[1][i]=max(dp[0][i-1]+a[i]-a[i-1]-1,dp[1][i-1]+(i&1 ? 0 : a[i]-a[i-1]));
    }
    int ans=max(dp[0][n+1],dp[1][n+1]);
    printf("%d\n",ans);
    return 0;
}


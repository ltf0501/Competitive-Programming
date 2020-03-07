#include<cstdio>
#include<algorithm>
using namespace std;
#define maxn 10000000+5
char c[maxn];
int dp[2][maxn];
main()
{
    int n;scanf("%d",&n);
    scanf("%s",c+1);
    for(int i=1;i<=n;i++)
    {
        if(c[i]=='0')dp[0][i]=dp[0][i-1],dp[1][i]=min(dp[1][i-1]+1,dp[0][i]+1);
        if(c[i]=='1')dp[1][i]=dp[1][i-1],dp[0][i]=min(dp[0][i-1]+1,dp[1][i]+1);
    }
    printf("%d\n",min(dp[0][n]+1,dp[1][n]));
    return 0;
}

#include<cstdio>
#include<algorithm>
using namespace std;
#define inf 1<<30
int dp[5010][1010];//dp[i][j]表示前i隻選j對最小
int a[5010];
main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int k,n;
        scanf("%d %d",&k,&n);
        k+=8;
        for(int i=n;i>=1;i--)scanf("%d",&a[i]);
        for(int i=1;i<=n;i++)
        {
            dp[i][0]=0;
            for(int j=1;j<=k;j++)dp[i][j]=inf;
        }
        for(int i=3;i<=n;i++)
        {
            for(int j=1;j<=k;j++)
            {
                if(i>=3*j && dp[i-2][j-1]!=inf)
                    dp[i][j]=min(dp[i-1][j],dp[i-2][j-1]+(a[i]-a[i-1])*(a[i]-a[i-1]));
            }
        }
        printf("%d\n",dp[n][k]);
    }
    return 0;
}

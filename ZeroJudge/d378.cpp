#include<bits/stdc++.h>
using namespace std;
#define maxn 105
#define INF 1000000000
int dp[maxn];
int a[maxn];
int n,m;
main()
{
    int cas=0;
    while(~scanf("%d%d",&n,&m))
    {
        //for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)dp[i][j]=INF;
        dp[0]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)scanf("%d",&a[j]);
            if(i==1){for(int j=1;j<=m;j++)dp[j]=dp[j-1]+a[j];}
            else
            {
                dp[0]=INF;
                for(int j=1;j<=m;j++)dp[j]=min(dp[j-1],dp[j])+a[j];
            }
            //printf("%d\n",dp[m]);
        }
        printf("Case #%d :\n%d\n",++cas,dp[m]);
    }
    return 0;
}

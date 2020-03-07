#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define INF 2000000000
int dp[1<<16][20],t[20],ans;
main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&t[i]);
    for(int i=0;i<(1<<n);i++)
        for(int j=0;j<n;j++)dp[i][j]=INF;
    ans=INF;
    dp[0][0]=1;
    for(int i=1;i<(1<<n);i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i&(1<<j))
            {
                for(int k=0;k<n;k++)
                {
                    int s=dp[i^(1<<j)][k]+abs(k-j);
                    dp[i][j]=min(dp[i][j],((s-1)/t[j]+1)*t[j]);
                }
            }
        }
    }
    for(int i=0;i<n;i++)ans=min(ans,dp[(1<<n)-1][i]);
    printf("%d\n",ans);
    return 0;
}

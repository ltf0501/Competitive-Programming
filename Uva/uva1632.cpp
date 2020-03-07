# include<iostream>
# include<cstring>
# include<cstdio>
# include<algorithm>
using namespace std;
#define maxn 10000+10
#define inf 1<<30
int n;
int dp[maxn][maxn][2],x[maxn],t[maxn];


int main()
{
    while(scanf("%d",&n)==1)
    {
        for(int i=1;i<=n;i++)scanf("%d %d",&x[i],&t[i]);
        int ans=inf;
        for(int i=n;i>=0;i--)
        {
            for(int j=i+1;j<=n;j++)
            {
                dp[i][j][0]=inf;dp[i][j][1]=inf;
                ans=min(dp[i+1][j][0]+x[i+1]-x[i],dp[i+1][j][1]+x[j]-x[i]);
				if(ans<t[i])
                    dp[i][j][0]=min(ans,dp[i][j][0]);
				ans=min(dp[i][j-1][0]+x[j]-x[i],dp[i][j-1][1]+x[j]-x[j-1]);
				if(ans<t[j])
                    dp[i][j][1]=min(ans,dp[i][j][1]);
            }
        }
        ans=min(dp[1][n][0],dp[1][n][1]);
        if(ans==inf)printf("No solution\n");
        else printf("%d\n",ans);
    }
    return 0;
}


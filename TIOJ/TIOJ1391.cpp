#include<bits/stdc++.h>
using namespace std;
int ary[150][150], dp[150][150];
main()
{
	int n,ans,temp;
	while(~scanf("%d",&n))
	{
		for(int i=0;i<n;i++)
			for(int j=0;j<=i;j++)scanf("%d",&ary[i][j]);
		ans=-1;
		memset(dp,1,sizeof(dp));
		dp[0][0]=ary[0][0];
		for(int i=0;i<n-1;i++)
		{
			for(int j=0;j<=i;j++)
			{
				ans=max(ans,dp[i][j]);
				dp[i+1][j]=min(dp[i+1][j],max(dp[i][j],ary[i+1][j])+1);
				dp[i+1][j+1]=min(dp[i+1][j+1],max(dp[i][j],ary[i+1][j+1])+1);
			}
		}
		for(int j=0;j<=n-1;j++)
            ans=max(ans,dp[n-1][j]);
		printf("%d\n", ans);
	}
	return 0;
}

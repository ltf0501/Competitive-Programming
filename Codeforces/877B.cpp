#include<bits/stdc++.h>
using namespace std;
#define maxn 5010
char c[maxn];
int dp[maxn][3];
main()
{
    scanf("%s",c+1);
    int n=strlen(c+1);
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<3;j++)dp[i][j]=dp[i-1][j];
        if(c[i]=='a')
        {
            dp[i][0]++;
            dp[i][1]=max(dp[i][1],dp[i][0]);
            dp[i][2]=max(max(dp[i][2]+1,dp[i][1]),dp[i-1][1]+1);
        }
        else
        {
            dp[i][1]=max(dp[i][1]+1,dp[i][0]+1);
            dp[i][2]=max(dp[i][2],dp[i][1]);
        }
    }
    printf("%d\n",dp[n][2]);
    return 0;
}

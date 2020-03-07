#include<bits/stdc++.h>
using namespace std;
#define maxn 50000+5
int dp[3][maxn];
char c[maxn];
main()
{
    int n;
    while(~scanf("%d",&n))
    {
        scanf("%s",c);
        memset(dp,0,sizeof(dp));
        for(int i=n-1;i>=0;i--)
        {
            if(c[i]=='r')
            {
                dp[0][i]=1+dp[0][i+1];
                dp[1][i]=dp[1][i+1];
                dp[2][i]=dp[2][i+1];
            }
            if(c[i]=='g')
            {
                dp[0][i]=max(dp[0][i+1],dp[1][i+1]+1);
                dp[1][i]=dp[1][i+1]+1;
                dp[2][i]=dp[2][i+1];
            }
            if(c[i]=='b')
            {
                dp[0][i]=max(max(dp[0][i+1],dp[1][i+1]),dp[2][i+1]+1);
                dp[1][i]=max(dp[1][i+1],dp[2][i+1]+1);
                dp[2][i]=dp[2][i+1]+1;
            }
        }
        printf("%d\n",dp[0][0]);
    }
    return 0;
}

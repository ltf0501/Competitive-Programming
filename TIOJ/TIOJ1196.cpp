#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char g[15][15];
int dp[15][15];
int n;
main()
{
    while(scanf("%d",&n)==1)
    {
        for(int i=0;i<n;i++)scanf("%s",g[i]);
        memset(dp,-1,sizeof(dp));
        g[0][0]='0',g[n-1][n-1]='0';
        dp[0][0]=0;
        for(int i=1;i<n;i++)
        {
            if(g[0][i]=='X')break;
            dp[0][i]=dp[0][i-1]+(g[0][i]-'0');
        }
        for(int i=1;i<n;i++)
        {
            if(g[i][0]=='X')break;
            dp[i][0]=dp[i-1][0]+(g[i][0]-'0');
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(g[i][j]=='X')continue;
                if(dp[i][j-1]==-1 && dp[i-1][j]==-1)continue;
                dp[i][j]=max(dp[i-1][j],dp[i][j-1])+(g[i][j]-'0');
            }
        }
        /*
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)printf("%d ",dp[i][j]);
            puts("");
        }
        */
        if(dp[n-1][n-1]==-1)puts("X");
        else printf("%d\n",dp[n-1][n-1]);
    }
    return 0;
}
//plastic memory 1

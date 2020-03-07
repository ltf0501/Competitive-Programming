#include<bits/stdc++.h>
using namespace std;
#define maxn 1005
#define INF 0x3f3f3f3f
char c[4][maxn];
int a[4];
int dp[5][maxn][(1<<12)+1];
main()
{
    int n;scanf("%d",&n);
    for(int i=1;i<=4;i++)scanf("%d",&a[i]);
    for(int i=1;i<=4;i++)scanf("%s",c[i]+1);
    memset(dp,INF,sizeof(dp));
    dp[3][3][0]=0;
    for(int i=4;i<=n;i++)
    {
        for(int j=0;j<4;j++)for(int msk=0;msk<(1<<12);msk++)
        {
            if(c[j][i]=='.')
            {
                if(j)dp[j][i][msk>>1]=dp[j-1][i][msk];
                else dp[j][i][msk>>1]=dp[3][i-1][msk];
                continue;
            }

        }
    }
    return 0;
}

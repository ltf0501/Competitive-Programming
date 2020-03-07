#include<bits/stdc++.h>
using namespace std;
#define maxn 201
#define ll long long
ll dp[maxn][maxn];
void init()
{
    for(int i=0;i<=200;i++)dp[0][i]=1;
    for(int i=1;i<=200;i++)
    {
        for(int j=1;j<=200;j++)
        {
            dp[i][j]=dp[i][j-1];
            if(i>=j)dp[i][j]+=dp[i-j][j];
        }
    }
}
main()
{
    init();
    int n;
    while(~scanf("%d",&n))
    {
        printf("%lld\n",dp[n][n]);
    }
    return 0;
}

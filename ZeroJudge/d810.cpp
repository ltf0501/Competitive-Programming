#include<bits/stdc++.h>
using namespace std;
int dp[25][4];
void init()
{
    for(int i=0;i<=20;i++)dp[i][1]=1;
    dp[0][2]=dp[1][2]=1;
    for(int i=2;i<=20;i++)dp[i][2]=dp[i-1][2]+dp[i-2][2];
    dp[0][3]=dp[1][3]=1;
    dp[2][3]=2;
    for(int i=3;i<=20;i++)dp[i][3]=dp[i-1][3]+dp[i-2][3]+dp[i-3][3];
}
main()
{
    init();
    int t,k;
    while(~scanf("%d%d",&t,&k))
    {
        k=abs(k);
        printf("%d\n",dp[k][t]);
    }
    return 0;
}

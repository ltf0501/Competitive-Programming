#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[55];
void init()
{
    dp[1]=1,dp[2]=2;
    for(int i=3;i<=50;i++)
        dp[i]=dp[i-1]+dp[i-2];
}
main()
{
    init();
    int n;
    while(~scanf("%d",&n) && n)
        printf("%lld\n",dp[n]);
    return 0;
}

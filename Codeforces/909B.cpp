#include<bits/stdc++.h>
using namespace std;
int dp[105];
main()
{
    int n;scanf("%d",&n);
    dp[1]=1;dp[2]=2;
    for(int i=3;i<=n;i++)dp[i]=dp[i-2]+i;
    printf("%d\n",dp[n]);
    return 0;
}

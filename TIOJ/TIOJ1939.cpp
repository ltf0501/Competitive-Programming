#include<bits/stdc++.h>
using namespace std;
#define maxn 105
#define ll long long
const int mod=1e9+9;
ll dp[2][maxn];
main()
{
    dp[0][1]=0,dp[1][1]=1;
    for(int i=2;i<=100;i++)
    {
        dp[0][i]=(dp[0][i-1]+dp[1][i-1])%mod;
        dp[1][i]=(2*dp[0][i-1]+3*dp[1][i-1])%mod;
    }
    int t;scanf("%d",&t);
    while(t--)
    {
        int n;scanf("%d",&n);
        printf("%d\n",(dp[0][n]+dp[1][n])%mod);
    }
    return 0;
}

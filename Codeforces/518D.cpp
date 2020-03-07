#include<bits/stdc++.h>
using namespace std;
#define maxn 2000+5
double dp[maxn][maxn];
main()
{
    int n,t;
    double p;
    cin>>n>>p>>t;
    double q=1-p;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=t;j++)dp[i][j]=p*(1+dp[i-1][j-1])+q*dp[i][j-1];
    printf("%0.9lf\n",dp[n][t]);
    return 0;
}

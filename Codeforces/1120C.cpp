#include<bits/stdc++.h>
using namespace std;
#define maxn 5010
int n,a,b;
char c[maxn];
int dp[maxn][maxn],dp2[maxn];
main()
{
    scanf("%d%d%d",&n,&a,&b);
    scanf("%s",c);
    for(int i=0;i<n;i++)
        for(int j=0;j<i;j++)
            if(c[i]==c[j])dp[i][j]=dp[i-1][j-1]+1;
    dp2[0]=a;
    for(int i=1;i<n;i++)
    {
        dp2[i]=dp2[i-1]+a;
        for(int j=0;j<i;j++)
        {
            int x=min(i-j,dp[i][j]);
            dp2[i]=min(dp2[i],dp2[i-x]+b);
        }
    }
    printf("%d\n",dp2[n-1]);
    return 0;
}

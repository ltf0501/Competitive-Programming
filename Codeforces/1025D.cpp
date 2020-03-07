#include<bits/stdc++.h>
using namespace std;
#define maxn 705
bool ok[maxn][maxn];
int n,a[maxn];
bool dp[2][maxn][maxn];
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
    {
        if(a[i]>1)ok[i][i]=1;
        for(int j=i+1;j<=n;j++)
            if(__gcd(a[i],a[j])>1)ok[i][j]=ok[j][i]=1;
    }
    for(int i=1;i<=n;i++)dp[0][i][i]=dp[1][i][i]=1;
    for(int len=1;len<n;len++)
    {
        for(int i=1;i<=n;i++)
        {
            int j=i+len;
            if(j>n)break;
            for(int k=i+1;k<=j;k++)
                dp[0][i][j]|=(ok[i][k] && dp[1][i+1][k] && dp[0][k][j]);
            for(int k=i;k<j;k++)
                dp[1][i][j]|=(ok[k][j] && dp[1][i][k] && dp[0][k][j-1]);
        }
    }
    /*
    for(int i=1;i<=n;i++)
    {
        printf("%d :\n",i);
        for(int j=i+1;j<=n;j++)printf("%d ",dp[0][i][j]);puts("");
        for(int j=i+1;j<=n;j++)printf("%d ",dp[1][i][j]);puts("");
        puts("");
    }
    */
    if(dp[0][1][n] || dp[1][1][n])return 0*puts("YES");
    for(int i=2;i<n;i++)
        if(dp[1][1][i] && dp[0][i][n])return 0*puts("YES");
    puts("NO");
    return 0;
}

#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 105
int dp[maxn][maxn],a[maxn][maxn];
main()
{
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)scanf("%d",&a[i][j]);
    memset(dp,0,sizeof(dp));
    for(int i=n;i>=1;i--)
    {
        for(int j=1;j<=i;j++)
        {
            if(i==n)dp[i][j]=a[i][j];
            else dp[i][j]=max(dp[i+1][j],dp[i+1][j+1])+a[i][j];
        }
    }
    printf("%d\n",dp[1][1]);
    return 0;
}

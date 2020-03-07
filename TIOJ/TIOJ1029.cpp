#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 1000+5
int a[maxn],sum[maxn];
int dp[maxn][maxn];
main()
{
    int n;scanf("%d",&n);
    sum[0]=0;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),sum[i]=sum[i-1]+a[i];
    for(int i=1;i<=n;i++)dp[i][i]=a[i];
    for(int d=1;d<=n-1;d++)
    {
        for(int x=1,y=x+d;y<=n;x++,y++)
            dp[x][y]=(sum[y]-sum[x-1])-min(dp[x+1][y],dp[x][y-1]);
    }
    printf("%d %d\n",dp[1][n],sum[n]-dp[1][n]);
    return 0;
}

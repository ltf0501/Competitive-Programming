#include<cstdio>
#include<algorithm>
using namespace std;
#define maxn 1005
int w[maxn][maxn],dp[maxn][maxn],s[maxn][maxn];
int a[maxn];
main()
{
    int n,m;scanf("%d%d",&n,&m);
    for(int i=2;i<=n;i++)scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)w[i][j]=w[i][j-1]+a[j]-a[(i+j)>>1];
    for(int i=1;i<=n;i++)dp[1][i]=w[1][i];
    for(int i=2;i<=m;i++)
    {
        s[i][n+1]=n-1;
        for(int j=n;j>=i;j--)
        {
            dp[i][j]=2147483647;
            for(int k=s[i-1][j];k<=s[i][j+1];k++)if(dp[i][j]>dp[i-1][k]+w[k+1][j])
                dp[i][j]=dp[i-1][k]+w[k+1][j],s[i][j]=k;
        }
    }
    printf("%d\n",dp[m][n]);
    return 0;
}

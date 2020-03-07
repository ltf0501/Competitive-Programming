#include<bits/stdc++.h>
using namespace std;
#define maxn 1505
int sum[maxn][maxn];//0左上 1右上 2右下 3左下
int dp[4][maxn][maxn];
int a[maxn][maxn];
int c1[maxn][maxn];
int m,n,k;
void P0()
{
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];
}
void P1()
{
    for(int i=1;i<=m;i++)
        for(int j=n;j>=1;j--)
            sum[i][j]=sum[i-1][j]+sum[i][j+1]-sum[i-1][j+1]+a[i][j];
}
void P2()
{
    for(int i=m;i>=1;i--)
        for(int j=n;j>=1;j--)
            sum[i][j]=sum[i+1][j]+sum[i][j+1]-sum[i+1][j+1]+a[i][j];
}
void P3()
{
    for(int i=m;i>=1;i--)
        for(int j=1;j<=n;j++)
            sum[i][j]=sum[i+1][j]+sum[i][j-1]-sum[i+1][j-1]+a[i][j];
}
void DP()
{
    P3();
    for(int i=1;i<=m;i++)for(int j=1;j<=n;j++)
    {
        int t;
        if(i+k<=m+1 && j>=k)t=sum[i][j]-sum[i+k][j]-sum[i][j-k]+sum[i+k][j-k];
        else t=0;
        dp[3][i][j]=max(max(dp[3][i+1][j],dp[3][i][j-1]),t);
    }
    memset(sum,0,sizeof(sum));
    P2();
    for(int i=1;i<=m;i++)for(int j=1;j<=n;j++)
    {
        int t;
        if(i+k<=m+1 && j+k<=n+1)t=sum[i][j]-sum[i][j+k]-sum[i+k][j]+sum[i+k][j+k];
        else t=0;
        dp[2][i][j]=max(max(dp[2][i+1][j],dp[2][i][j+1]),t);
    }
    memset(sum,0,sizeof(sum));
    P1();
    for(int i=1;i<=m;i++)for(int j=1;j<=n;j++)
    {
        int t;
        if(i>=k && j+k<=n+1)t=sum[i][j]-sum[i-k][j]-sum[i][j+k]+sum[i-k][j+k];
        else t=0;
        dp[1][i][j]=max(max(dp[1][i-1][j],dp[1][i][j+1]),t);
    }
    memset(sum,0,sizeof(sum));
    P0();
    for(int i=1;i<=m;i++)for(int j=1;j<=n;j++)
    {
        int t;
        if(i>=k && j>=k)t=sum[i][j]-sum[i][j-k]-sum[i-k][j]+sum[i-k][j-k];
        else t=0;
        dp[0][i][j]=max(max(dp[0][i-1][j],dp[0][i][j-1]),t);
    }
}
void DP2()
{
    for(int i=1;i+k-1<=m;i++)for(int j=1;j+k-1<=n;j++)
        c1[i][i+k-1]=max(c1[i][i+k-1],sum[i+k-1][j+k-1]-sum[i-1][j+k-1]-sum[i+k-1][j-1]+sum[i-1][j-1]);
    for(int h=k+1;h<=m;h++)
    {
        for(int i=1;i+h-1<=m;i++)c1[i][i+h-1]=max(c1[i][i+h-2],c1[i+1][i+h-1]);
    }
}
void DP3()
{
    for(int i=1;i+k-1<=n;i++)for(int j=1;j+k-1<=m;j++)
        c1[i][i+k-1]=max(c1[i][i+k-1],sum[j+k-1][i+k-1]-sum[j-1][i+k-1]-sum[j+k-1][i-1]+sum[j-1][i-1]);
    for(int h=k+1;h<=m;h++)
    {
        for(int i=1;i+h-1<=n;i++)c1[i][i+h-1]=max(c1[i][i+h-2],c1[i+1][i+h-1]);
    }
}
main()
{
    scanf("%d%d%d",&m,&n,&k);
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)scanf("%d",&a[i][j]);
    DP();
    /*
    for(int s=0;s<=3;s++)
    {
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)printf("%d ",dp[s][i][j]);
            puts("");
        }
        puts("");
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)printf("%d ",c[i][j]);
        puts("");
    }
    */
    int ans=0;
    DP2();
    for(int l=1;l<m;l++)for(int r=l+1;r<m;r++)
        ans=max(ans,c1[1][l]+c1[l+1][r]+c1[r+1][m]);
    memset(c1,0,sizeof(c1));
    DP3();
    for(int l=1;l<n;l++)for(int r=l+1;r<n;r++)
            ans=max(ans,c1[1][l]+c1[l+1][r]+c1[r+1][n]);
    for(int i=1;i<m;i++)for(int j=1;j<n;j++)
        ans=max(ans,dp[0][i][j]+dp[1][i][j+1]+dp[3][i+1][n]),
        ans=max(ans,dp[3][i+1][j]+dp[2][i+1][j+1]+dp[0][i][n]),
        ans=max(ans,dp[0][i][j]+dp[3][i+1][j]+dp[1][m][j+1]),
        ans=max(ans,dp[1][i][j+1]+dp[2][i+1][j+1]+dp[0][m][j]);
    printf("%d\n",ans);

    return 0;
}

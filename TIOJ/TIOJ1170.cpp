#include<bits/stdc++.h>
using namespace std;
#define maxn 1000+5
#define INF 1000000000
int s[maxn];
int dp[maxn][maxn];
int h(int l,int m,int r)
{
    return (s[m]-s[l-1])*(s[r]-s[m]);
}
main()
{
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)fill(dp[i]+1,dp[i]+n+1,-INF);
    s[0]=0;
    for(int i=1;i<=n;i++)scanf("%d",&s[i]),s[i]+=s[i-1];
    for(int i=1;i<=n;i++)dp[i][i]=0;
    for(int d=1;d<n;d++)
    {
        for(int i=1;i+d<=n;i++)
        {
            int j=i+d;
            for(int k=i;k+1<=j;k++)dp[i][j]=max(dp[i][j],max(dp[i][k],dp[k+1][j])+h(i,k,j));
        }
    }
    /*
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)printf("%d ",dp[i][j]);
        puts("");
    }
    */
    printf("%d\n",dp[1][n]);
    return 0;
}

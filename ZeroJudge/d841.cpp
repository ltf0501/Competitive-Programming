#include<bits/stdc++.h>
using namespace std;
#define maxn 35
#define ll long long
ll dp[maxn][maxn];
int root[maxn][maxn],a[maxn];
int n;
int c[maxn],cnt=0;
void dfs(int l,int r)
{
    if(l>r)return ;
    if(l==r){printf("%d ",l);return ;}
    int m=root[l][r];
    printf("%d ",m);
    dfs(l,m-1),dfs(m+1,r);
}
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=0;i<=n+1;i++)for(int j=0;j<=n+1;j++)dp[i][j]=1;
    for(int i=1;i<=n;i++)root[i][i]=i,dp[i][i]=a[i];
    for(int k=1;k<n;k++)for(int i=1;i+k<=n;i++)for(int s=i;s<=i+k;s++)
    {
        if(dp[i][i+k]<dp[i][s-1]*dp[s+1][i+k]+a[s])
            dp[i][i+k]=dp[i][s-1]*dp[s+1][i+k]+a[s],root[i][i+k]=s;
    }
    /*
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)printf("%d ",root[i][j]);puts("");
    }
    */
    printf("%lld\n",dp[1][n]);
    dfs(1,n);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define maxn 2010
int pos[2][maxn];
int dp[maxn][maxn],cost1[maxn][maxn],cost2[maxn][maxn];
main()
{
    int n;scanf("%d",&n);
    for(int i=1;i<=2*n;i++)
    {
        int x;char c[2];
        scanf("%s %d",c,&x);
        if(c[0]=='B')pos[0][x]=i;
        else pos[1][x]=i;
    }
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
    {
        cost1[i][j]=cost1[i][j-1];
        cost2[j][i]=cost2[j][i-1];
        if(pos[0][i]<pos[1][j])cost1[i][j]++;
        else cost2[j][i]++;
    }
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
        dp[i][j]=min(dp[i-1][j]+cost1[i][j],dp[i][j-1]+cost2[j][i]);
    int ans=0;
    for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)
    {
        if(pos[0][i]>pos[0][j])ans++;
        if(pos[1][i]>pos[1][j])ans++;
    }
    printf("%d\n",ans+dp[n][n]);
    return 0;
}

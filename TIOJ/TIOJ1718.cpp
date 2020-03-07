#include<bits/stdc++.h>
using namespace std;
#define ll long long
int m,n,p;
int a[55][55],c[55][55];
ll dp[2][10005];
main()
{
    scanf("%d%d%d",&m,&n,&p);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=p;j++)scanf("%d%d",&a[i][j],&c[i][j]);
    }
    int cur=1;
    for(int i=1;i<=n;i++)
    {
        cur^=1;
        memset(dp[cur],0ll,sizeof(dp[cur]));
        for(int j=m;j>=0;j--)
        {
            dp[cur][j]=dp[cur^1][j];
            for(int k=1;k<=p;k++)
                if(j>=a[i][k])dp[cur][j]=max(dp[cur][j],dp[cur^1][j-a[i][k]]+c[i][k]);
        }
    }
    printf("%lld\n",dp[cur][m]);
    return 0;
}

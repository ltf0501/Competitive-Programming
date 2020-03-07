#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 3000+5
int g[maxn];
int dp[maxn];
int m,n;
main()
{

    scanf("%d%d",&m,&n);
    memset(dp,0,sizeof(dp));
    int ans=0;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&g[j]);
            dp[j]=max(0,max(dp[j],dp[j-1]))+g[j];
            ans=max(ans,dp[j]);
        }
    }
    printf("%d\n",ans);
    return 0;
}

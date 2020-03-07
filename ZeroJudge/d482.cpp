#include<bits/stdc++.h>
using namespace std;
#define maxn 105
int dp[maxn];
int a[maxn];
main()
{
    int n;
    while(~scanf("%d",&n))
    {
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                scanf("%d",&a[j]);
                dp[j]=max(dp[j],dp[j-1])+a[j];
            }
        }
        printf("%d\n",dp[n]);
    }
    return 0;
}

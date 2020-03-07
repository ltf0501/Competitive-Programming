#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 100+10
#define inf 2147483647
main()
{
    int t;scanf("%d",&t);
    int a[maxn],dp[maxn];
    while(t--)
    {
        memset(dp,0,sizeof(dp));
        int n;scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        for(int i=1;i<=n;i++)dp[i]=max(0,dp[i-1])+a[i];
        int ans=-inf;
        for(int i=1;i<=n;i++)ans=max(ans,dp[i]);
        printf("%d\n",ans);

    }
    return 0;
}

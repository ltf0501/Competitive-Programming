#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define INF 2147483647
#define maxn 100000+5
int a[maxn],dp[maxn],g[maxn];
main()
{
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)g[i]=INF;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int k=lower_bound(g+1,g+n+1,a[i])-g;
        dp[i]=k;
        g[k]=a[i];
        ans=max(ans,dp[i]);
    }
    printf("%d\n",ans);
    return 0;
}

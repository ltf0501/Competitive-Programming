#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 505
#define INF 10000000000
#define ll long long
ll a[maxn],g[maxn];
main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=n;i>=1;i--)scanf("%d",&a[i]);
        for(int i=1;i<=n;i++)g[i]=INF;
        ll ans=0;
        for(int i=1;i<=n;i++)
        {
            ll k=lower_bound(g+1,g+n+1,a[i])-g;
            while(g[k]==a[i])k++;
            ans=max(ans,k);
            //printf("%d ",dp[i]);
            g[k]=a[i];
        }
        printf("%lld\n",ans);
    }
    return 0;
}

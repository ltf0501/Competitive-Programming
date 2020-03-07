#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
#define ll long long
int a[maxn];
ll dp[maxn];
int n;
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    if(a[1]>0)return 0*puts("-1");
    for(int i=2;i<=n;i++)
    {
        if(a[i]-a[i-1]>=2)return 0*puts("-1");
        if(a[i]==a[i-1]+1)dp[i]=dp[i-1]+1;
        else dp[i]=dp[i-1]+a[i];
    }
    printf("%lld\n",dp[n]);
    return 0;
}

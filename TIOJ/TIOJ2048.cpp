#include<bits/stdc++.h>
using namespace std;
#define maxn 1000010
#define ll long long
int n;
int a[maxn];
ll dp1[maxn],dp2[maxn];
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    dp1[1]=a[1];
    for(int i=2;i<=n;i++)dp1[i]=max({(ll)a[i],dp1[i-1],a[i]+dp1[i-1]});
    dp2[3]=a[1]+a[3];
    ll ans=dp2[3];
    for(int i=4;i<=n;i++)dp2[i]=max(dp2[i-1],dp1[i-2])+a[i],ans=max(ans,dp2[i]);
    printf("%lld\n",ans);
    return 0;
}

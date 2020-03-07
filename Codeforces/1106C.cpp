#include<bits/stdc++.h>
using namespace std;
#define maxn 300010
#define ll long long
int n,a[maxn];
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    ll ans=0;
    for(int i=1;i<=n/2;i++)ans+=1ll*(a[i]+a[n-i+1])*(a[i]+a[n-i+1]);
    printf("%lld\n",ans);
    return 0;
}

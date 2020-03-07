#include<bits/stdc++.h>
using namespace std;
#define ll long long
main()
{
    int n;scanf("%d",&n);
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        ll a;scanf("%lld",&a);
        ans=__gcd(ans,a);
    }
    printf("%lld\n",ans);
    return 0;
}

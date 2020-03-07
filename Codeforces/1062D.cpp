#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
#define ll long long
int n;
main()
{
    scanf("%d",&n);
    ll ans=0;
    for(int l=2,r;l<=n;l=r+1)
    {
        r=n/(n/l);
        ll a=n/l;
        ans+=(1ll*a*(a+1)/2-1)*(r-l+1);
    }
    printf("%lld\n",ans*4);
    return 0;
}

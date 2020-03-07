#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,h;
main()
{
    scanf("%lld%lld",&n,&h);
    if(h>(ll)(2*1e9) || (h<=(ll)(2*1e9) && h*(h+1)/2>=n))
    {
        ll k=((ll)sqrt(8*n+1)-1)/2;
        ll ans=k;
        if(k*(k+1)/2!=n)ans++;
        printf("%lld\n",ans);
        return 0;
    }
    ll k=(ll)sqrt(n+h*(h-1)/2);
    ll t=k*(k+1)/2+(k-h)*(k+h-1)/2;
    ll ans=k+k-h;
    if((n-t)%k==0)printf("%lld\n",ans+(n-t)/k);
    else printf("%lld\n",ans+(n-t)/k+1);
    return 0;
}

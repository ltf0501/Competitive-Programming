#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a,b,x,y;
main()
{
    scanf("%lld%lld%lld%lld",&a,&b,&x,&y);
    ll g=__gcd(x,y);
    x/=g,y/=g;
    ll num=min(a/x,b/y);
    printf("%lld\n",num);
    return 0;
}

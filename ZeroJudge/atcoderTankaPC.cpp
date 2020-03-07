#include<bits/stdc++.h>
using namespace std;
#define ll long long
main()
{
    ll n;scanf("%lld",&n);
    for(ll a=1;a<=3500;a++)for(ll b=a;b<=3500;b++)
    {
        ll p=n*a*b,q=4*a*b-n*a-n*b;
        if(q>0 && p%q==0){printf("%lld %lld %lld",a,b,p/q);return 0;}
    }
    return 0;
}


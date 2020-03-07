#include<bits/stdc++.h>
using namespace std;
#define ll long long
main()
{
    ll n,k;scanf("%lld%lld",&n,&k);
    if(k>=43)return 0*puts("No");
    ll lcm=1;
    for(int i=1;i<=k;i++)lcm=lcm/__gcd(lcm,1ll*i)*i;
    puts((n+1)%lcm==0 ? "Yes" : "No");
    return 0;
}

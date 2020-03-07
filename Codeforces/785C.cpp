#include<bits/stdc++.h>
using namespace std;
#define ll long long
main()
{
    ll m,n;scanf("%I64d%I64d",&m,&n);
    if(m<=n){printf("%I64d\n",m);return 0;}
    ll k=m-n;
    ll l=1,r=2000000000;
    while(r>l)
    {
        ll mid=l+(r-l)/2;
        ll ans=mid*(mid+1)/2;
        if(ans<k)l=mid+1;
        else r=mid;
    }
    printf("%I64d\n",n+l);
    return 0;
}

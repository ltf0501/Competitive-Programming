#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll p,q,b;
main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        scanf("%lld%lld%lld",&p,&q,&b);
        p%=q;
        ll g=__gcd(p,q);
        p/=g,q/=g;
        while(q!=1 && b!=1)
        {
            //printf("%lld %lld\n",q,b);
            ll d=__gcd(q,b);
            q/=d,b=d;
        }
        if(q==1)puts("Finite");
        else puts("Infinite");
    }
    return 0;
}
/*
249886636138706567 863798980712890625 156039876781250000

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a,b;
main()
{
    scanf("%lld%lld",&a,&b);
    bool rev=0;
    while(a&&b)
    {
        if(a<b)swap(a,b),rev^=1;
        if(a>=2*b)a-=(a/(2*b))*(2*b);
        else break;
    }
    if(rev)swap(a,b);
    printf("%lld %lld\n",a,b);
    return 0;
}

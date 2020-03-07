#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,x,y;
main()
{
    scanf("%lld%lld%lld",&n,&x,&y);
    if(x>y)swap(x,y);
    x--,y--;
    ll a=y;
    x=n-1-x,y=n-1-y;
    if(x>y)swap(x,y);
    ll b=y;
    //printf("%lld %lld\n",a,b);
    if(a<=b)puts("White");
    else puts("Black");
    return 0;
}


#include<bits/stdc++.h>
using namespace std;
#define ll long long
main()
{
    ll l,r,x,y,k;scanf("%I64d%I64d%I64d%I64d%I64d",&l,&r,&x,&y,&k);
    bool flag=0;
    for(ll i=x;i<=y;i++)
    {
        if(l<=i*k && i*k<=r){flag=1;break;}
    }
    puts(flag ? "YES" : "NO");
    return 0;
}


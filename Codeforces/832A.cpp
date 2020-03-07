#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k;
main()
{
    scanf("%I64d%I64d",&n,&k);
    ll s=n/k;
    if(s%2==1)puts("YES");
    else puts("NO");
    return 0;
}

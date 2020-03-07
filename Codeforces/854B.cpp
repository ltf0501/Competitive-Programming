#include<bits/stdc++.h>
using namespace std;
#define ll long long
main()
{
    ll n,k;scanf("%I64d%I64d",&n,&k);
    ll mi,mx;
    if(k==0 || k==n){puts("0 0");return 0;}
    mi=1;
    if(3*k<=n)mx=2*k;
    else mx=n-k;
    printf("%I64d %I64d\n",mi,mx);
    return 0;
}

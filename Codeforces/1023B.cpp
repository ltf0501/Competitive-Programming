#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k;
main()
{
    scanf("%lld%lld",&n,&k);
    if(k>=2*n)return 0*puts("0");
    if(k>=n+1)return 0*printf("%lld\n",(2*n-k+1)/2);
    printf("%lld\n",(k-1)/2);
    return 0;
}

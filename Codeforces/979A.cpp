#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
main()
{
    scanf("%lld",&n);
    n++;
    if(n==1)return 0*puts("0");
    if(n&1)return 0*printf("%lld\n",n);
    printf("%lld\n",n/2);
    return 0;
}


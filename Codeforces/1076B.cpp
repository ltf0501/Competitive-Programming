#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
main()
{
    scanf("%lld",&n);
    if(n%2==0)return 0*printf("%lld\n",n/2);
    ll p=n;
    for(int i=3;1ll*i*i<=n;i+=2)
        if(n%i==0){p=i;break;}
    n-=p;
    //printf("%lld\n",n);
    printf("%lld\n",1+n/2);

    return 0;
}

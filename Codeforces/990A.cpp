#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
int a,b;
main()
{
    scanf("%lld%lld%d%d",&n,&m,&a,&b);
    ll k=n%m;
    if(k==0)return 0*puts("0");
    ll ans=min(a*(m-k),b*k);
    printf("%lld\n",ans);
    return 0;
}


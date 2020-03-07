#include<bits/stdc++.h>
using namespace std;
#define ll long long
main()
{
    ll a,b;scanf("%I64d%I64d",&a,&b);
    int ans=1;
    if(b-a>=5)ans=0;
    else
    {
        for(ll i=a+1;i<=b;i++)ans*=(i%10);
    }
    ans%=10;
    printf("%d\n",ans);
    return 0;
}

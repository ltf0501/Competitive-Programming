#include<bits/stdc++.h>
using namespace std;
#define ll long long
main()
{
    ll n;int q;
    scanf("%lld%d",&n,&q);
    while(q--)
    {
        ll nn=n;
        ll x;scanf("%lld",&x);
        if(x%2==1){printf("%lld\n",(x+1)/2);continue;}
        ll ans=0,cnt=0;
        while(x%2==0)
        {
            ans+=x/2;
            nn-=x/2-1;
            x=(--nn);
            cnt++;
        }
        ans+=(x+1)/2;
        printf("%lld\n",ans);
    }
    return 0;
}

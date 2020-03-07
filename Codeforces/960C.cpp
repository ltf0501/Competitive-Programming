#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll X,d;
vector<ll> ans;
main()
{
    scanf("%lld%lld",&X,&d);
    ll cur=1;
    while(X)
    {
        for(int i=30;i>=0;i--)
        {
            if(X>=(1ll<<i)-1)
            {
                for(int j=0;j<i;j++)ans.push_back(cur);
                cur+=d;
                X-=(1ll<<i)-1;
                break;
            }
        }
    }
    printf("%d\n",ans.size());
    for(ll s : ans)printf("%lld ",s);
    return 0;
}

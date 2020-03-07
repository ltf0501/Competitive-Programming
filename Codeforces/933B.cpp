#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> v;
ll p;int k;
ll _ceil(ll a,ll b)
{
    if(a<0)return a/b;
    if(a%b==0)return a/b;
    return a/b+1;
}
main()
{
    scanf("%lld%d",&p,&k);
    ll now=p;
    while(now>=k || now<0)
    {
        ll tmp=_ceil(-now,k);
        //printf("%lld\n",tmp);
        v.push_back(tmp*k+now);
        now=tmp;
    }
    v.push_back(now);
    printf("%d\n",v.size());
    for(ll s : v)printf("%lld ",s);
    return 0;
}

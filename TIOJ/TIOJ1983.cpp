#include<bits/stdc++.h>
#include "lib1983.h"
using namespace std;
#define ll long long
set<ll> s;
ll ans[100010],k,n;
ll get(ll l,ll r)
{
    ll L=l,R=r;
    while(L<R)
    {
        ll m=(L+R)/2;
        if(Ask(m,m+1))R=m;
        else L=m+1;
    }
    return L;
}
main()
{
    n=Init();
    k=get(0,n-1);
    s.insert(k);
    bool flag=1;
    while(flag)
    {
        flag=0;
        vector<ll> v;
        ll tmp=0;
        for(auto t : s)
        {
            k=get(tmp,t);
            if(k!=tmp && k!=t)
            {
                flag=1;
                v.push_back(k);
            }
            tmp=t;
        }
        k=get(tmp,n-1);
        if(k!=tmp && k!=n-1)
        {
            flag=1;
            v.push_back(k);
        }
        for(auto t : v)s.insert(t);
    }
    int now=0;
    for(auto t : s)ans[now++]=t;
    Answer(now,ans);
    return 0;
}

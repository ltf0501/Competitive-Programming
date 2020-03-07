#include<bits/stdc++.h>
using namespace std;
#define maxn 400010
#define ll long long
const int mod=1e9+7;
set<int> s;
main()
{
    int q;scanf("%d",&q);
    int lo=0,hi=1e9;
    s.insert(lo),s.insert(hi);
    ll ans=1;
    while(q--)
    {
        char c[10];int x;
        scanf("%s %d",c,&x);
        if(c[1]=='D')s.insert(x);
        else
        {
            if(x<lo || x>hi)return 0*puts("0");
            if(lo<x && x<hi)ans=ans*2%mod;
            auto it=s.find(x);
            lo=*prev(it),hi=*next(it);
            s.erase(it);
        }
    }
    int num=0;
    for(auto it=s.find(lo);it!=s.find(hi);it++)num++;
    ans=ans*num%mod;
    printf("%lld\n",ans);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define ll long long
main()
{
    int q;scanf("%d",&q);
    while(q--)
    {
        ll k;int x;scanf("%lld%d",&k,&x);
        ll ans=9*(k-1)+x;
        printf("%lld\n",ans);
    }
    return 0;
}


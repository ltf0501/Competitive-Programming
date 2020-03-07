#include<bits/stdc++.h>
using namespace std;
#define ll long long
main()
{
    int n;ll h;
    scanf("%d %lld",&n,&h);
    int cnt=0;
    ll now=h;
    bool flag=1;
    while(n--)
    {
        ll s;scanf("%lld",&s);
        if(!flag)continue;
        if(h<=s){flag=0;continue;}
        if(now<=s)now=h-s,cnt++;
        else now-=s;
    }
    if(!flag)puts("-1");
    else printf("%d\n",cnt);
    return 0;
}

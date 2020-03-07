#include<bits/stdc++.h>
using namespace std;
#define ll long long
map<int,int> mp;
main()
{
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x,c;scanf("%d%d",&x,&c);
        mp[x]=max(mp[x],c);
    }
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x,c;scanf("%d%d",&x,&c);
        mp[x]=max(mp[x],c);
    }
    ll ans=0;
    for(auto s : mp)ans+=s.second;
    printf("%lld\n",ans);
    return 0;
}

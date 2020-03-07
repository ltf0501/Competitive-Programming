#include<bits/stdc++.h>
using namespace std;
#define maxn 300010
#define ll long long
#define F first
#define S second
int a[maxn];
vector<int> v[2];
map<int,int> mp;
main()
{
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x;scanf("%d",&x);
        a[i]=a[i-1]^x;
    }
    ll ans=0;
    for(int i=0;i<=n;i++)v[(i&1)^1].push_back(a[i]);
    for(int i=0;i<2;i++)
    {
        mp.clear();
        for(int j : v[i])mp[j]++;
        for(auto tmp : mp)
        {
            ans+=1ll*tmp.S*(tmp.S-1)/2;
        }
    }
    printf("%lld\n",ans);
    return 0;
}

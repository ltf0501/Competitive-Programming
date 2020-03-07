#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
#define ll long long
int n;
map<int,int> mp;
main()
{
    scanf("%d",&n);
    ll sum=0;
    long double ans=0.0;
    for(int i=0;i<n;i++)
    {
        int x;scanf("%d",&x);
        ans+=(ll)i*(ll)x-sum;
        sum+=x;
        if(mp.find(x-1)!=mp.end())ans-=mp[x-1];
        if(mp.find(x+1)!=mp.end())ans+=mp[x+1];
        mp[x]++;
    }
    cout<<fixed<<setprecision(0)<<ans<<'\n';
    return 0;
}

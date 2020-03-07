#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
#define ll long long
#define S second
map<int,int> mp;
int n,k;
main()
{
    scanf("%d%d",&n,&k);
    int MX=(1<<k)-1;
    ll ans=1ll*n*(n+1)/2;
    mp[0]=1;
    int cur=0;
    for(int i=1;i<=n;i++)
    {
        int x;scanf("%d",&x);
        cur^=x;
        if(cur&1)mp[cur^MX]++;
        else mp[cur]++;
    }
    for(auto s : mp)
    {
        //printf("%d\n",s.S);
        int p=s.S/2,q=(s.S+1)/2;
        ans-=1ll*p*(p-1)/2+1ll*q*(q-1)/2;
    }
    printf("%lld\n",ans);
    return 0;
}

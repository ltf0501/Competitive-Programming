#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 300010
int a[maxn];
int n;
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        ll x;scanf("%lld",&x);
        a[i]=__builtin_popcountll(x);
    }
    ll ans=0;
    int cur=0;
    int cnt[2]={1,0};
    for(int i=n;i;i--)
    {
        int sum=0,mx=0;
        cur+=a[i];
        ans+=(cnt[cur&1]++);
        for(int j=i;j<=n && j<=i+63;j++)
        {
            sum+=a[j],mx=max(mx,a[j]);
            if(2*mx>sum && sum%2==0)ans--;
        }
    }
    printf("%lld\n",ans);
    return 0;
}

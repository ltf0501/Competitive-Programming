#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
#define ll long long
ll n,x,k;
ll a[maxn];
main()
{
    scanf("%I64d%I64d%I64d",&n,&x,&k);
    for(int i=1;i<=n;i++)scanf("%I64d",&a[i]);
    sort(a+1,a+n+1);
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        ll s=(a[i]%x!=0) ? a[i]/x+1 : a[i]/x;
        int t1=lower_bound(a+1,a+n+1,max(a[i],(ll)x*(ll)(s+k-1)))-a;
        int t2=lower_bound(a+1,a+n+1,max(a[i],(ll)x*(ll)(s+k)))-a;
        ans+=(ll)(t2-t1);
    }
    printf("%I64d\n",ans);
    return 0;
}

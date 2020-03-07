#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
#define ll long long
ll a[maxn],b[maxn];
main()
{
    int n,k;scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%lld%lld",&a[i],&b[i]);
    ll ans=0;
    for(int i=1;i<=n;i++)if((k|a[i])==k)ans+=b[i];
    for(int i=0;i<=30;i++)if(k>>i&1)
    {
        ll t=((ll)k>>(i+1))*(1ll<<(i+1))+(1ll<<i)-1;
        //printf("%d\n",t);
        ll tmp=0;
        for(int i=1;i<=n;i++)if((t|a[i])==t)tmp+=b[i];
        ans=max(ans,tmp);
    }
    printf("%lld\n",ans);

    return 0;
}

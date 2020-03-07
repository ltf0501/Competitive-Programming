#include<bits/stdc++.h>
using namespace std;
#define ll long long
main()
{
    int n,k,a,b;scanf("%d%d%d%d",&n,&k,&a,&b);
    if(k==1)return 0*printf("%lld\n",1ll*(n-1)*a);
    ll ans=0;
    while(n>1)
    {
        if(n<k){ans+=1ll*(n-1)*a;break;}
        int t=n%k;n-=t;ans+=1ll*t*a;
        ans+=min(1ll*b,1ll*(n-n/k)*a);n/=k;
    }
    printf("%lld\n",ans);
    return 0;
}

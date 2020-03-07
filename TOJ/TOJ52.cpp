#include<bits/stdc++.h>
using namespace std;
#define maxn 2000010
#define ll long long
ll s[maxn];
int n;
ll k;
bool check(ll m)
{
    for(int i=1;i<=n;i++)
        if(s[i+m-1]-s[i-1]>=k)return 1;
    return 0;
}
main()
{
    scanf("%d%lld",&n,&k);
    for(int i=1;i<=n;i++)scanf("%lld",&s[i]),s[i]+=s[i-1];
    for(int i=n+1;i<=2*n-1;i++)s[i]=s[i-n]+s[n];
    //for(int i=1;i<=2*n-1;i++)printf("%d ",s[i]);puts("");
    ll ans=0;
    ll t=k/s[n];
    k-=s[n]*t,ans+=n*t;
    ll l=0,r=n;
    while(r-l>=1)
    {
        ll m=(l+r)/2;
        if(check(m))r=m;
        else l=m+1;
    }
    printf("%lld\n",ans+l);
    return 0;
}

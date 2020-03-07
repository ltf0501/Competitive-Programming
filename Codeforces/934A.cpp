#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
int a[55],b[55];
ll mx(ll a,ll b,ll c,ll d)
{
    ll ret=max(a,max(b,max(c,d)));
    return ret;
}
ll mi(ll a,ll b,ll c,ll d)
{
    ll ret=min(a,min(b,min(c,d)));
    return ret;
}
main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=m;i++)scanf("%d",&b[i]);
    sort(a+1,a+n+1);
    sort(b+1,b+m+1);
    ll t1=mx(1ll*a[2]*b[1],1ll*a[2]*b[m],1ll*a[n]*b[1],1ll*a[n]*b[m]);
    ll t2=mx(1ll*a[1]*b[1],1ll*a[1]*b[m],1ll*a[n-1]*b[1],1ll*a[n-1]*b[m]);
    ll ans=min(t1,t2);
    printf("%I64d\n",ans);
    return 0;
}

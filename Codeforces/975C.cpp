#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 200010
ll a[maxn];
int n,q;
ll sum=0;
int query(ll k)
{
    sum+=k;
    if(sum>=a[n])sum=0;
    int l=0,r=n;
    while(l<r-1)
    {
        int m=(l+r)>>1;
        if(a[m]<=sum)l=m;
        else r=m;
    }
    return n-l;
}
main()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        a[i]+=a[i-1];
    }
    while(q--)
    {
        ll x;scanf("%lld",&x);
        printf("%d\n",query(x));
    }
    return 0;
}

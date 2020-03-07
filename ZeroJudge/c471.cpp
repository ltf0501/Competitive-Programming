#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
#define ll long long
struct P
{
    int x,y;
    bool operator < (const P& b)const
    {
        return x*b.y<b.x*y;
    }
}a[maxn];
int sum[maxn];
main()
{
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i].x);
    for(int i=1;i<=n;i++)scanf("%d",&a[i].y);
    sort(a+1,a+n+1);
    for(int i=1;i<n;i++)sum[i]=sum[i-1]+a[i].x;
    ll ans=0;
    for(int i=2;i<=n;i++)ans+=(ll)sum[i-1]*(ll)a[i].y;
    printf("%lld\n",ans);
    return 0;
}

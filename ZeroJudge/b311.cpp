#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
#define ll unsigned long long
#define mod (int)(1e9+7)
struct P
{
    ll d,t;
    bool operator < (const P& b)const{return d*b.t<b.d*t;}
};
P a[maxn];
main()
{
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%llu%llu",&a[i].d,&a[i].t);
    sort(a+1,a+n+1);
    ll ans=0;
    for(int i=1;i<=n;i++)ans=(ans+a[i].d+a[i].t*ans)%mod;
    printf("%llu\n",ans);
    return 0;
}

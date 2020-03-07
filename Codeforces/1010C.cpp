#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
#define ll long long
int n,k;
int a[maxn];
set<ll> s;
main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    int g=0;
    for(int i=1;i<=n;i++)g=__gcd(g,a[i]);
    for(int i=0;i<k;i++)s.insert(1ll*g*i%k);
    printf("%d\n",s.size());
    for(ll v : s)printf("%lld ",v);
    return 0;
}

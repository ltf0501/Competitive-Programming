#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
#define ll long long
int l[maxn],r[maxn];
main()
{
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d%d",&l[i],&r[i]);
    sort(l,l+n+1,greater<int>());
    sort(r,r+n+1);
    ll ans=0;
    for(int i=0;i<=n;i++)ans+=2*max(0,l[i]-r[i]);
    printf("%lld\n",ans);
    return 0;
}

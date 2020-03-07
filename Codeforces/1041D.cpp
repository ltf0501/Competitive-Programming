#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 200010
#define pii pair<int,int>
#define F first
#define S second
const ll INF=1e18;
int n,h;
pii a[maxn];
ll s[maxn];
main()
{
    scanf("%d%d",&n,&h);
    for(int i=1;i<=n;i++)scanf("%d%d",&a[i].F,&a[i].S);
    sort(a+1,a+n+1);
    for(int i=1;i<n;i++)s[i]=s[i-1]+a[i+1].F-a[i].S;
    s[n]=INF;
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        int k=lower_bound(s+i,s+n+1,s[i-1]+h)-s;
		if(s[k]-s[i-1]>=h)k--;
		ans=max(ans,h-(s[k]-s[i-1])+a[k+1].S-a[i].F);
    }
    printf("%lld\n",ans);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define maxn 2010
#define ll long long
const ll INF=1e14;
int n,k,p;
int a[maxn],b[maxn];
main()
{
    scanf("%d%d%d",&n,&k,&p);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=k;i++)scanf("%d",&b[i]);
    sort(a+1,a+n+1);
    sort(b+1,b+k+1);
    ll ans=INF;
    for(int i=0;i+n<=k;i++)
    {
        ll tmp=0;
        for(int j=1;j<=n;j++)tmp=max(tmp,0ll+abs(a[j]-b[i+j])+abs(b[i+j]-p));
        ans=min(ans,tmp);
    }
    printf("%lld\n",ans);
    return 0;
}

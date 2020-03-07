#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 100010
const ll INF=4e18;
ll mx[2][maxn],mi[2][maxn];
ll a[maxn];
main()
{
    int n;scanf("%d",&n);
    ll p,q,r;scanf("%I64d%I64d%I64d",&p,&q,&r);
    for(int i=1;i<=n;i++)scanf("%I64d",&a[i]);
    mi[0][0]=mi[1][n+1]=INF;
    mx[0][0]=mx[1][n+1]=-INF;
    for(int i=1;i<=n;i++)
    {
        mx[0][i]=max(mx[0][i-1],a[i]);
        mi[0][i]=min(mi[0][i-1],a[i]);
    }
    for(int i=n;i>=1;i--)
    {
        mx[1][i]=max(mx[1][i+1],a[i]);
        mi[1][i]=min(mi[1][i+1],a[i]);
    }
    ll ans=-INF;
    for(int i=1;i<=n;i++)
    {
        ll tmp=q*a[i];
        if(p<0)tmp+=p*mi[0][i];
        else tmp+=p*mx[0][i];
        if(r<0)tmp+=r*mi[1][i];
        else tmp+=r*mx[1][i];
        ans=max(ans,tmp);
    }
    printf("%I64d\n",ans);
    return 0;
}

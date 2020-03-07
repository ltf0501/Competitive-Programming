#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
#define ll long long
const ll INF=5e18;
int a[maxn],nxt[maxn];
ll sum[maxn];
ll prod(ll x,ll y)
{
    if(INF/x<y)return -1;
    return x*y;
}
main()
{
    int n,k;scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),sum[i]=sum[i-1]+a[i];
    ll ans=0;
    for(int i=n+1;i>=1;i--)
        nxt[i]=(a[i]==1 ? nxt[i+1] : i);
    //for(int i=1;i<=n;i++)printf("%d ",nxt[i]);puts("");
    for(int i=1;i<=n;i++)
    {
        vector<int> umr;
        if(a[i]==1)umr.push_back(i);
        ll cur=1;
        for(int j=nxt[i];j<=n;j=nxt[j+1])
        {
            if(prod(cur,a[j])==-1)break;
            umr.push_back(j),cur*=a[j];
        }
        cur=1;
        for(int j : umr)
        {
            cur*=a[j];
            if(cur%k)continue;
            //printf("%d: %lld %lld\n",j,(sum[j]-sum[i-1])*k,(sum[nxt[j+1]-1]-sum[i-1])*k);
            if((sum[j]-sum[i-1])*k<=cur && (sum[nxt[j+1]-1]-sum[i-1])*k>=cur)ans++;
        }
    }
    printf("%lld\n",ans);
    return 0;
}

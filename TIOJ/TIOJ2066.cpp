#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) v.begin(),v.end()
#define maxn 100010
const ll mod=(1ll<<61)-1;
int n,k,m;
int a[maxn];
vector<int> v;
ll bit[maxn];
ll dp[maxn],cur[maxn],pre[maxn];
void add(int x,ll d)
{
    for(int i=x;i<=m;i+=i&-i)bit[i]=(bit[i]+d)%mod;
}
ll query(int x)
{
    ll ret=0;
    for(int i=x;i;i-=i&-i)ret=(ret+bit[i])%mod;
    return ret;
}
main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        v.clear();
        memset(bit,0,sizeof(bit));
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]),v.push_back(a[i]);
        sort(ALL(v));
        v.resize(m=unique(ALL(v))-v.begin());
        assert(m<maxn);
        for(int i=1;i<=n;i++)a[i]=lower_bound(ALL(v),a[i])-v.begin()+1;
        ll ans=0;
        for(int i=1;i<=n;i++)dp[i]=1;
        for(int t=2;t<=k;t++)
        {
            memset(bit,0,sizeof(bit));
            for(int i=1;i<=n;i++)
            {
                cur[i]=query(a[i]-1);
                ans=(ans+cur[i])%mod;
                add(a[i],dp[i]);
            }
            for(int i=1;i<=n;i++)dp[i]=cur[i];
        }
        ans=(ans+n)%mod;
        printf("%lld\n",ans);
    }
    return 0;
}

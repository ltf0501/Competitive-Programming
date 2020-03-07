#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 100010
int mi[17][maxn];
int n;
ll m,ans=0;
ll query(ll w,ll h)
{
    ll k=(ll)(log(w*1.0)/log(2.0));
    ll ret=0;
    for(int i=1;i+w-1<=n;i++)
    {
        ll minh=min(mi[k][i],mi[k][i+w-(1<<k)]);
        ret+=max(minh-h+1,0ll);
    }
    return ret;
}
main()
{
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&mi[0][i]);
    for(int j=1;(1<<j)<=n;j++)for(int i=1;i<=n;i++)
        mi[j][i]=min(mi[j-1][i],mi[j-1][i+(1<<(j-1))]);
    for(ll w=1;w*w<=m;w++)if(m%w==0)
    {
        ll h=m/w;
        if(h<=100000ll)
        {
            ans+=query(w,h);
            if(h!=w)ans+=query(h,w);
        }
    }
    printf("%lld\n",ans);
    return 0;
}

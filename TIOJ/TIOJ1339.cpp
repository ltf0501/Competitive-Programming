#include<bits/stdc++.h>
using namespace std;
#define maxn 1000010
#define ll long long
#define pii pair<int,int>
#define F first
#define S second
const int mod=1000000009;
vector<int> v[2];
pii a[maxn];
int bit[maxn];
int bit2[maxn];
void add1(int x,int d)
{
    for(int i=x;i<=maxn-10;i+=i&-i)bit[i]+=d;
}
int query1(int x)
{
    int ret=0;
    for(int i=x;i;i-=i&-i)ret+=bit[i];
    return ret;
}
void add2(int x,ll d)
{
    for(int i=x;i<=maxn-10;i+=i&-i)bit2[i]=(bit2[i]+d)%mod;
}
ll query2(int x)
{
    ll ret=0;
    for(int i=x;i;i-=i&-i)ret=(ret+bit2[i])%mod;
    return ret;
}
main()
{
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&a[i].F,&a[i].S);
        v[0].push_back(a[i].F),v[1].push_back(a[i].S);
    }
    sort(v[0].begin(),v[0].end());sort(v[1].begin(),v[1].end());
    v[0].resize(unique(v[0].begin(),v[0].end())-v[0].begin());
    v[1].resize(unique(v[1].begin(),v[1].end())-v[1].begin());
    for(int i=1;i<=n;i++)
    {
        a[i].F=lower_bound(v[0].begin(),v[0].end(),a[i].F)-v[0].begin()+1;
        a[i].S=lower_bound(v[1].begin(),v[1].end(),a[i].S)-v[1].begin()+1;
    }
    sort(a+1,a+n+1);
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        int num=query1(a[i].S);
        ll tmp=(ll)v[0][a[i].F-1]*(ll)v[1][a[i].S-1]%mod;
        ans=(ans+tmp*(ll)num)%mod;
        ans=(ans-query2(a[i].S))%mod;
        if(ans<0)ans+=mod;
        add1(a[i].S,1);
        add2(a[i].S,tmp);
    }
    printf("%lld\n",ans);
    return 0;
}

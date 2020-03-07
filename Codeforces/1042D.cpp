#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
#define ll long long
#define ALL(v) v.begin(),v.end()
#define SZ(v) (int)v.size()
int n;
ll t;
ll s[maxn];
vector<ll> v;
int id(ll x){return (int)(upper_bound(ALL(v),x)-v.begin());}
int bit[maxn];
void add(int x)
{
    for(int i=x;i<=SZ(v);i+=i&-i)bit[i]++;
}
int query(int x)
{
    int ret=0;
    for(int i=x;i;i-=i&-i)ret+=bit[i];
    return ret;
}
main()
{
    scanf("%d%lld",&n,&t);
    v.push_back(t);
    for(int i=1;i<=n;i++)
    {
        int x;scanf("%d",&x);
        s[i]=s[i-1]+x;
        v.push_back(s[i]+t);
    }
    sort(ALL(v));
    v.resize(unique(ALL(v))-v.begin());
    ll ans=0;
    //for(ll s : v)printf("%lld ",s);puts("");
    for(int i=0;i<=n;i++)
    {
        ans+=i-query(id(s[i]));
        //printf("%lld %d\n",s[i]+t,id(s[i]+t));
        add(id(s[i]+t));
    }
    printf("%lld\n",ans);
    return 0;
}


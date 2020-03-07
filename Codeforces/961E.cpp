#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
#define ll long long
int bit[maxn];
void add(int x,int d)
{
    for(int i=x;i<maxn;i+=i&-i)bit[i]+=d;
}
int query(int x)
{
    int ret=0;
    for(int i=x;i;i-=i&-i)ret+=bit[i];
    return ret;
}
#define pii pair<int,int>
#define F first
#define S second
vector<pii> v;
int n,a[maxn];
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)v.push_back(pii(a[i],i));
    sort(v.begin(),v.end(),greater<pii>());
    int cur=0;
    ll ans=0;
    for(int i=n;i>=1;i--)
    {
        while(cur<n && v[cur].F>=i)add(v[cur++].S,1);
        ans+=query(min(a[i],i-1));
    }
    printf("%lld\n",ans);
    return 0;
}

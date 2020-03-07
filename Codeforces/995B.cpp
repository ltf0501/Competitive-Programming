#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
#define ll long long
int n,a[maxn];
map<int,int> mp;
int bit[maxn];
void add(int x,int d)
{
    for(int i=x;i<=n;i+=i&-i)bit[i]+=d;
}
int query(int x)
{
    int ret=0;
    for(int i=x;i;i-=i&-i)ret+=bit[i];
    return ret;
}
main()
{
    scanf("%d",&n);
    n*=2;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    ll ans=0;
    for(int i=1;i<=n;i++)add(i,1);
    for(int i=1;i<=n;i++)
    {
        if(!mp[a[i]])mp[a[i]]=i;
        else
        {
            add(mp[a[i]],1);
            add(i,-1);
            ans+=query(i-1)-query(mp[a[i]]);
        }
    }
    printf("%lld\n",ans);
    return 0;
}

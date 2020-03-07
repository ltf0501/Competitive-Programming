#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
#define ll long long
ll c[maxn],a[maxn],b[maxn];
int n;
int r[maxn];
void add(int x,ll d)
{
    for(int i=x;i<=n;i+=i&-i)
        c[i]+=d;
}
ll query(int x)
{
    ll ret=0;
    for(int i=x;i;i-=i&-i)
        ret+=c[i];
    return ret;
}
bool cmp(int x,int y){return b[x]<b[y] || (b[x]==b[y] && x>y);}
ll ans(ll s)
{
    memset(c,0,sizeof(c));
    for(int i=1;i<=n;i++)b[i]=s*(ll)i-a[i];
    for(int i=1;i<=n;i++)r[i]=i;
    sort(r+1,r+n+1,cmp);
    ll ret=0;
    for(int i=1;i<=n;i++)
    {
        ret+=query(r[i]);
        add(r[i],1);
    }
    memset(c,0,sizeof(c));
    for(int i=1;i<=n;i++)b[i]=s*(ll)i-a[n+1-i];
    for(int i=1;i<=n;i++)r[i]=i;
    sort(r+1,r+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
        ret+=query(r[i]);
        add(r[i],1);
    }
    return ret;
}
unordered_map<int,ll> mp;
main()
{
    ll l,r;scanf("%d%lld%lld",&n,&l,&r);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    ll Ans=ans(r)-ans(l);
    if(!l)
    {
        for(int i=1;i<=n;i++)
        {
            if(mp.find(a[i])!=mp.end())mp[a[i]]++;
            else mp[a[i]]=1;
        }
        ll tmp=0;
        for(auto i : mp)tmp+=(i.second*(i.second-1)/2);
        Ans-=tmp;
    }
    printf("%lld\n",Ans);
    return 0;
}
/*
6 1 2
8 7 1 2 4 8
*/

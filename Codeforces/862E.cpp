#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
#define ll long long
const ll INF=1e16;
int a[maxn],b[maxn];
set<ll> s;
main()
{
    int n,m,q;scanf("%d%d%d",&n,&m,&q);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    for(int i=0;i<m;i++)scanf("%d",&b[i]);
    int flag=1;
    ll t=0;
    for(int i=0;i<n;i++)
    {
        t+=flag*b[i];
        flag=-flag;
    }
    s.insert(t);
    for(int i=2;i+n<=m;i+=2)
    {
        t=t-b[i-2]+b[i-1]+b[i+n-2]*flag-b[i+n-1]*flag;
        s.insert(t);
    }
    if(n!=m)
    {
        t=0,flag=1;
        for(int i=1;i<=n;i++)
        {
            t+=flag*b[i];
            flag=-flag;
        }
        s.insert(t);
        for(int i=3;i+n<=m;i+=2)
        {
            t=t-b[i-2]+b[i-1]+b[i+n-2]*flag-b[i+n-1]*flag;
            s.insert(t);
        }
    }
    ll ans=0;
    flag=1;
    for(int i=0;i<n;i++)
    {
        ans+=a[i]*flag;
        flag=-flag;
    }
    auto it=s.lower_bound(ans);
    ll g=INF,h=-INF;
    if(it!=s.end())g=*it;
    if(it!=s.begin())h=*(--it);
    printf("%I64d\n",min(g-ans,ans-h));
    while(q--)
    {
        int l,r,x;scanf("%d%d%d",&l,&r,&x);
        if((l+r)%2==0)
        {
            if(l%2==1)ans+=x;
            else ans-=x;
        }
        auto it=s.lower_bound(ans);
        ll g=INF,h=-INF;
        if(it!=s.end())g=*it;
        if(it!=s.begin())h=*(--it);
        printf("%I64d\n",min(g-ans,ans-h));
    }
    return 0;
}

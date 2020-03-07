#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=998244353;
int n;
ll a[505];
map<ll,int> mp,mp2;
vector<ll> v,tmp;
ll mysqrt(ll a)
{
    ll k=(ll)sqrt(a+0.5);
    while(k*k<a)k++;
    while(k*k>a)k--;
    return k;
}
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        ll k=mysqrt(a[i]+0.5);
        if(k*k==a[i])
        {
            ll kk=mysqrt(k+0.5);
            if(kk*kk==k)mp[kk]+=4;
            else mp[k]+=2;
        }
        else
        {
            ll kk=(ll)pow(a[i],1.0/3.0);
            while(kk*kk*kk<a[i])kk++;
            while(kk*kk*kk>a[i])kk--;
            if(kk*kk*kk==a[i])mp[kk]+=3;
            else v.push_back(a[i]);
        }
    }
    int m=v.size();
    for(int i=0;i<m;i++)
    {
        ll x=-1,y=-1;
        for(int j=1;j<=n;j++)if(v[i]!=a[j])
        {
            ll g=__gcd(v[i],a[j]);
            if(g!=1)
            {
                if(x==-1)x=g;
                else if(x!=g)y=g;
            }
        }
        if(x==-1)mp2[v[i]]++;
        else
        {
            if(y==-1)y=v[i]/x;
            mp[x]++,mp[y]++;
        }
    }
    ll ans=1;
    for(auto s : mp)ans=ans*(s.second+1)%mod;
    for(auto s : mp2)ans=ans*(s.second+1)%mod*(s.second+1)%mod;
    printf("%lld\n",ans);fflush(stdout);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MX=(ll)1e18;
int n,k,N;
int p[16];
vector<ll> v[2];
void dfs(ll x,int id,vector<ll>& v)
{
    v.push_back(x);
    for(int i=id;i<N;i++)
    {
        if(x<=MX/p[i])dfs(x*p[i],i,v);
        else break;
    }
}
main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&p[i]);
    scanf("%d",&k);
    N=min(n/2,6);
    dfs(1,0,v[0]);
    int m=N;N=n;
    for(int i=m;i<n;i++)
        dfs(p[i],i,v[1]);
    v[1].push_back(1);
    for(int i=0;i<2;i++)sort(v[i].begin(),v[i].end());
    //printf("%d %d\n",v[0].size(),v[1].size());
    ll l=1,r=(ll)1e18;
    while(l<r)
    {
        ll m=(l+r)/2;
        ll cnt=0;
        for(int i=0;i<v[0].size();i++)
        {
            if(v[0][i]>m)break;
            cnt+=upper_bound(v[1].begin(),v[1].end(),m/v[0][i])-v[1].begin();
            if(cnt>=k)break;
        }
        if(cnt>=k)r=m;
        else l=m+1;
    }
    printf("%lld\n",l);
    return 0;
}

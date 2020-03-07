#include<bits/stdc++.h>
using namespace std;
#define maxn 1000000+5
#define mod 1000000007
#define ll long long
bool vis[1000005];
vector<ll> prime;
void init()
{
    for(ll i=2;i<=maxn;i++)if(!vis[i])
    {
        prime.push_back(i);
        for(ll j=i*i;j<=maxn;j+=i)vis[j]=1;
    }
}
ll phi(ll n)
{
    ll ret=n;
    for(int i=0;i<prime.size();i++)
    {
        ll p=prime[i];
        if(p*p>n) break;
        if(n%p==0)
        {
            ret=ret/p*(p-1);
            while(n%p==0)n/=p;
        }
    }
    if(n>1)ret=ret/n*(n-1);
    return ret;
}
main()
{
    init();
    ll n,k;
    scanf("%I64d%I64d",&n,&k);
    while(k>0)
    {
        if(n==1) break;
        n=phi(n);
        k-=2;
    }
    printf("%I64d\n",n%mod);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,l,r;
int log2(ll n)
{
    ll i=0;
    ll ans=1;
    while(ans<=n)i++,ans*=2;
    i--;
    return i;
}
ll dfs(ll n,ll r)
{
    if(r==1)return 1;
    if(r==0)return 0;
    int a=log2(n);
    ll k=1;
    for(int i=1;i<=a;i++)k*=2;
    ll ans=0;
    for(int i=a;i>=0;i--)
    {
        if(r&k)ans+=n/2+n%2;
        n/=2,k/=2;
    }
    return ans;
}
main()
{
    scanf("%I64d%I64d%I64d",&n,&l,&r);
    if(!n){puts("0");return 0;}
    printf("%I64d\n",dfs(n,r)-dfs(n,l-1));
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define maxn 2000010
#define ll long long
const int mod=1e9+7;
ll dp[maxn],ans,cur,p[maxn];
int n,k;
ll pw(ll a,int n)
{
    ll ret=1;
    while(n)
    {
        if(n&1)ret=ret*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return ret;
}
vector<int> v[maxn];
main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=k;i++)p[i]=pw(i,n);
    for(int i=1;i<=k;i++)
        for(int j=i+i;j<=k;j+=i)v[j].push_back(i);
    for(int i=1;i<=k;i++)
    {
        dp[i]=(p[i]-p[i-1]+mod)%mod;
        for(int s : v[i])dp[i]=(dp[i]-dp[s]+mod)%mod;
        cur=(cur+dp[i])%mod;
        ans=(ans+(cur^i))%mod;
    }
    printf("%I64d\n",ans);
    return 0;
}

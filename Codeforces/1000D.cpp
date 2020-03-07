#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
#define maxn 1010
#define ll long long
int a[maxn],n;
vector<int> pos[maxn];
ll dp[maxn],c[maxn][maxn];
void pre(int n)
{
    c[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        c[i][0]=1;
        for(int j=1;j<=n;j++)c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
    }
}
main()
{
    scanf("%d",&n);
    pre(n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    ll ans=0;
    dp[n+1]=1;
    for(int i=n;i>=1;i--)if(a[i]>0 && a[i]<=n-i)
    {
        for(int j=i+a[i];j<=n;j++)dp[i]=(dp[i]+dp[j+1]*c[j-i][a[i]]%mod)%mod;
        ans=(ans+dp[i])%mod;
    }
    printf("%lld\n",ans);
    return 0;
}

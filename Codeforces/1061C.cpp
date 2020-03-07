#include<bits/stdc++.h>
using namespace std;
#define maxn 1000100
#define ll long long
const int mod=1e9+7;
vector<int> v,tmp;
int n;
ll dp[maxn],ans=0;
main()
{
    scanf("%d",&n);
    dp[0]=1;
    for(int i=1;i<=n;i++)
    {
        int x;scanf("%d",&x);
        v.clear(),tmp.clear();
        for(int j=1;1ll*j*j<=x && j<=i;j++)if(x%j==0)
        {
            v.push_back(j);
            if(1ll*j*j<x)tmp.push_back(x/j);
        }
        for(int j=tmp.size()-1;j>=0;j--)v.push_back(tmp[j]);
        for(int j=v.size()-1;j>=0;j--)dp[v[j]]=(dp[v[j]]+dp[v[j]-1])%mod;
    }
    for(int i=1;i<=n;i++)ans=(ans+dp[i])%mod;
    printf("%lld\n",ans);
    return 0;
}

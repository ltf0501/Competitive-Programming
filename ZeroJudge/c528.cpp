#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 10000010
const ll INF=1e16;
ll dp[maxn];
deque<int> dq;
main()
{
    int n,k;scanf("%d%d",&n,&k);
    dq.push_back(0);
    for(int i=1;i<=n;i++)
    {
        int x;scanf("%d",&x);
        while(!dq.empty() && dq.front()<i-k)dq.pop_front();
        dp[i]=x+dp[dq.front()];
        while(!dq.empty() && dp[i]<dp[dq.back()])dq.pop_back();
        dq.push_back(i);
    }
    ll ans=INF;
    for(int i=n;i>n-k;i--)ans=min(ans,dp[i]);
    printf("%lld\n",ans);
    return 0;
}

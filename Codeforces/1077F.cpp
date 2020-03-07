#include<bits/stdc++.h>
using namespace std;
#define maxn 5010
#define ll long long
int a[maxn];
int n,x,k;
ll dp[maxn][maxn];
deque<int> dq;
main()
{
    scanf("%d%d%d",&n,&k,&x);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    memset(dp,-1,sizeof(dp));
    dp[0][0]=0;
    for(int cur=0;cur<x;cur++)
    {
        dq.clear();
        if(dp[cur][0]!=-1)dq.push_back(0);
        for(int i=1;i<=n;i++)
        {
            while(!dq.empty() && i-dq.front()>k)dq.pop_front();
           // printf("pre = %d\n",dq.empty() ?dq.front());
            if(!dq.empty())dp[cur+1][i]=dp[cur][dq.front()]+a[i];
            //printf("%d->%d\n",dq.empty() ? -1 : dq.front(),i);
            while(!dq.empty() && dp[cur][i]>dp[cur][dq.back()])dq.pop_back();
            if(dp[cur][i]!=-1)dq.push_back(i);
        }
        //for(int i=1;i<=n;i++)printf("%lld ",dp[cur+1][i]);puts("");
    }
    ll ans=-1;
    for(int i=n;i>n-k;i--)ans=max(ans,dp[x][i]);
    printf("%lld\n",ans);
    return 0;
}

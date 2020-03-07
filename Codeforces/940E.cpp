#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
#define ll long long
int n,c,a[maxn],f[maxn];
ll dp[maxn],s[maxn];
deque<int> dq;
main()
{
    scanf("%d%d",&n,&c);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),s[i]=a[i]+s[i-1];
    dq.push_back(0);
    for(int i=1;i<=n;i++)
    {
        while(dq.size() && i-dq.front()>=c)dq.pop_front();
        while(dq.size() && a[dq.back()]>a[i])dq.pop_back();
        dq.push_back(i);
        f[i]=a[dq.front()];
    }
    for(int i=1;i<=n;i++)
    {
        dp[i]=dp[i-1]+a[i];
        if(i>=c)dp[i]=min(dp[i],dp[i-c]+s[i]-s[i-c]-f[i]);
    }
    //for(int i=1;i<=n;i++)printf("%lld ",dp[i]);puts("");
    printf("%lld\n",dp[n]);
    return 0;
}

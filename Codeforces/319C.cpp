#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
#define ll long long
ll a[maxn],b[maxn];
int n;
deque<int> dq;
ll dp[maxn];
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%I64d",&a[i]);
    for(int i=1;i<=n;i++)scanf("%I64d",&b[i]);
    dq.push_back(1);
    for(int i=2;i<=n;i++)
    {
        while(dq.size()>=2)
        {
            int k=dq.front();dq.pop_front();
            int j=dq.front();
            double x=1.0*a[i]*(b[k]-b[j]);
            double y=1.0*(dp[j]-dp[k]);
            if(y>=x)
            {
                dq.push_front(k);
                break;
            }
        }
        int j=dq.front();
        dp[i]=dp[j]+a[i]*b[j];
        while(dq.size()>=2)
        {
            int j=dq.back();dq.pop_back();
            int k=dq.back();
            double x=1.0*(dp[i]-dp[j])*(b[j]-b[k]);
            double y=1.0*(dp[j]-dp[k])*(b[i]-b[j]);
            if(y>=x)
            {
                dq.push_back(j);
                break;
            }
        }
        dq.push_back(i);
    }
    //for(int i=1;i<=n;i++)printf("%I64d ",dp[i]);
    printf("%I64d\n",dp[n]);
    return 0;
}

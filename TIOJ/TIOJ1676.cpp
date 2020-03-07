#include<bits/stdc++.h>
using namespace std;
#define maxn 500010
#define ll long long
ll dp[maxn],sum[maxn],a[maxn];
ll y(int i){return (ll)i*(ll)i-dp[i]-sum[i];}
deque<int> dq;
main()
{
    int n,k;scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[n+1-i];
    dq.push_back(0);
    for(int i=1;i<=n;i++)
    {
        while(i-dq.front()>k)dq.pop_front();
        while(dq.size()>=2)
        {
            int a=dq.front();dq.pop_front();
            int b=dq.front();
            if((ll)i*2*(b-a)<=y(b)-y(a))
            {
                dq.push_front(a);
                break;
            }
        }
        int j=dq.front();
        ///printf("%d\n",dq.front());
        dp[i]=dp[j]+sum[j]-(ll)(i-j)*(ll)(i-j);
        while(dq.size()>=2)
        {
            int j=dq.back();dq.pop_back();
            int s=dq.back();
            if((y(i)-y(j))*(ll)(j-s)>=(y(j)-y(s))*(ll)(i-j) || y(i)-y(j)>=2*(ll)(s+k)*(ll)(i-j))///要注意在i,s把j夾掉前,s可能就過期了
            {
                dq.push_back(j);
                break;
            }
        }
        dq.push_back(i);
    }
    ///for(int i=1;i<=n;i++)printf("%lld ",dp[i]);puts("");
    printf("%lld\n",dp[n]);
    return 0;
}

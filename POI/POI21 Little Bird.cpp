#include<bits/stdc++.h>
using namespace std;
#define maxn 1000010
int dp[maxn],d[maxn];
deque<int> dq;
main()
{
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&d[i]);
    int q;scanf("%d",&q);
    while(q--)
    {
        int k;scanf("%d",&k);
        dq.clear();
        dq[1]=0;dq.push_back(1);
        for(int i=2;i<=n;i++)
        {
            while(dq.front()+k<i)dq.pop_front();
            while(dq.size()>=2)
            {
                int k=dq.front();dq.pop_front();
                int j=dq.front();
                if(dp[j]>=dp[k] || (dp[j]==dp[k] && d[j]<=d[k]))
                {
                    dq.push_front(k);
                    break;
                }
            }
            int j=dq.front();
            dp[i]=dp[j]+(d[j]<=d[i]);
            while(!dq.empty() && (dp[dq.back()]>dp[i] || (dp[dq.back()]==dp[i] && d[dq.back()]<d[i])))dq.pop_back();
            dq.push_back(i);
        }
        printf("%d\n",dp[n]);
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define maxn 1000010
#define ll long long
ll d[maxn],p[maxn],c[maxn];
ll s[maxn],t[maxn],dp[maxn];
deque<int> dq;
ll v(int i){return c[i]+d[i]*s[i]-t[i];}
ll y(int i){return dp[i]+t[i];}
main()
{
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        ll y;scanf("%lld%lld%lld",&d[i],&y,&c[i]);
        s[i]=s[i-1]+y;
        t[i]=t[i-1]+d[i]*y;
    }
    dq.push_back(0);
    for(int i=1;i<=n;i++)
    {
        while(dq.size()>=2)
        {
            int k=dq.front();dq.pop_front();
            int j=dq.front();
            if(d[i]*(s[j]-s[k])<=y(j)-y(k))
            {
                dq.push_front(k);
                break;
            }
        }
        int j=dq.front();
        //printf("%d\n",j);
        dp[i]=v(i)+dp[j]-d[i]*s[j]+t[j];
        while(dq.size()>=2)
        {
            int j=dq.back();dq.pop_back();
            int k=dq.back();
            if((y(i)-y(j))*(s[j]-s[k])>=(y(j)-y(k))*(s[i]-s[j]))
            {
                dq.push_back(j);
                break;
            }
        }
        dq.push_back(i);
    }
    //for(int i=1;i<=n;i++)printf("%lld ",dp[i]);puts("");
    printf("%lld\n",dp[n]);
    return 0;
}
/*
3
0 5 10
5 3 100
9 6 10
*/

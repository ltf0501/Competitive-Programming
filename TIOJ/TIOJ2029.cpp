#include<bits/stdc++.h>
using namespace std;
#define maxn 500010
#define ll long long
const ll INF=1e16;
int n,k,C;
ll R;
int d[maxn];
ll s[maxn],t[maxn];
ll dp[maxn],tmp[maxn];
ll y(int i){return (C-n-i)*t[i]+s[i]-dp[i];}
deque<int> dq;
void Swap(ll a[],ll b[])
{
    for(int i=1;i<=n;i++)swap(a[i],b[i]);
}
bool solve(int Y)
{
    fill(dp+1,dp+n+1,-INF);
    fill(tmp+1,tmp+n+1,-INF);
    int T=k;
    while(T--)
    {
        dq.clear();dq.push_back(0);
        for(int i=1;i<=n;i++)
        {
            while(i-dq.front()>Y)dq.pop_front();
            while(dq.size()>=2)
            {
                int k=dq.front();dq.pop_front();
                int j=dq.front();
                if(y(j)-y(k)>=(ll)(j-k)*t[i])
                {
                    dq.push_front(k);
                    break;
                }
            }
            int j=dq.front();
            tmp[i]=dp[j]+s[i]-s[j]+(C-n+j)*(t[i]-t[j]);
            while(dq.size()>=2)
            {
                int j=dq.back();dq.pop_back();
                int k=dq.back();
                if((ll)(j-k)*(y(i)-y(j))>=(ll)(i-j)*(y(j)-y(k)) || y(i)-y(j)>=(ll)(i-j)*(ll)(k+Y))
                {
                    dq.push_back(j);
                    break;
                }
            }
            dq.push_back(i);
        }
        Swap(dp,tmp);
        ///for(int i=1;i<=n;i++)printf("%d ",dp[i]);puts("");
    }
    ///printf("%lld\n",dp[n]);
    return dp[n]>=R;
}
main()
{
    scanf("%d%d%lld%d",&n,&k,&R,&C);
    for(int i=1;i<=n;i++)scanf("%d",&d[i]);
    for(int i=1;i<=n;i++)s[i]=s[i-1]+(n-i)*d[i],t[i]=t[i-1]+d[i];
    int l=1,r=n+1;
    while(r-l>1)
    {
        int m=(l+r)>>1;
        ///printf("%d\n",m);
        if(solve(m))r=m;
        else l=m;
    }
    if(r==n+1)puts("-1");
    else printf("%d\n",r);
    return 0;
}

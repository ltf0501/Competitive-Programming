#include<cstdio>
#include<algorithm>
#include<deque>
using namespace std;
#define maxn 500010
#define ll long long
const ll INF=1e16;
int n,k;
ll a[maxn];
ll sum[maxn];
ll dp[maxn];
deque<int> dq;
ll s(int i){return -a[i+1];}
ll t(int i){return dp[i]-sum[i]+i*a[i+1];}
void init()
{
    while(!dq.empty())dq.pop_back();
}
int main()
{
    int T;scanf("%d",&T);
    while(T--)
    {
        init();
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++)scanf("%lld",&a[i]),sum[i]=sum[i-1]+a[i];
        dq.push_back(0);
        for(int i=1;i<=n;i++)
        {
            //while(dq.front()+2*k<=i)dq.pop_front();
            while(dq.size()>=2)
            {
                int kk=dq[0],j=dq[1];
                if(1ll*i*(a[j+1]-a[kk+1])>=t(j)-t(kk))dq.pop_front();
                else break;
            }
            int j=dq.front();
            dp[i]=s(j)*i+t(j)+sum[i];
            if(i-k+1>=k)
            {
                while(dq.size()>=2)
                {
                    int j=dq[dq.size()-1],kk=dq[dq.size()-2];
                    if((t(j)-t(kk))*(a[i-k+2]-a[j+1])>=(t(i-k+1)-t(j))*(a[j+1]-a[kk+1]))dq.pop_back();
                    else break;
                }
                dq.push_back(i-k+1);
            }
        }
        printf("%lld\n",dp[n]);
    }
    return 0;
}


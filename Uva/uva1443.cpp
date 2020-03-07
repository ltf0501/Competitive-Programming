#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 40000+10
#define inf 0x3f3f3f3f
int n,m,d;
int w[maxn],sum[maxn];
int dp[maxn][2];
bool check(int x)
{
    dp[0][0]=0,dp[0][1]=inf;
    for(int i=2;i<=n;i+=2)
    {
        dp[i][0]=inf,dp[i][1]=inf;
        for(int len=1;len<=d && i-2*len>=0;len++)
        {
            if(sum[i]-sum[i-len]>x)break;
            if(sum[i-len]-sum[i-2*len]<=x)
            {
                dp[i][0]=min(dp[i][0],dp[i-2*len][1]+1);
                dp[i][1]=min(dp[i][1],dp[i-2*len][0]+1);
            }
        }
    }
    if(dp[n][(m-1)%2]>m-1)return 0;
    return 1;
}
main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&m,&d);
        sum[0]=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&w[i]);
            sum[i]=sum[i-1]+w[i];
        }
        if((n&1) || (n<2*(m-1)) || (n>2*d*(m-1)))printf("BAD\n");
        else
        {
            int l=1,r=sum[n];
            while(l<r)//¤G¤À·j
            {
                int mid=(l+r)>>1;
                if(check(mid))r=mid;
                else l=mid+1;
            }
            printf("%d\n",l);
        }

    }
    return 0;
}

#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 10000+5
main()
{
    int t;scanf("%d",&t);
    int a[maxn],dp[maxn*1000+10];
    while(t--)
    {
        int n;scanf("%d",&n);
        memset(dp,0,sizeof(dp));
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        int v=sum/2;
        for(int i=1;i<=n;i++)
        {
            for(int j=v;j>=0;j--)
            {
                if(j>=a[i])dp[j]=max(dp[j],dp[j-a[i]]+a[i]);
            }
            /*
            for(int j=0;j<=v;j++)printf("%d ",dp[j]);
            puts("");
            */
        }
        printf("%d\n",dp[v]*dp[v]+(sum-dp[v])*(sum-dp[v]));
    }
    return 0;
}

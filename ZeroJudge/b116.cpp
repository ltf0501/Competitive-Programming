#include<bits/stdc++.h>
using namespace std;
#define maxn 100+5
int a[maxn];
int dp[1000*maxn];
main()
{
    int t,n;
    while(~scanf("%d%d",&t,&n))
    {
        while(t--)
        {
            memset(dp,0,sizeof(dp));
            int sum=0;
            for(int i=1;i<=n;i++)scanf("%d",&a[i]),sum+=a[i];
            if(sum&1){puts("No");continue;}
            sum/=2;
            bool flag=0;
            for(int i=1;i<=n;i++)
            {
                for(int j=sum;j>=0;j--)
                {
                    if(j>=a[i])dp[j]=max(dp[j],dp[j-a[i]]+a[i]);
                }
            }
            //for(int i=0;i<=sum;i++)printf("%d ",dp[i]);puts("");
            if(dp[sum]==sum)puts("Yes");
            else puts("No");
        }
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int a[105];
int dp[20010];
main()
{
    int T;scanf("%d",&T);
    int cas=0;
    while(T--)
    {
        int n,t;scanf("%d%d",&n,&t);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        for(int i=1;i<=t-1;i++)dp[i]=-1000000000;
        dp[0]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=t-1;j>=a[i];j--)
                dp[j]=max(dp[j],dp[j-a[i]]+1);
            //for(int j=0;j<=t-1;j++)printf("%d ",dp[j]);puts("");
        }
        int mx=-1,ti;
        for(int j=t-1;j>=0;j--)
            if(dp[j]>mx)mx=dp[j],ti=j;
        printf("Case %d: %d %d\n",++cas,mx+1,ti+678);
    }
    return 0;
}

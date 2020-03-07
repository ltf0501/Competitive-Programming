#include<bits/stdc++.h>
using namespace std;
int a[35],dp[35],p[35];
main()
{
    int n;
    while(~scanf("%d",&n) && n)
    {
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);a[0]=0;
        for(int i=0;i<=n;i++)dp[i]=100000000;
        dp[n]=0,p[n]=-1;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(dp[i]>dp[j]+(200-a[j]+a[i])*(200-a[j]+a[i]))
                    dp[i]=dp[j]+(200-a[j]+a[i])*(200-a[j]+a[i]),p[i]=j;
            }
        }
        /*
        for(int i=0;i<=n;i++)printf("%d ",p[i]);
        puts("");
        */
        int idx=0;
        while(p[idx]!=-1)printf("%d ",idx),idx=p[idx];
        printf("%d\n",n);
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define maxn 105
int n;
int a[maxn];
main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int sum=0;
        for(int i=1;i<=n;i++)scanf("%d",&a[i]),sum+=a[i];
        int k=sum;
        sum/=2;
        vector<int>dp(sum+5,0);
        for(int i=1;i<=n;i++)
            for(int j=sum;j>=a[i];j--)dp[j]=max(dp[j],dp[j-a[i]]+a[i]);
        printf("%d\n",k-2*dp[sum]);
    }
    return 0;
}

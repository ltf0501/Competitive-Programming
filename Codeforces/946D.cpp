#include<bits/stdc++.h>
using namespace std;
#define maxn 505
#define INF 100000000
int cal[maxn],dp[maxn];
int sum[maxn];
int n,m,k;
char c[maxn];
main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)cal[j]=INF;
        scanf("%s",c+1);
        sum[0]=0;
        for(int j=1;j<=m;j++)sum[j]=sum[j-1]+c[j]-'0';
        for(int len=1;len<=m;len++)for(int j=1;j+len-1<=m;j++)
            cal[sum[j+len-1]-sum[j-1]]=min(cal[sum[j+len-1]-sum[j-1]],len);
        for(int j=k;j>=0;j--)
        {
            int tmp=INF;
            for(int t=0;t<=min(j,sum[m]);t++)tmp=min(tmp,dp[j-t]+cal[sum[m]-t]);
            dp[j]=tmp;
        }
    }
    printf("%d\n",dp[k]);
    return 0;
}

#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 5000+5
#define maxm 50+5
#define INF 1000000
int dp[maxn][maxm];//d[i][j]表示1~i 和 1~j 的解
int n,m;
char s[maxn],t[maxm];
int judge(int k)
{
    memset(dp,INF,sizeof(dp));
    dp[0][0]=0;
    for(int i=0;i<=n;i++)
    {
        if(dp[i][m]<=k)dp[i][0]=0;
        for(int j=0;j<=m;j++)
        {
            dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]+(s[i+1]!=t[j+1]));
            dp[i+1][j]=min(dp[i+1][j],dp[i][j]+1);
            dp[i][j+1]=min(dp[i][j+1],dp[i][j]+1);
        }
    }
    return dp[n][m]<=k;
}
main()
{
    int cas;scanf("%d",&cas);
    while(cas--)
    {
        scanf("%s%s",t+1,s+1);
        n=strlen(s+1);m=strlen(t+1);
        //printf("%d %d\n",n,m);
        int l=0,r=n;
        while(l<r)
        {
            int mid=l+(r-l)/2;
            if(judge(mid))r=mid;
            else l=mid+1;
        }
        /*
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)printf("%d ",dp[i][j]);
            puts("");
        }
        */
        printf("%d\n",l);
    }
    return 0;
}

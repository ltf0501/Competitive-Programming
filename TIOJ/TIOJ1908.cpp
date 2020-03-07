#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 23
int dp[2][1<<maxn];
int A[maxn][maxn];
main()
{
    int n;scanf("%d",&n);
    memset(dp,0,sizeof(dp));
    int cur=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)scanf("%d",&A[i][j]);
    if(n==2)
    {
        int ans=0;
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)ans=max(ans,A[i][j]);
        printf("%d\n",ans);
        return 0;
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cur^=1;
            memset(dp[cur],0,sizeof(dp[cur]));
            for(int k=0;k<(1<<(n+1));k++)
            {
                dp[cur][(k<<1)^(1<<(n+1))]=dp[cur^1][k];//¤£«õ
                int flag=1;
                if(j && k&1)flag=0;
                if(i && k&( (1<<(n-2)) + (1<<(n-1)) + (1<<n) ) )flag=0;
                if(flag)dp[cur][(k<<1)^(1<<(n+1))^1]=dp[cur^1][k]+A[i][j];//«õ
            }
            for(int i=0;i<(1<<(n+1));i++)printf("%d ",dp[cur][i]);
            puts("");puts("");
        }

    }
    int ans=0;
    for(int i=0;i<(1<<(n+1));i++){ans=max(ans,dp[cur][i]);printf("%d ",dp[cur][i]);}
    puts("");
    printf("%d\n",ans);
    return 0;
}

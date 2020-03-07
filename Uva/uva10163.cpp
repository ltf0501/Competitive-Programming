# include<iostream>
# include<cstring>
# include<cstdio>
# include<algorithm>
using namespace std;

const int INF=1000000000;

int n,m,p[35];
int dp[105][35];//考慮第i個人時,已經j個倉庫好了

int main()
{
    while(scanf("%d%d",&n,&m)&&n+m)
    {
        for(int i=1;i<=m;++i)
            scanf("%d",p+i);

        memset(dp,0,sizeof(dp));
        for(int i=0;i<=m;++i) dp[0][i]=INF;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                dp[i][j]=dp[i][j-1];
                for(int k=1;k<=i;++k)
                    dp[i][j]=max(min(dp[i-k][j-1],p[j]/k),dp[i][j]);
            }
        }
        printf("%d ",dp[n][m]);
        int ans1=dp[n][m];
        if(ans1==0){
            printf("0\n");
            continue;
        }

        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;++i) dp[i][0]=INF;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                dp[i][j]=dp[i][j-1];
                for(int k=1;k<=i;++k)
                    if(p[j]/k>=ans1)
                        dp[i][j]=min(dp[i][j],dp[i-k][j-1]+p[j]);
            }
        }
        printf("%d\n",dp[n][m]);
    }
    return 0;
}

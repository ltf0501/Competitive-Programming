#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 5000+5
#define LL long long
int dp[2][maxn];
main()
{
    int n,m;
    LL ans=0;
    int M=0;
    int cur=1;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        cur^=1;
        memset(dp[cur],0,sizeof(dp[cur]));
        char s[maxn];scanf("%s",s);
        for(int j=0;j<m;j++)
        {
           // printf("%d XD\n",j);
            int a=s[j]-'0';
            if(a==1)dp[cur][j]=0;
            else
            {
                if(!i || !j)dp[cur][j]=1;
                else
                {
                    int a,b,c;
                    a=dp[cur^1][j],b=dp[cur^1][j-1],c=dp[cur][j-1];
                    dp[cur][j]=min(min(a,b),c)+1;
                }
            }
            ans+=dp[cur][j];
            M=max(M,dp[cur][j]);
        }
       // printf("%d\n",M);
        //getchar();
    }
    printf("%lld %d\n",ans,M);
    return 0;
}

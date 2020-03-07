#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define MOD 1000000007
int dp[405][2050][15];
int n,k;
int b[15][2050],a[2050],e[15];
int ans[405][15];
main()
{
    memset(dp,0,sizeof(dp));memset(b,0,sizeof(b));memset(ans,0,sizeof(ans));
    b[1][0]=b[1][1]=1;
    for(int i=2;i<=11;i++)
    {
        for(int j=0;j<(1<<i);j++)
        {
            int q=j;
            for(int u=1;u<=i;u++)
            {
                e[u]=q%2;
                q/=2;
            }
            int OK=1;
            for(int u=1;u<=i/2;u++)
            {
                if(e[u]!=e[i+1-u])
                {
                    OK=0;
                    break;
                }
            }
            if(OK)b[i][j]=i;
            else b[i][j]=max(b[i-1][j&((1<<(i-1))-1)],b[i-1][j/2]);
        }
    }
    for(int i=1;i<=10;i++)
    {
        for(int j=0;j<(1<<i);j++)
        {
            for(int u=b[i][j]+1;u<=10;u++)ans[i][u]++;
        }
    }
    /*
    for(int i=1;i<=10;i++)
    {
        for(int j=1;j<=10;j++)printf("%d ",ans[i][j]);
        puts("");
    }
    */
    for(int i=0;i<(1<<11);i++)a[i]=b[11][i];
    for(int i=0;i<(1<<11);i++)
    {
        for(int u=a[i]+1;u<=10;u++)
        {
            dp[11][i][u]++;
            ans[11][u]++;
        }
    }
    for(int i=12;i<=400;i++)
    {
        for(int j=0;j<(1<<11);j++)
        {
            for(int u=2;u<=10;u++)
            {
                if(a[j]>=u)dp[i][j][u]=0;
                else
                {
                    dp[i][j][u]=(dp[i-1][j/2][u]+dp[i-1][j/2+(1<<10)][u])%MOD;
                    ans[i][u]=(ans[i][u]+dp[i][j][u])%MOD;
                }
            }
        }
    }
    int cas;scanf("%d",&cas);
    while(cas--)
    {
        scanf("%d%d",&n,&k);
        printf("%d\n",ans[n][k]);
    }

    return 0;
}


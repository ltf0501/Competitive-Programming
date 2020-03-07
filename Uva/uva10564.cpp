#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define maxn 25
#define LL long long
int n,sum,g[maxn<<1][maxn];
int d[maxn<<1][maxn][520];//d(i,j,k)表走到第i行第j個元素時路徑和為k的條數
LL dp()//從下往上走為了dfs方便操作
{
    for(int i=1;i<=n;i++)d[n*2-1][i][g[n*2-1][i]]=1;

    for(int i=n*2-1;i>n;i--)
        for(int j=1;j<=i+1-n;j++)
            for(int k=0;k<=sum;k++)
            {
                    int t;
                    if(~g[i-1][j] && (t=k+g[i-1][j])<=sum)d[i-1][j][t]+=d[i][j][k];//向右
                    if(~g[i-1][j-1] && (t=k+g[i-1][j-1])<=sum)d[i-1][j-1][t]+=d[i][j][k];//向左
            }

    for(int i=n;i>1;i--)
        for(int j=1;j<=n+1-i;j++)
            for(int k=0;k<=sum;k++)
            {
                    int t;
                    if(~g[i-1][j] && (t=k+g[i-1][j])<=sum)d[i-1][j][t]+=d[i][j][k];//向左
                    if(~g[i-1][j+1] && (t=k+g[i-1][j+1])<=sum)d[i-1][j+1][t]+=d[i][j][k];//向右
            }

    LL ans=0;
    for(int i=1;i<=n;i++)if(d[1][i][sum])ans+=d[1][i][sum];
    return ans;
}
void dfs(int i,int j,int k)
{
    if(i==n*2-1)return;
    int t=k-g[i][j];
    if(i<n)
    {
        if(~g[i+1][j-1] && d[i+1][j-1][t])
        {
            putchar('L');
            dfs(i+1,j-1,t);
            return;
        }
        else if(~g[i+1][j] && d[i+1][j][t])
        {
            putchar('R');
            dfs(i+1,j,t);
            return;
        }
    }
    else
    {
        if(~g[i+1][j] && d[i+1][j][t])
        {
            putchar('L');
            dfs(i+1,j,t);
            return ;
        }
        else if(~g[i+1][j+1] && d[i+1][j+1][t])
        {
            putchar('R');
            dfs(i+1,j+1,t);
            return;
        }
    }
}
main()
{
    while(scanf("%d%d",&n,&sum)==2 && n+sum)
    {
        memset(d,0,sizeof(d));
        memset(g,-1,sizeof(g));
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n-i+1;j++)scanf("%d",&g[i][j]);
        for(int i=1;i<n;i++)
            for(int j=1;j<=i+1;j++)scanf("%d",&g[n+i][j]);
        LL cnt=dp();
        //printf("\n");
        /*
        for(int i=1;i<=n;i++)
            {for(int j=1;j<=n-i+1;j++)printf("%d ",d[i][j][sum]);printf("\n");}
        for(int i=1;i<n;i++)
            {for(int j=1;j<=i+1;j++)printf("%d ",d[n+i][j][sum]);printf("\n");}
        */
        printf("%lld\n",cnt);
        if(cnt)
        {
            for(int i=1; i<=n; i++)if(d[1][i][sum])
            {
                printf("%d ",i-1);
                dfs(1,i,sum);
                break;
            }
        }
        printf("\n");
    }
    return 0;
}

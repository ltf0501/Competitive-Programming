#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 30
int n,m,k,t=0;
int g[maxn][maxn],sum[maxn][maxn];//sum[i][j] 為前i列j行的個數
int dp[32][32][32][32], used[32][32][32][32];
int getArea(int x,int y,int w,int h)
{
    return sum[x+w-1][y+h-1]-sum[x-1][y+h-1]-sum[x+w-1][y-1]+sum[x-1][y-1];
}
int dfs(int x,int y,int w,int h)
{
    if(used[x][y][w][h]==t)return dp[x][y][w][h];
    if(getArea(x,y,w,h)<2)return 0;
    used[x][y][w][h]=t;
    int &ret = dp[x][y][w][h];
    ret = 0x3f3f3f3f;//先讓dp[x][y][w][h]很大
    for(int i=1;i<w;i++)
    {
        if(getArea(x,y,i,h)>0 && getArea(x+i,y,w-i,h)>0)
            ret=min(ret,dfs(x,y,i,h)+dfs(x+i,y,w-i,h)+h);
    }
    for(int i=1;i<=h;i++)
    {
        if(getArea(x,y,w,i)>0 && getArea(x,y+i,w,h-i)>0)
            ret=min(ret,dfs(x,y,w,i)+dfs(x,y+i,w,h-i)+w);
    }
    return ret;
}
main()
{
    while(scanf("%d %d %d",&n,&m,&k)==3)
    {
        memset(g,0,sizeof(g));
        memset(sum,0,sizeof(sum));
        for(int i=0;i<k;i++)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            g[x][y]++;
        }
        for(int i=1;i<=n;i++)
        {
            int x=0;
            for(int j=1;j<=m;j++)
            {
                x+=g[i][j];
                sum[i][j]=sum[i-1][j]+x;
            }
        }
        t++;
        printf("Case %d: %d\n",t,dfs(1,1,n,m));
    }
    return 0;
}

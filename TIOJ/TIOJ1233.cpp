#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 520
char g[maxn][maxn];
int vis[maxn][maxn]={0};
int m,n;
const int a[]={0,1,2,4,6,10,12,14,16,18,20};
void dfs(int x,int y,int cnt)
{
    vis[x][y]=cnt;
    for(int i=-1;i<=1;i++)
    {
        for(int j=-1;j<=1;j++)
        {
            if(i==0 && j==0)continue;
            if(x+i<0 || x+i>=m || y+j<0 || y+j>=n)continue;
            if(g[x+i][y+j]=='0')continue;
            if(vis[x+i][y+j])continue;
            dfs(x+i,y+j,cnt);
        }
    }
}
main()
{
    int cnt=0;
    scanf("%d%d",&m,&n);
    for(int i=0;i<m;i++)scanf("%s",g[i]);
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(g[i][j]=='1' && !vis[i][j])cnt++,dfs(i,j,cnt);
        }
    }
    /*
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)printf("%d ",vis[i][j]);
        puts("");
    }
    */
    if(cnt==0){puts("0");return 0;}
    if(cnt>20){puts("10");return 0;}
    int k=lower_bound(a,a+11,cnt)-a;
    printf("%d\n",k);
    return 0;
}

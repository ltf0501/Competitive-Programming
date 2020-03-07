#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 100+5
char g[maxn][maxn];
bool vis[maxn][maxn];
int w,h;
void dfs(int x,int y,char c)
{
    if(vis[x][y])return ;
    vis[x][y]=1;
    for(int i=-1;i<=1;i++)
    {
        for(int j=-1;j<=1;j++)
        {
            if(!i && !j)continue;
            int dx=x+i,dy=y+j;
            if(dx<0 || dy<0 || dx>=h || dy>=w)continue;
            if(g[dx][dy]!=c)continue;
            dfs(dx,dy,c);
        }
    }
}
main()
{
    scanf("%d%d",&w,&h);
    for(int i=0;i<h;i++)scanf("%s",g[i]);
    int cnt1=0,cnt2=0;
    for(int i=0;i<h;i++)
        for(int j=0;j<w;j++)if(!vis[i][j] && g[i][j]=='G')dfs(i,j,'G'),cnt1++;
    memset(vis,false,sizeof(vis));
    for(int i=0;i<h;i++)
        for(int j=0;j<w;j++)if(!vis[i][j] && g[i][j]=='-')dfs(i,j,'-'),cnt2++;
    printf("%d %d\n",cnt1,cnt2);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define maxn 505
const int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
char g[maxn][maxn];
bool vis[maxn][maxn];
int cnt;
int m,n;
void dfs(int x,int y)
{
    if(vis[x][y])return ;
    vis[x][y]=1;cnt++;
    for(int i=0;i<4;i++)
    {
        int x1=x+dx[i],y1=y+dy[i];
        if(x1<0 || x1>=m || y1<0 || y1>=n)continue;
        if(g[x1][y1]!='J')continue;
        dfs(x1,y1);
    }
}
main()
{
    while(~scanf("%d%d",&m,&n))
    {
        for(int i=0;i<m;i++)scanf("%s",g[i]);
        memset(vis,false,sizeof(vis));
        int ans=0,piece=0;
        for(int i=0;i<m;i++)for(int j=0;j<n;j++)
        {
            if(!vis[i][j] && g[i][j]=='J')piece++,cnt=0,dfs(i,j),ans=max(ans,cnt);
        }
        printf("%d %d\n",piece,ans);
    }
    return 0;
}

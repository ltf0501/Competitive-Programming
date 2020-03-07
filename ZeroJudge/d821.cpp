#include<bits/stdc++.h>
using namespace std;
#define maxn 55
#define mod 100000
const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};
struct P{int x,y,d;};
bool vis[maxn][maxn];
int dis[maxn][maxn],a[maxn][maxn];
int n,m;
bool not_ok(int x,int y){return x<0 || x>=n || y<0 || y>=m || a[x][y]==1;}
queue<P> q;
int dp[maxn][maxn];
int sx,sy,ex,ey;
int dfs(int x,int y)
{
    //printf("%d %d\n",x,y);
    if(vis[x][y])return dp[x][y];
    vis[x][y]=1;
    if(x==sx && y==sy)return dp[x][y]=1;
    int ret=0;
    for(int i=0;i<4;i++)
    {
        int xx=x+dx[i],yy=y+dy[i];
        if(not_ok(xx,yy))continue;
        if(dis[x][y]==dis[xx][yy]+1)ret=(ret+dfs(xx,yy))%mod;
    }
    return dp[x][y]=ret;
}
void init()
{
    memset(vis,0,sizeof(vis));
    memset(dis,0,sizeof(dis));
    memset(dp,0,sizeof(dp));
    while(!q.empty())q.pop();
}
main()
{
    while(~scanf("%d%d",&n,&m))
    {
        init();
        for(int i=0;i<n;i++)for(int j=0;j<m;j++)scanf("%d",&a[i][j]);
        scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
        if(sx==ex && sy==ey){puts("1");continue;}
        q.push({sx,sy,0});
        while(!q.empty())
        {
            P t=q.front();q.pop();
            if(vis[t.x][t.y])continue;
            vis[t.x][t.y]=1;
            dis[t.x][t.y]=t.d;
            if(t.x==ex && t.y==ey)break;
            for(int i=0;i<4;i++)
            {
                int x=t.x+dx[i],y=t.y+dy[i];
                if(not_ok(x,y))continue;
                q.push({x,y,t.d+1});
            }
        }
        if(!dis[ex][ey]){puts("0");continue;}
        /*
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)printf("%d ",dis[i][j]);
            puts("");
        }
        */
        memset(vis,0,sizeof(vis));
        printf("%d\n",dfs(ex,ey));
        /*
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)printf("%d ",dp[i][j]);
            puts("");
        }
        */
    }

    return 0;
}

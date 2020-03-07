#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
#define maxn 100+10
const int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
struct Point
{
    int x,y,t;
    Point(int x,int y,int t):x(x),y(y),t(t){}
};
int vis[maxn][maxn];
char g[maxn][maxn];
queue<Point> q;
main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        while(!q.empty())q.pop();
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++)scanf("%s",g[i]);
        int flag=1;
        q.push(Point(1,1,1));vis[1][1]=1;
        while(!q.empty() && flag)
        {
            Point p=q.front();q.pop();
            for(int i=0;i<4;i++)
            {
                Point p0=Point(p.x+dx[i],p.y+dy[i],p.t+1);
                if(p0.x>=0 && p0.y>=0 && p0.x<n &&p0.y<n)
                {
                    if(g[p0.x][p0.y]=='.' && vis[p0.x][p0.y]==0)
                    {
                        vis[p0.x][p0.y]=1;
                        q.push(p0);
                        if(p0.x==n-2 && p0.y==n-2)
                        {
                            printf("%d\n",p0.t);
                            flag=0;
                        }
                    }
                }
            }
        }
        if(flag)printf("No solution!\n");

    }
    return 0;
}

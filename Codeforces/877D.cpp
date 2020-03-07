#include<bits/stdc++.h>
using namespace std;
#define maxn 1010
#define INF 1000000000
struct P
{
    int x,y,t;
    bool operator < (const P& b)const
    {
        return t>b.t;
    }
};
const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};
char c[maxn][maxn];
int n,m,k;
bool vis[maxn][maxn][4];
queue<P> q;
bool ok(int x,int y,int i)
{
    return 1<=x && x<=n && 1<=y && y<=m && c[x][y]!='#' && !vis[x][y][i];
}
main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)scanf("%s",c[i]+1);
    int x1,y1,x2,y2;scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    if(x1==x2 && y1==y2){puts("0");return 0;}
    q.push({x1,y1,0});
    for(int i=0;i<4;i++)vis[x1][y1][i]=1;
    while(!q.empty())
    {
        P t=q.front();q.pop();
        if(t.x==x2 && t.y==y2){printf("%d\n",t.t);return 0;}
        for(int i=0;i<4;i++)
        {
            int x=t.x,y=t.y;
            for(int j=1;j<=k;j++)
            {
                x+=dx[i],y+=dy[i];
                if(!ok(x,y,i))break;
                vis[x][y][i]=1;
                q.push({x,y,t.t+1});
            }
        }
    }
    puts("-1");
    return 0;
}

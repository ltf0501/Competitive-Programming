#include<bits/stdc++.h>
using namespace std;
#define maxn 2010
#define pii pair<int,int>
#define x first
#define y second
const int dx[]={-1,1,0,0};
const int dy[]={0,0,-1,1};
const int cost[]={0,0,1,0};
char s[maxn][maxn];
bool vis[maxn][maxn];
int dis[maxn][maxn];
int n,m,r,c,num_l,num_r;
bool check(int x,int y){return x>=1 && x<=n && y>=1 && y<=m;}
deque<pii> q;
main()
{
    scanf("%d%d%d%d%d%d",&n,&m,&r,&c,&num_l,&num_r);
    for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)dis[i][j]=10000000;
    dis[r][c]=0;
    q.push_back(pii(r,c));
    while(!q.empty())
    {
        pii t=q.front();q.pop_front();
        if(vis[t.x][t.y])continue;
        vis[t.x][t.y]=1;
        for(int i=0;i<4;i++)
        {
            int a=t.x+dx[i],b=t.y+dy[i];
            if(check(a,b) && s[a][b]=='.' && !vis[a][b])
            {
                if(dis[a][b]>dis[t.x][t.y]+cost[i])
                {
                    //printf("%d %d\n",a,b);
                    dis[a][b]=dis[t.x][t.y]+cost[i];
                    if(i==2)q.push_back(pii(a,b));
                    else q.push_front(pii(a,b));
                }
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
        if(vis[i][j] && dis[i][j]<=num_l && j-c+dis[i][j]<=num_r)ans++;
        /*
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s[i][j]=='*')putchar(s[i][j]);
            else if(vis[i][j])putchar('+');
            else putchar('.');
        }puts("");
    }
    */
    printf("%d\n",ans);
    return 0;
}

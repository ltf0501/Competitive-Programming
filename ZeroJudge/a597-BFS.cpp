#include<bits/stdc++.h>
using namespace std;
#define maxn 505
const int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
char g[maxn][maxn];
bool vis[maxn][maxn];
int cnt;
int m,n;
struct node{int x,y;};
queue<node> q;
main()
{
    while(~scanf("%d%d",&m,&n))
    {
        for(int i=0;i<m;i++)scanf("%s",g[i]);
        memset(vis,false,sizeof(vis));
        int ans=0,piece=0;
        for(int i=0;i<m;i++)for(int j=0;j<n;j++)
        {
            if(!vis[i][j] && g[i][j]=='J')
            {
                vis[i][j]=1;
                piece++,cnt=1;
                q.push((node){i,j});
                while(!q.empty())
                {
                    node t=q.front();q.pop();
                    for(int i=0;i<4;i++)
                    {
                        int x=t.x+dx[i],y=t.y+dy[i];
                        if(x<0 || x>=m || y<0 || y>=n)continue;
                        if(vis[x][y] || g[x][y]!='J')continue;
                        vis[x][y]=1;
                        cnt++;
                        q.push((node){x,y});
                        //printf("%d %d\n",x,y);
                    }
                }
                ans=max(ans,cnt);
            }
        }
        printf("%d %d\n",piece,ans);
    }
    return 0;
}


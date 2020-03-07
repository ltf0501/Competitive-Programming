#include<bits/stdc++.h>
using namespace std;
#define maxn 205
const int dx[]={-1,0,1,0};
const int dy[]={0,1,0,-1};
bool flag[4][maxn][maxn];
bool vis[maxn][maxn];
int n,m,cur;
void dfs(int x,int y)
{
    if(vis[x][y])return ;
    vis[x][y]=1;
    cur+=(x&1)^(y&1) ? 1 : -1;
    //printf("%d %d %d\n",x,y,cur);
    for(int i=0;i<4;i++)
    {
        if(flag[i][x][y])continue;
        int a=x+dx[i],b=y+dy[i];
        if(a<=0 || a>n || b<=0 || b>n)continue;
        dfs(a,b);
    }
}
void init()
{
    memset(vis,0,sizeof(vis));
    memset(flag,0,sizeof(flag));
}
main()
{
    while(~scanf("%d%d",&n,&m))
    {
        init();
        for(int i=1;i<=m;i++)
        {
            int x,y,k;scanf("%d%d%d",&x,&y,&k);k--;
            flag[k][x][y]=1,flag[(k+2)%4][x+dx[k]][y+dy[k]]=1;
        }
        bool ok=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)if(!vis[i][j])
            {
                cur=0,dfs(i,j);
                if(cur!=0){ok=1;break;}
            }
            if(ok)break;
        }
        puts(ok ? "Kevin you cheat !" : "I win !");
    }
    return 0;
}

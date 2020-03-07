#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 10
int n,ans;
int G[maxn][maxn],vis[maxn][maxn],num[maxn];
const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};
void dfs(int x,int y,int len)
{
    vis[x][y]=1;
    for(int i=0;i<=3;i++)
    {
        int a=x+dx[i],b=y+dy[i];
        if(vis[a][b] || num[G[a][b]] || G[a][b]==-1)//已到底
        {
            ans=max(ans,len);
            continue;
        }
        num[G[a][b]]=1;
        dfs(a,b,len+1);
        num[G[a][b]]=0;
    }
    vis[x][y]=0;
}
main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        memset(G,-1,sizeof(G));
        memset(vis,0,sizeof(vis));
        memset(num,0,sizeof(num));
        ans=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)scanf("%d",&G[i][j]);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)dfs(i,j,0);
        printf("%d\n",ans+1);
    }
    return 0;
}
/*
2
4
1 3 5 7
2 11 6 9
6 13 8 2
8 17 10 4
3
1 2 3
1 2 4
1 2 3
*/

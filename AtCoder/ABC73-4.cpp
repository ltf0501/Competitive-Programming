#include<bits/stdc++.h>
using namespace std;
#define maxn 205
#define inf 1000000000
int n,m,r;
struct node
{
    int to,dis;
};
vector<node> g[maxn];
int v[maxn],d[maxn][maxn];
int tmp[10];
int ans;
bool vis[10];
void backtrack(int now)
{
    if(now==r+1)
    {
        int t=0;
        for(int i=1;i<n;i++)t+=d[tmp[i]][tmp[i+1]];
        ans=min(ans,t);
        return ;
    }
    for(int i=1;i<=r;i++)if(!vis[i])
    {
        vis[i]=1;tmp[now]=v[i];
        backtrack(now+1);
        vis[i]=0;
    }
}
main()
{
    scanf("%d%d%d",&n,&m,&r);
    for(int i=1;i<=r;i++)scanf("%d",&v[i]);
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)d[i][j]=inf;
    for(int i=1;i<=n;i++)d[i][i]=0;
    for(int i=1;i<=m;i++)
    {
        int x,y,z;scanf("%d%d%d",&x,&y,&z);
        g[x].push_back({y,z}),g[y].push_back({x,z});
        d[x][y]=d[y][x]=z;
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
            d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    }
    ans=inf;
    backtrack(1);
    printf("%d\n",ans);
    return 0;
}

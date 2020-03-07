#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
#define pii pair<int,int>
#define F first
#define S second
vector<int> g[maxn],col[105];
int n,m,k,s;
queue<pii> q;
int dis[maxn][105];
bool vis[maxn];
main()
{
    scanf("%d%d%d%d",&n,&m,&k,&s);
    for(int i=1;i<=n;i++)
    {
        int x;scanf("%d",&x);
        col[x].push_back(i);
    }
    for(int i=1;i<=m;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        g[x].push_back(y),g[y].push_back(x);
    }
    for(int i=1;i<=n;i++)for(int j=1;j<=k;j++)dis[i][j]=maxn;
    for(int i=1;i<=k;i++)
    {
        for(int r : col[i])q.push(pii(r,0));
        memset(vis,0,sizeof(vis));
        while(!q.empty())
        {
            pii t=q.front();q.pop();
            vis[t.F]=1;
            dis[t.F][i]=min(dis[t.F][i],t.S);
            for(int v : g[t.F])
                if(!vis[v])q.push(pii(v,t.S+1));
        }
    }
    for(int i=1;i<=n;i++)sort(dis[i]+1,dis[i]+k+1);
    for(int i=1;i<=n;i++)
    {
        int ans=0;
        for(int j=1;j<=s;j++)ans+=dis[i][j];
        printf("%d ",ans);
    }
    return 0;
}

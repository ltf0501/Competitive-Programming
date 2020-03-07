#include<bits/stdc++.h>
using namespace std;
#define maxn 1005
vector<int> g[maxn];
int n,m,s,t;
struct P
{
    int d,u;
    bool operator < (const P& b)const
    {
        return d>b.d;
    }
};
priority_queue<P> pq;
bool vis[maxn],con[maxn][maxn];
int d1[maxn],d2[maxn],tmp[maxn];
void dijk(int s)
{
    for(int i=1;i<=n;i++)tmp[i]=maxn;
    memset(vis,0,sizeof(vis));
    tmp[s]=0;
    pq.push({0,s});
    while(!pq.empty())
    {
        P x=pq.top();pq.pop();
        if(vis[x.u])continue;
        vis[x.u]=1;
        for(int v : g[x.u])
        {
            if(tmp[v]>tmp[x.u]+1)
            {
                tmp[v]=tmp[x.u]+1;
                pq.push({tmp[v],v});
            }
        }
    }
}
main()
{
    scanf("%d%d%d%d",&n,&m,&s,&t);
    for(int i=1;i<=m;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        g[x].push_back(y),g[y].push_back(x);
        con[x][y]=con[y][x]=1;
    }
    dijk(s);
    for(int i=1;i<=n;i++)d1[i]=tmp[i];
    dijk(t);
    for(int i=1;i<=n;i++)d2[i]=tmp[i];
    int ans=0,dis=d1[t];
    for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)
        if(!con[i][j] && d1[i]+d2[j]+1>=dis && d1[j]+d2[i]+1>=dis)ans++;
    printf("%d\n",ans);
    return 0;
}

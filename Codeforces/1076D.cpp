#include<bits/stdc++.h>
using namespace std;
#define maxn 300010
#define ll long long
#define pii pair<ll,int>
#define F first
#define S second
const ll INF=1e16;
struct E
{
    int u,v,d;
};
vector<int> g[maxn],g2[maxn];
vector<E> e;
int to(int u,int id){return e[id].u^e[id].v^u;}
int n,m,k;
pii p[maxn];
ll dis[maxn];
priority_queue<pii,vector<pii>,greater<pii> > pq;
bool vis[maxn];
vector<int> ans;
void dfs(int u)
{
    //printf("%d\n",u);
    for(int id : g2[u])
    {
        ans.push_back(id);
        int v=to(u,id);
        dfs(v);
    }
}
main()
{
    scanf("%d%d%d",&n,&m,&k);
    k=min(k,n-1);
    for(int i=1;i<=m;i++)
    {
        int x,y,d;scanf("%d%d%d",&x,&y,&d);
        int sz=e.size();
        e.push_back({x,y,d});
        g[x].push_back(sz),g[y].push_back(sz);
    }
    for(int i=1;i<=n;i++)dis[i]=INF;
    dis[1]=0;
    pq.push(pii(dis[1],1));
    while(!pq.empty())
    {
        pii t=pq.top();pq.pop();
        if(vis[t.S])continue;
        vis[t.S]=1;
        for(int id : g[t.S])
        {
            int v=to(t.S,id);
            if(dis[v]>t.F+e[id].d)
            {
                p[v]=pii(t.S,id);
                dis[v]=t.F+e[id].d;
                pq.push(pii(dis[v],v));
            }
        }
    }
    //for(int i=1;i<=n;i++)printf("%lld ",dis[i]);puts("");
   // for(int i=1;i<=n;i++)printf("%d ",p[i]);puts("");
    for(int i=2;i<=n;i++)g2[p[i].F].push_back(p[i].S);
    dfs(1);
    printf("%d\n",k);
    //for(int v : ans)printf("%d ",v);puts("");
    for(int i=0;i<k;i++)printf("%d ",ans[i]+1);puts("");
    return 0;
}

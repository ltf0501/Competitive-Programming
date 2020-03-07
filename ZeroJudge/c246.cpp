#include<bits/stdc++.h>
using namespace std;
#define maxn 105
#define INF 100000000
struct P
{
    int d,u;
    bool operator < (const P& b)const
    {
        return d>b.d;
    }
};
struct edge{int u,v,d;};
vector<edge> e;
int to(int u,int id){return u^e[id].u^e[id].v;}
priority_queue<P> pq;
int n,m,t,st;
vector<int> g[maxn];
int d[maxn];
bool vis[maxn];
void init()
{
    e.clear();
    for(int i=1;i<=n;i++)g[i].clear();
    for(int i=1;i<=n;i++)d[i]=INF;
    memset(vis,0,sizeof(vis));
}
main()
{
    int cas;scanf("%d",&cas);
    while(cas--)
    {
        scanf("%d%d%d%d",&n,&st,&t,&m);
        init();
        e.push_back({0,0,0});
        for(int i=1;i<=m;i++)
        {
            int x,y,d;scanf("%d%d%d",&x,&y,&d);
            if(x==y || d>t)continue;
            int id=e.size();
            g[y].push_back(id);
            e.push_back({y,x,d});
        }
        d[st]=0;
        pq.push({0,st});
        while(!pq.empty())
        {
            P t=pq.top();pq.pop();
            if(vis[t.u])continue;
            vis[t.u]=1;
            for(int i : g[t.u])
            {
                int v=to(t.u,i);
                if(d[v]>d[t.u]+e[i].d)
                {
                    d[v]=d[t.u]+e[i].d;
                    pq.push({d[v],v});
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)
            if(d[i]<=t)ans++;
        printf("%d\n",ans);
        if(cas)puts("");
    }
    return 0;
}

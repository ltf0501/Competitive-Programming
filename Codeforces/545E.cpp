#include<bits/stdc++.h>
using namespace std;
#define maxn 300010
#define ll long long
int n,m,root;
struct edge
{
    int x,y,d,id;
    bool operator < (const edge& b)const{return d<b.d;}
};
struct P
{
    int v;ll d;
    bool operator < (const P& b)const{return d>b.d;}
};
vector<edge> e;
vector<int> g[maxn];
int to(int x,int id){return x^e[id].x^e[id].y;}
ll d[maxn];
bool vis[maxn];
priority_queue<P> pq;
vector<edge> pre[maxn];
main()
{
    scanf("%d%d",&n,&m);
    e.push_back({0,0,0,0});
    for(int i=1;i<=m;i++)
    {
        int x,y,d;scanf("%d%d%d",&x,&y,&d);
        g[x].push_back(i),g[y].push_back(i);
        e.push_back((edge){x,y,d,i});
    }
    for(int i=1;i<=n;i++)d[i]=(ll)4e16;
    scanf("%d",&root);
    d[root]=0;
    pq.push((P){root,0});
    ll ans=0;
    while(!pq.empty())
    {
        P t=pq.top();pq.pop();
        if(vis[t.v])continue;
        //printf("%d\n",t.v);
        vis[t.v]=1;
        for(int i : g[t.v])
        {
            int v=to(t.v,i);
            if(d[v]>d[t.v]+e[i].d)
            {
                d[v]=d[t.v]+e[i].d;
                pq.push((P){v,d[v]});
            }
        }
    }
    for(int u=1;u<=n;u++)
    {
        for(int i : g[u])
        {
            int v=to(u,i);
            if(d[v]==d[u]+e[i].d)pre[v].push_back(e[i]);
        }
    }
    for(int u=1;u<=n;u++)if(u!=root)
    {
        sort(pre[u].begin(),pre[u].end());
        ans+=pre[u][0].d;
    }
    printf("%I64d\n",ans);
    for(int u=1;u<=n;u++)if(u!=root)
        printf("%d ",pre[u][0].id);
    return 0;
}

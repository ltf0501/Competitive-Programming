#include<bits/stdc++.h>
using namespace std;
#define maxn 105
#define ll long long
const ll inf=1e12;
struct edge
{
    int from,to,cap,flow,cost;
    edge(int u,int v,int c,int f,int w):from(u),to(v),cap(c),flow(f),cost(w){}
};
struct MCMF
{
    int n,m;
    vector<edge> edges;
    vector<int> g[maxn];
    int inq[maxn];
    int d[maxn];
    int p[maxn];
    int a[maxn];

    void init(int n)
    {
        this->n=n;
        for(int i=0;i<n;i++)g[i].clear();
        edges.clear();
    }

    void addedge(int from,int to,int cap,int cost)
    {
        edges.push_back(edge(from,to,cap,0,cost));
        edges.push_back(edge(to,from,0,0,-cost));
        m=edges.size();
        g[from].push_back(m-2);
        g[to].push_back(m-1);
    }
    bool Bellmanford(int s,int t,int& flow,ll& cost)
    {
        for(int i=1;i<=n;i++)d[i]=inf;
        memset(inq,0,sizeof(inq));
        d[s]=0,inq[s]=1,p[s]=0,a[s]=inf;

        queue<int> q;
        q.push(s);
        while(!q.empty())
        {
            int u=q.front();q.pop();
            inq[u]=0;
            for(int v : g[u])
            {
                edge& e=edges[v];
                if(e.cap>e.flow && d[e.to]>d[u]+e.cost)
                {
                    d[e.to]=d[u]+e.cost;
                    p[e.to]=v;
                    a[e.to]=min(a[u],e.cap-e.flow);
                    if(!inq[e.to]){q.push(e.to);inq[e.to]=1;}
                }
            }
        }
        if(d[t]==inf)return 0;
        flow+=a[t];
        cost+=(ll)d[t]*(ll)a[t];
        for(int u=t;u!=s;u=edges[p[u]].from)
            edges[p[u]].flow+=a[t],edges[p[u]^1].flow-=a[t];
        return 1;
    }
    ll query(int s,int t,ll& cost)
    {
        int flow=0;ll cost=0;
        while(Bellmanford(s,t,flow,cost));
        return cost;
    }
};
main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        MCMF ans;
        scanf("%d%d",&ans.n,&ans.m);
        ans.init(n);
    }
    return 0;
}

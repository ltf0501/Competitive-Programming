#include<bits/stdc++.h>
using namespace std;
#define maxn 1000010
#define pii pair<int,int>
#define F first
#define S second
const int INF=1e9+7;
vector<pii> edge;
vector<int> g[20010];
int n,m;
int N;
struct Edge{
	int from,to,cap,flow;//起点，终点，容量，流量
	Edge(){}
	Edge(int from,int to,int cap,int flow):from(from),to(to),cap(cap),flow(flow){}
};
struct Dinic{
	int n,m,s,t;
	vector<Edge> edges;
	vector<int> G[maxn];
	bool vis[maxn];
	int d[maxn];
	int cur[maxn];

	void init(int n)
    {
	 	this->n=n;
	 	for(int i=0;i<n;i++) G[i].clear();
	 	edges.clear();
    }
	void AddEdge(int from,int to,int cap)
	{
		edges.push_back(Edge(from,to,cap,0));
		edges.push_back(Edge(to,from,0,0));
		m=edges.size();
		G[from].push_back(m-2);
		G[to].push_back(m-1);
	}
	bool bfs()
	{
		memset(vis,0,sizeof(vis));
		queue<int> Q;
		Q.push(s);
		d[s]=0;
		vis[s]=1;
		while(!Q.empty())
		{
			int x=Q.front();Q.pop();
			for(int i=0;i<G[x].size();i++)
			{
				Edge& e=edges[G[x][i]];
				if(!vis[e.to]&&e.cap>e.flow)
				{
					vis[e.to]=1;
					d[e.to]=d[x]+1;
					Q.push(e.to);
				}
			}
		}
		return vis[t];
	}
	int dfs(int x,int a)
	{
		if(x==t || a==0) return a;
		int flow=0,f;
		for(int& i=cur[x]; i<G[x].size() ;i++)
		{
			Edge& e=edges[G[x][i]];
			if(d[x]+1==d[e.to]&&(f=dfs(e.to,min(a,e.cap-e.flow)))>0){
				e.flow+=f;
				edges[G[x][i]^1].flow-=f;
				flow+=f;
				a-=f;
				if(!a) break;
			}
		}
		return flow;
	}
	int Maxflow(int s,int t)
	{
		this->s=s,this->t=t;
		int flow=0;
		while(bfs())
		{
			memset(cur,0,sizeof(cur));
			flow+=dfs(s,INF);
		}
		return flow;
	}
}solver;
pii anc[20][20010];
int in[20010],out[20010],dfs_clock;
void dfs(int u,int fa)
{
    in[u]=++dfs_clock;
    for(int v : g[u])if(v!=fa)
    {
        anc[0][v]=pii(u,N++);
        for(int k=1;;k++)
        {
            int w=anc[k-1][v].F;
            if(!anc[k-1][w].F)break;
            anc[k][v]=pii(anc[k-1][w].F,N++);
            solver.AddEdge(anc[k][v].S,anc[k-1][v].S,INF);
            solver.AddEdge(anc[k][v].S,anc[k-1][w].S,INF);
        }
        dfs(v,u);
    }
    out[u]=dfs_clock;
}
bool ancestor(int x,int y){return in[x]<=in[y] && out[x]>=out[y];}
int LCA(int x,int y)
{
    if(ancestor(x,y))return x;
    if(ancestor(y,x))return y;
    for(int i=17;i>=0;i--)if(!ancestor(anc[i][x].F,y))
        x=anc[i][x].F;
    return anc[0][x].F;
}
void add(int id,int u,int l)
{
    for(int i=17;i>=0;i--)if(!ancestor(anc[i][u].F,l))
    {
        solver.AddEdge(id,anc[i][u].S,INF);
        u=anc[i][u].F;
    }
    solver.AddEdge(id,anc[0][u].S,INF);
}
vector<int> v,e;
main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<n;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        edge.push_back(pii(x,y));
        g[x].push_back(y),g[y].push_back(x);
    }
    dfs(1,0);out[0]=dfs_clock;
    for(int i=0;i<m;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        int l=LCA(x,y);
        add(N+i,x,l),add(N+i,y,l);
    }
    N+=m;
    int s=N++;
    int t=N++;
    for(int i=0;i<m;i++)solver.AddEdge(s,N-2-m+i,1);
    for(int i=2;i<=n;i++)solver.AddEdge(anc[0][i].S,t,1);
    int ans=solver.Maxflow(s,t);
    for(int i=0;i<m;i++)
    {
        int id=N-2-m+i;
        if(!solver.vis[id])v.push_back(i);
    }
    for(int i=0;i<edge.size();i++)
    {
        int u=edge[i].F,v=edge[i].S;
        if(ancestor(u,v))swap(u,v);
        int id=anc[0][u].S;
        if(solver.vis[id])e.push_back(i);
    }
    printf("%d\n",ans);
    printf("%d",(int)v.size());
    for(int id : v)printf(" %d",id+1);puts("");
    printf("%d",(int)e.size());
    for(int id : e)printf(" %d",id+1);puts("");
    return 0;
}


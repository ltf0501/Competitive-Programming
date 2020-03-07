#include<bits/stdc++.h>
using namespace std;
#define maxn 5010
#define int long long
const int INF=1e14L;
int n,m;
int a[maxn];
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

int32_t main()
{
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    int ans=0;
    for(int i=1;i<=m;i++)
    {
        int x,y,d;scanf("%lld%lld%lld",&x,&y,&d);
        solver.AddEdge(i,x+m,INF);
        solver.AddEdge(i,y+m,INF);
        solver.AddEdge(0,i,d);
        ans+=d;
    }
    for(int i=1;i<=n;i++)solver.AddEdge(i+m,n+m+10,a[i]);
   // printf("%lld\n",solver.m);
    printf("%lld\n",ans-solver.Maxflow(0,n+m+10));
    return 0;
}

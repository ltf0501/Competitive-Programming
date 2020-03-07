#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
#define F first
#define S second
const int maxn = 110;
const int maxm = 1010;
const double inf = 1e9;
const double eps = 1e-9;
int deg[maxn];
pii p[maxm];
int n, m;
int s, t;
struct Edge{
	int from,to;
	double cap,flow;//起點，終點，容量，流量
	Edge(){}
	Edge(int from,int to,double cap,double flow):from(from),to(to),cap(cap),flow(flow){}
};
vector<Edge> edges;
vector<int> G[maxn];
struct Dinic{
	int n,m,s,t;
	bool vis[maxn];
	int d[maxn];
	int cur[maxn];

	void init(int n)
    {
	 	this->n=n;
	 	for(int i=0;i<n;i++) G[i].clear();
	 	edges.clear();
    }
	void AddEdge(int from,int to,double cap)
	{
		edges.push_back(Edge(from,to,cap,0.0));
		edges.push_back(Edge(to,from,0.0,0.0));
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
				if(!vis[e.to] && e.cap - e.flow > eps)
				{
					vis[e.to]=1;
					d[e.to]=d[x]+1;
					Q.push(e.to);
				}
			}
		}
		return vis[t];
	}
	double dfs(int x, double a)
	{
		if(x==t || a < eps) return a;
		double flow=0,f;
		for(int& i=cur[x]; i<G[x].size();i++)
		{
			Edge& e=edges[G[x][i]];
			if(d[x]+1==d[e.to]&&(f=dfs(e.to,min(a,e.cap-e.flow)))>eps){
				e.flow+=f;
				edges[G[x][i]^1].flow-=f;
				flow+=f;
				a-=f;
				if(a < eps) break;
			}
		}
		return flow;
	}
	double Maxflow(int s,int t)
	{
		this->s=s,this->t=t;
		double flow=0;
		while(bfs())
		{
			memset(cur,0,sizeof(cur));
			double tmp=dfs(s,inf);
			if(tmp==inf)return -1;
			flow+=tmp;
		}
//		printf("flow = %.3f\n", flow);
		return flow;
	}
};
Dinic solver;
void build(double mid) {
	solver.init(n + 5);
	for(int i = 1; i <= n; i++) {
		solver.AddEdge(s, i, 1.0 * m);
		solver.AddEdge(i, t, double(m + 2.0 * mid - deg[i]));
	}
	for(int i = 1; i <= m; i++) {
		solver.AddEdge(p[i].F, p[i].S, 1.0);
		solver.AddEdge(p[i].S, p[i].F, 1.0);
	}
}
bool mark[maxn];
int sum;
void dfs(int u) {
	++sum;
	mark[u] = 1;
	for(int i = 0; i < (int)G[u].size(); i++) {
		Edge& e = edges[G[u][i]];
		if(e.cap - e.flow > eps && !mark[e.to]) dfs(e.to);
	}
}
int main() {
	scanf("%d%d", &n, &m);
	solver.init(n + 5);
	s = 0, t = n + 1;
	for(int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		p[i] = pii(x, y);
		deg[x]++, deg[y]++;
	}
	if(m == 0) {
		printf("1\n1\n");
		return 0;
	}
 	double l = 0, r = m;
	while(r - l >=  1.0 / n / n) {
		double mid = (l + r) / 2;
		build(mid);
		double h = ((double)m * n - solver.Maxflow(s, t)) / 2;
		if(h > eps) l = mid;
		else r = mid;
	}
	build(l);
	solver.Maxflow(s, t);
	dfs(s);
	printf("%d\n", sum - 1);
	for(int i = 1; i <= n; i++)
		if(mark[i]) printf("%d\n", i);
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1505;
typedef pair<int, int> pii;
#define F first
#define S second
struct Edge {
	int from, to, cap, flow, cost;
	Edge(){}
	Edge(int u, int v, int c, int f, int co): from(u), to(v), cap(c), flow(f), cost(co){}
};

vector<Edge> edges;
vector<int> G[maxn];

struct MCMF {
	int n, m, s, t;
	int dis[maxn];
	int h[maxn];
	int p[maxn];

	void init(int n) {
		this->n = n;
		for(int i = 0; i < n; i++) G[i].clear();
		edges.clear();
	}

	void AddEdge(int from, int to, int cap, int cost) {
		edges.push_back(Edge(from, to, cap, 0, cost));
		edges.push_back(Edge(to, from, 0, 0, -cost));
		m = (int)edges.size();
		G[from].push_back(m - 2);
		G[to].push_back(m - 1);
	}

	bool dijkstra(int s, int t, int& max_flow, long long& cost) {
		priority_queue<pii, vector<pii>, greater<pii> > pq;
		for(int i = 0; i < n; i++) dis[i] = INF;
		dis[s] = 0, pq.push(pii(0, s));
		while(!pq.empty()) {
			pii u = pq.top(); pq.pop();
			int v = u.S;	
			if(dis[v] < u.F) continue;
			for(int i = 0; i < (int)G[v].size(); i++) {
				Edge& e = edges[G[v][i]];
				if(e.cap > e.flow && dis[e.to] > dis[v] + e.cost + h[v] - h[e.to]) {
					dis[e.to] = dis[v] + e.cost + h[v] - h[e.to];
					p[e.to] = G[v][i];
					pq.push(pii(dis[e.to], e.to));
				}
			}
		}
		if(dis[t] == INF) return 0;
		for(int i = 0; i < n; i++) h[i] += dis[i];
		int d = max_flow;
		for(int u = t; u != s; u = edges[p[u]].from) 
			d = min(d, edges[p[u]].cap - edges[p[u]].flow);
		max_flow -= d;
		cost += (long long)d * (long long)h[t];
		for(int u = t; u != s; u = edges[p[u]].from) {
			edges[p[u]].flow += d;
			edges[p[u]^1].flow -= d;
		}
		return 1;
	}

	void MincostMaxflow(int s, int t, int max_flow, long long& cost) {
		this->s = s, this->t = t;
		cost = 0;
		for(int i = 0; i < n; i++) h[i] = 0;
		while(dijkstra(s, t, max_flow, cost) && max_flow);
	}
};
int a[55][55];
int get_id(int i, int j) {
	if(i > j) swap(i, j);
	return i + j * (j - 1) / 2;
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--, y--;
		a[x][y] = 1;
	}
	MCMF solver;
	solver.init(m * (m - 1) / 2 + n + 10);
	int cnt = 0;
	int edge_num = m * (m - 1) / 2;
	int s = edge_num + n, t = edge_num + n + 1;
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			if(a[i][j] || a[j][i]) {
				if(a[i][j]) solver.AddEdge(cnt, edge_num + i, 1, 0);
				else solver.AddEdge(cnt, edge_num + j, 1, 0);
			}
			else {
				solver.AddEdge(cnt, edge_num + i, 1, 0);
				solver.AddEdge(cnt, edge_num + j, 1, 0); 
			}
			solver.AddEdge(s, cnt, 1, 0);
			cnt++;
		}
	}
	for(int i = 0; i < n; i++) {
		for(int k = 0; k < n - 1; k++) {
			solver.AddEdge(edge_num + i, t, 1, k);
		}
	}
	return 0;
}

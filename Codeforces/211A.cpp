#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const int maxn = 505;
const int maxm = 5010;
struct E {
	int u, v, ans;
	E(){}
	E(int u, int v, int ans):u(u), v(v), ans(ans){}
};
vector<E> ee; 
int n, m, k, num;
int deg[maxn];
typedef pair<int, int> pii;
#define F first
#define S second
struct Edge {
        int from, to, cap, flow, cost, id;
        Edge(){}
        Edge(int u, int v, int c, int f, int co, int id): from(u), to(v), cap(c), flow(f), cost(co), id(id){}
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

        void AddEdge(int from, int to, int cap, int cost, int id) {
                edges.push_back(Edge(from, to, cap, 0, cost, id));
                edges.push_back(Edge(to, from, 0, 0, -cost, -1));
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
		void check(int now) {
			for(int i = 0; i < (int)edges.size(); i += 2) {
				Edge e = edges[i];
				if(e.cap == e.flow && e.id != -1) {
					ee[e.id].ans = now;
					deg[e.from]--, deg[e.to]--;
				}
			}
		}
};
int cal(int x, int y) {
	return (x % y == 0) ? x / y : x / y + 1;
}
int main() {
	scanf("%d%d%d%d", &n, &m, &k, &num);
	for(int i = 0; i < k; i++) {
		int x, y;
		scanf("%d%d", &x, &y); x--, y--;
		int sz = (int)ee.size();
		deg[x]++, deg[y + n]++;
		ee.push_back({x, y, -1});
	}
	int cnt = 0;
	for(int i = 0; i < n + m; i++) cnt += (deg[i] % num != 0);
	printf("%d\n", cnt);
	for(int i = num; i >= 1; i--) {
		MCMF solver;
		solver.init(n + m + 10);
		int s = n + m, t = n + m + 1;
		for(int j = 0; j < (int)ee.size(); j++) {
			if(ee[j].ans == -1) {
				solver.AddEdge(ee[j].u, ee[j].v + n, 1, 0, j);
			}
		}
		for(int j = 0; j < n; j++) {
			solver.AddEdge(s, j, deg[j] / i, 0, -1);
			if(deg[j] % i != 0) solver.AddEdge(s, j, 1, 1, -1);
		}
		for(int j = 0; j < m; j++) {
			solver.AddEdge(j + n, t, deg[j + n] / i, 0, -1);
			if(deg[j + n] % i != 0) solver.AddEdge(j + n, t, 1, 1, -1);
		}
		long long cost = 0;
		solver.MincostMaxflow(s, t, INF, cost);
		solver.check(i);
	}
	for(int i = 0; i < k; i++) printf("%d ", ee[i].ans); puts("");
	return 0;
}

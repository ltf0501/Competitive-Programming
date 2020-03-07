#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
#define maxn 2000+10
#define INF 1000000000
int R,C,N;

struct Edge
{
    int from,to,cap,flow;
    Edge(int u,int v,int c,int f):from(u),to(v),cap(c),flow(f){}
};

struct EdmondsKarp
{
    int n,m;
    vector<Edge> edges;
    vector<int> G[maxn];
    int a[maxn],p[maxn],S[maxn],T[maxn];

    void Init(int n)
    {
        for(int i=0;i<n;i++)G[i].clear();
        edges.clear();
        memset(S,0,sizeof(S));memset(T,0,sizeof(T));
    }

    void AddEdge(int from,int to,int cap)
    {
        edges.push_back(Edge(from,to,cap,0));
        edges.push_back(Edge(to,from,0,0));
        m=edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }
    int Maxflow(int s,int t)
    {
        int flow=0;
        while(1)
        {
            memset(a,0,sizeof(a));
            queue<int> q;
            q.push(s);
            a[s]=INF;
            while(!q.empty())
            {
                int u=q.front();q.pop();
                for(int i=0;i<G[u].size();i++)
                {
                    Edge& e=edges[G[u][i]];
                    if(!a[e.to] && e.cap>e.flow)
                    {

                        a[e.to]=min(a[u],e.cap-e.flow);
                        p[e.to]=G[u][i];
                        q.push(e.to);
                    }
                }
                if(a[t])break;
            }
            if(!a[t])break;
            int cnt=0;
            for(int u=t;u!=s;u=edges[p[u]].from)
            {
                edges[p[u]].flow+=a[t];
                edges[p[u]^1].flow-=a[t];

            }
            flow+=a[t];
        }

    }
}g;
main()
{
    while(scanf("%d%d%d",&R,&C,&N)==3 && R+C+N)
    {
        g.Init(R+C+2);
        int r,c;
        for(int i=0;i<N;i++)
        {
            scanf("%d%d",&r,&c);
            g.AddEdge(r-1,R+c-1,1);
        }
        for(int i=0;i<R;i++)g.AddEdge(R+C,i,1);
        for(int i=R;i<R+C;i++)g.AddEdge(i,R+C+1,1);
        int ans=g.Maxflow(R+C,R+C+1);
        printf("%d",ans);

        /*
        for(int i=0;i<R;i++)
        {
            if(g.S[i]==0)printf(" r%d",i+1);
        }
        puts("");
        for(int i=R;i<R+C;i++)
        {
            if(g.T[i]==1)printf(" c%d",i-R+1);
        }
        puts("");
        */
    }
    return 0;
}

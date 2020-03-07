#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<string>
#include<queue>
using namespace std;
#define maxn 400+10
#define INF 1000000000
int n,m,k;
vector<string> names;
int d[maxn][maxn],target[maxn],device[maxn];
int ID(const string& s)
{
    for(int i=0;i<names.size();i++)
        if(names[i]==s) return i;
    names.push_back(s);
    return names.size()-1;
}
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
    int a[maxn],p[maxn];

    void Init(int n)
    {
        for(int i=0;i<n;i++)G[i].clear();
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
            for(int u=t;u!=s;u=edges[p[u]].from)
            {
                edges[p[u]].flow+=a[t];
                edges[p[u]^1].flow-=a[t];
            }
            flow+=a[t];
        }
        return flow;
    }
}g;
main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        names.clear();
        memset(d,0,sizeof(d));
        string s1,s2;
        scanf("%d",&n);
        for(int i=0;i<n;i++){cin>>s1;target[i]=ID(s1);}
        scanf("%d",&m);
        for(int i=0;i<m;i++){cin>>s1>>s2;device[i]=ID(s2);}
        scanf("%d",&k);
        for(int i=0;i<k;i++){cin>>s1>>s2;d[ID(s1)][ID(s2)]=1;}
        int v=names.size();
        for(int k=0;k<v;k++)//floyd
        {
            for(int i=0;i<v;i++)
            {
                for(int j=0;j<v;j++)d[i][j]=d[i][j] || (d[i][k] && d[k][j]);
            }
        }
        g.Init(v+2);
        for(int i=0;i<m;i++)g.AddEdge(v,device[i],1);
        for(int i=0;i<n;i++)g.AddEdge(target[i],v+1,1);
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(d[device[i]][target[j]])g.AddEdge(device[i],target[j],INF);

        int ans=g.Maxflow(v,v+1);
        printf("%d\n",m-ans);
        if(t)puts("");
    }
    return 0;
}

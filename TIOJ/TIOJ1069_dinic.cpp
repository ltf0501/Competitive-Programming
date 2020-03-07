#include<bits/stdc++.h>
using namespace std;
#define maxn 2005
#define INF 10000000
struct P
{
    int t,x,y;
    void input(){scanf("%d%d%d",&t,&x,&y);}
}a[maxn];
struct edge{int u,v,cap,flow;};
struct dinic
{
    int n,m,s,t;            //结点数，边数（包括反向弧），源点编号和汇点编号
    vector<edge> edges;     //边表。edge[e]和edge[e^1]互为反向弧
    vector<int> g[maxn];    //邻接表，G[i][j]表示节点i和第j条边在e数组中的序号
    bool vis[maxn];         //BFS使用
    int d[maxn];            //从起点到i的距离
    int cur[maxn];          //当前弧下标
    void init(int n)
    {
        for(int i=0;i<n;i++)g[i].clear();
        edges.clear();
    }
    void clear_flow()
    {
        int len=edges.size();
        for(int i=0;i<len;i++) edges[i].flow=0;
    }
    void addedge(int from,int to,int cap)
    {
        edges.push_back((edge){from,to,cap,0});
        edges.push_back((edge){to,from,0,0});
        m=edges.size();
        g[from].push_back(m-2);
        g[to].push_back(m-1);
    }
    bool BFS()
    {
        memset(vis,0,sizeof(vis));
        queue<int> q;
        q.push(s);
        d[s]=0;
        vis[s]=1;
        while(!q.empty())
        {
            int x=q.front();
            q.pop();
            for(int y : g[x])
            {
                edge& e=edges[y];
                if(!vis[e.v] && e.cap>e.flow)
                {
                    vis[e.v]=1;
                    d[e.v]=d[x]+1;
                    q.push(e.v);
                }
            }
        }
        return vis[t];
    }
    int DFS(int x,int a)
    {
        if(x==t || a==0) return a;
        int flow=0,f,len=g[x].size();
        for(int& i=cur[x];i<len;i++)
        {
            int id=g[x][i];
            edge& e=edges[id];
            if(d[x]+1==d[e.v] && (f=DFS(e.v,min(a,e.cap-e.flow)))>0)
            {
                e.flow+=f;
                edges[id^1].flow-=f;
                flow+=f;
                a-=f;
                if(a==0)break;
            }
        }
        return flow;
    }
    int maxflow(int s,int t)
    {
        this->s=s;
        this->t=t;
        int flow=0;
        while(BFS())
        {
            memset(cur,0,sizeof(cur));
            flow+=DFS(s,INF);
        }
        return flow;
    }
};
main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int n;scanf("%d",&n);
        for(int i=1;i<=n;i++)a[i].input();
        dinic sol;
        sol.init(2*n+1);
        for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
            if(i!=j && abs(a[i].x-a[j].x)+abs(a[i].y-a[j].y)+a[i].t<=a[j].t)
                sol.addedge(i,j+n,1);
        for(int i=1;i<=n;i++)sol.addedge(0,i,1);
        for(int i=1;i<=n;i++)sol.addedge(i+n,2*n+1,1);
        printf("%d\n",n-sol.maxflow(0,2*n+1));
    }
    return 0;
}

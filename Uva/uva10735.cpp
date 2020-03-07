#include<bits/stdc++.h>
using namespace std;
#define maxn 105
#define maxm 505
#define INF 100000000
int n,m;
struct edge{int u,v,cap,flow;};
struct dinic
{
    int n,m,s,t;
    vector<edge> edges;
    vector<int> g[maxn];
    bool vis[maxn];
    int d[maxn];
    int cur[maxn];
    void init(int n)
    {
        for(int i=1;i<=n;i++)g[i].clear();
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
        if(x==t || a==0)return a;
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
int in[maxn],out[maxn];
#define pii pair<int,int>
#define F first
#define S second
vector<pii> e;
vector<int> g[maxn],ans;
bool vis[maxm];
void dfs(int u)
{
    for(int id : g[u])if(!vis[id])
    {
        vis[id]=1;
        int v=e[id].S;
        dfs(v);
        ans.push_back(id);
    }
}
main()
{
    int t;scanf("%d",&t);
    bool f=0;
    while(t--)
    {
        if(f)puts("");
        f=1;
        scanf("%d%d",&n,&m);
        memset(vis,0,sizeof(vis));
        ans.clear();
        memset(in,0,sizeof(in));
        memset(out,0,sizeof(out));
        for(int i=1;i<=n;i++)g[i].clear();
        e.clear();
        dinic sol;
        sol.init(n);
        for(int i=1;i<=m;i++)
        {
            int x,y;char c[2];
            scanf("%d%d%s",&x,&y,c);
            if(c[0]=='U')sol.addedge(x,y,1);
            else
            {
                e.push_back(pii(x,y));
                int s=e.size();
                g[x].push_back(s-1);
            }
            out[x]++,in[y]++;
        }
        bool flag=1;
        int tot=0;
        for(int i=1;i<=n;i++)
        {
            if(abs(in[i]-out[i])&1){flag=0;break;}
            if(in[i]<out[i])
            {
                int k=(out[i]-in[i])/2;
                tot+=k;
                sol.addedge(n+1,i,k);
            }
            else if(in[i]>out[i])
            {
                int k=(in[i]-out[i])/2;
                sol.addedge(i,n+2,k);
            }
        }
        if(!flag){puts("No euler circuit exist");continue;}
        int mx=sol.maxflow(n+1,n+2);
        if(mx!=tot){puts("No euler circuit exist");continue;}
        for(int i=1;i<=n;i++)
        {
            for(int j : sol.g[i])if(j%2==0)
            {
                edge E=sol.edges[j];
                int u=E.u,v=E.v;
                if(u>n || v>n)continue;
                if(E.flow==1)swap(u,v);
                e.push_back(pii(u,v));
                int s=e.size();
                g[u].push_back(s-1);
            }
        }
        dfs(1);
        reverse(ans.begin(),ans.end());
        for(int id : ans)printf("%d ",e[id].F);
        puts("1");
    }
    return 0;
}

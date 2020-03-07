#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
#define INF 1000000007
struct E{int u,v,c;};
int n,m;
vector<int> g[maxn],now,tmp,ans;
vector<E> e;
int to(int u,int id){return u^e[id].u^e[id].v;}
queue<int> q;
int d[maxn];
bool vis[maxn];
void init()
{
    e.clear();
    ans.clear();
    now.clear();
    for(int i=1;i<=n;i++)g[i].clear();
    while(!q.empty())q.pop();
    memset(vis,0,sizeof(vis));
}
main()
{
    while(~scanf("%d%d",&n,&m))
    {
        init();
        e.push_back({0,0,0});
        for(int i=1;i<=m;i++)
        {
            int x,y,c;scanf("%d%d%d",&x,&y,&c);
            if(x==y)continue;
            int s=e.size();
            g[x].push_back(s),g[y].push_back(s);
            e.push_back({x,y,c});
        }
        q.push(n);
        vis[n]=1;d[n]=0;
        while(!q.empty())
        {
            int u=q.front();q.pop();
            for(int i : g[u])
            {
                int v=to(u,i);
                if(!vis[v])
                {
                    vis[v]=1,d[v]=d[u]+1;
                    q.push(v);
                }
            }
        }
        //for(int i=1;i<=n;i++)printf("%d ",d[i]);puts("");
        memset(vis,0,sizeof(vis));
        now.push_back(1);
        int cur=d[1];
        vis[1]=1;
        while(cur--)
        {
            int mi=INF;
            for(int u : now)for(int i : g[u])
            {
                int v=to(u,i);
                if(d[u]==d[v]+1)mi=min(mi,e[i].c);
            }
            ans.push_back(mi);
            for(int u : now)for(int i : g[u])
            {
                int v=to(u,i);
                if(!vis[v] && d[u]==d[v]+1 && e[i].c==mi)
                    vis[v]=1,tmp.push_back(v);
            }
            now=tmp;
            tmp.clear();
        }
        printf("%d\n",d[1]);
        for(int i=0;i<ans.size();i++)printf("%d%c",ans[i],i==ans.size()-1 ? '\n' : ' ');
    }
    return 0;
}

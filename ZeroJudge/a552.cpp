#include<bits/stdc++.h>
using namespace std;
#define maxn 105
vector<int> g[maxn];
bool vis[maxn];
int deg[maxn];
struct node
{
    int id,deg;
    node(int id,int deg):id(id),deg(deg){}
    bool operator < (const node& b)const
    {
        return deg>b.deg ||(deg==b.deg && id>b.id);
    }
};
main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=0;i<n;i++)g[i].clear();
        memset(vis,false,sizeof(vis));
        memset(deg,0,sizeof(deg));
        priority_queue<node> pq;
        for(int i=0;i<m;i++)
        {
            int a,b;scanf("%d%d",&a,&b);
            g[a].push_back(b);deg[b]++;
        }
        for(int i=0;i<n;i++)
        {
            node e(i,deg[i]);
            pq.push(e);
        }
        while(!pq.empty())
        {
            node e=pq.top();pq.pop();
            if(vis[e.id])continue;
            printf("%d ",e.id);vis[e.id]=1;
            for(int i=0;i<g[e.id].size();i++)
            {
                int u=g[e.id][i];
                if(vis[u])continue;
                deg[u]--;
                node k(u,deg[u]);
                pq.push(k);
            }
        }
        puts("");
    }
    return 0;
}

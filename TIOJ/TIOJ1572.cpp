#include<bits/stdc++.h>
using namespace std;
#define maxn 1000000+10
#define INF 100000000
struct node
{
    int u,dist;
    node(int u,int dist):u(u),dist(dist){}
    bool operator < (const node& b)const
    {
        return dist>b.dist;
    }
};
vector<int> g[maxn];
int p[maxn],d[maxn];
bool vis[maxn];
priority_queue<node> pq;
main()
{
    int n,m,a,b;
    scanf("%d%d%d%d",&n,&m,&a,&b);
    while(m--)
    {
        int x,y;scanf("%d%d",&x,&y);
        g[x].push_back(y);g[y].push_back(x);
    }
    fill(d+1,d+n+1,INF);
    d[a]=0;
    pq.push(node(a,0));
    while(!pq.empty())
    {
        node t=pq.top();pq.pop();
        int u=t.u;
        if(vis[u])continue;
        vis[u]=1;
        for(int i=0;i<g[u].size();i++)
        {
            int v=g[u][i];
            if(d[v]==INF || d[v]>d[u]+1)
            {
                d[v]=d[u]+1;
                p[v]=u;
                pq.push(node(v,d[v]));
            }
            else if(d[v]==d[u]+1 && p[v]>u)p[v]=u;
        }
    }
    //for(int i=1;i<=n;i++)printf("%d ",p[i]);puts("");
    printf("%d\n",d[b]-1);
    int u=b;
    vector<int> s;
    while(u)s.push_back(u),u=p[u];
    for(int i=s.size()-1;i>=1;i--)printf("%d-",s[i]);
    printf("%d\n",s[0]);
    return 0;
}

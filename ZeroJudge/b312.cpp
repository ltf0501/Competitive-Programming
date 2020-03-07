#include<bits/stdc++.h>
using namespace std;
#define maxn 5010
#define INF 1000000000

struct node
{
    int x,dis;
    node(int x,int dis):x(x),dis(dis){}
    bool operator < (const node& rhs)const
    {
        return dis>rhs.dis;
    }
};
vector<node> g[maxn];
int n,m,st,ed;
int d[maxn];
bool vis[maxn];
main()
{
    scanf("%d%d%d%d",&n,&m,&st,&ed);
    for(int i=1;i<=m;i++)
    {
        int x,y,d;scanf("%d%d%d",&x,&y,&d);
        g[x].push_back(node(y,d)),g[y].push_back(node(x,d));
    }
    fill(d+1,d+n+1,INF);
    priority_queue<node> pq;
    d[st]=0;
    pq.push(node(st,0));
    while(!pq.empty())
    {
        node u=pq.top();pq.pop();
        if(vis[u.x])continue;
        vis[u.x]=1;
        for(node v : g[u.x])
        {
            if(d[v.x]>d[u.x]+v.dis)
            {
                d[v.x]=d[u.x]+v.dis;
                pq.push(node(v.x,d[v.x]));
            }
        }
    }
    printf("%d\n",d[ed]);
    return 0;
}

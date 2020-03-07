#include<bits/stdc++.h>
using namespace std;
#define maxn 10000+10
#define INF 100000000
int d[maxn];
bool vis[maxn];
struct node
{
    int to,dis;
    bool operator < (const node& b)const
    {
        return dis>b.dis;
    }
    node(int to,int dis):to(to),dis(dis){}
};
priority_queue<node> pq;
vector<node> g[maxn];
main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        fill(d,d+n,INF);
        memset(vis,false,sizeof(vis));
        for(int i=0;i<n;i++)g[i].clear();
        for(int i=0;i<m;i++)
        {
            int x,y,d;scanf("%d%d%d",&x,&y,&d);
            g[x].push_back(node(y,d)),g[y].push_back(node(x,d));
        }
        int st,ed;scanf("%d%d",&st,&ed);
        d[st]=0;
        pq.push(node(st,0));
        while(!pq.empty())
        {
            node t=pq.top();pq.pop();
            if(vis[t.to])continue;
            vis[t.to]=1;
            for(node v : g[t.to])
            {
                if(d[v.to]==INF || d[v.to]>d[t.to]+v.dis)
                {
                    d[v.to]=d[t.to]+v.dis;
                    pq.push(node(v.to,d[v.to]));
                }
            }
        }
        printf("%d\n",d[ed]);
    }
    return 0;
}

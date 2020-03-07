#include<bits/stdc++.h>
using namespace std;
#define INF 100000000
struct node
{
    int from,to,cap,flow;
}edge[40100];
int p[1005],flow[1005];
vector<int> v[1005];
int e_cnt;
void add_edge(int from,int to,int cap,int flow)
{
    edge[e_cnt].from=from;
    edge[e_cnt].to=to;
    edge[e_cnt].cap=cap;
    edge[e_cnt].flow=flow;
    v[from].push_back(e_cnt);
    e_cnt++;
}
int BFS(int st,int ed)
{
    deque<int> dq;
    dq.push_back(st);
    flow[st]=INF;
    while(!dq.empty())
    {
        int x=dq.front();dq.pop_front();
        for(int u : v[x])
        {
            node t=edge[u];
            if(!flow[t.to] && t.cap>t.flow)
            {
                p[t.to]=u;
                flow[t.to]=min(flow[t.from],t.cap-t.flow);
                dq.push_back(t.to);
            }
        }
        if(flow[ed])return flow[ed];
    }
    return flow[ed];
}
int cal(int st,int ed)
{
    int ans=0;
    while(1)
    {
        memset(flow,0,sizeof(flow));
        memset(p,0,sizeof(p));
        int tmp=BFS(st,ed);
        if(!tmp)return ans;
        ans+=tmp;
        int e=ed;
        while(e!=st)
        {
            int t=p[e];
            edge[t].flow+=tmp;
            edge[t^1].flow-=tmp;
            e=edge[t].from;
        }
    }
    return 0;
}
void init(int n)
{
    e_cnt=0;
    for(int i=0;i<=2*n+1;i++)v[i].clear();
}
main()
{
    int n,k,cas=0;
    while(~scanf("%d%d",&n,&k) && n+k)
    {
        init(n);
        while(k--)
        {
            int x,y;scanf("%d%d",&x,&y);
            add_edge(x,y+n,1,0),add_edge(y+n,x,0,0);
        }
        for(int i=1;i<=n;i++)add_edge(0,i,1,0),add_edge(i,0,0,0);
        for(int i=1;i<=n;i++)add_edge(i+n,2*n+1,1,0),add_edge(2*n+1,i+n,0,0);
        printf("Case #%d:%d\n",++cas,cal(0,2*n+1));
    }
    return 0;
}

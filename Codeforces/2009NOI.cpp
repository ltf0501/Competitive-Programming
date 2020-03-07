#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
int p[1005],flow[1005];
struct node
{
    int from,to,cap,flow;
}edge[200000];
int e_cnt;
vector<int> v[1005];
int R,C;
inline int pointid(int x,int y){return x*C+y+1;}
void add_edge(int from,int to,int cap,int flow)
{
    edge[e_cnt].from=from;
    edge[e_cnt].to=to;
    edge[e_cnt].cap=cap;
    edge[e_cnt].flow=flow;
    v[from].push_back(e_cnt);
    e_cnt++;
}
void build(int n,int m)
{
    for(int i=1;i<=n;i++)
        add_edge(0,i,r[i],0),add_edge(i,0,0,0);
    for(int i=1;i<=m;i++)
        add_edge(n+i,n+m+1,c[i],0),add_edge(n+m+1,n+i,0,0);
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
        add_edge(i,n+j,19,0),add_edge(n+j,i,0,0);
}
int BFS(int s,int e)
{
    deque<int> dq;
    dq.push_back(s);
    flow[s]=INF;
    while(!dq.empty())
    {
        int x=dq.front();dq.pop_front();
        for(int i=0;i<v[x].size();i++)
        {
            int u=v[x][i];
            node ed=edge[u];
            if(!flow[ed.to] && ed.cap>ed.flow)
            {
                p[ed.to]=u;
                flow[ed.to]=min(flow[ed.from],ed.cap-ed.flow);
                dq.push_back(ed.to);
            }
        }
        if(flow[e])return flow[e];
    }
    return flow[e];
}
int cal(int s,int e)
{
    int ans=0;
    while(1)
    {
        memset(flow,0,sizeof(flow));
        memset(p,0,sizeof(p));
        int tmp=BFS(s,e);
        if(!tmp)return ans;
        ans+=tmp;

        int ed=e;
        while(ed!=s)
        {
            int t=p[ed];
            edge[t].flow+=tmp;
            edge[t^1].flow-=tmp;
            ed=edge[t].from;
        }
    }
    return 0;
}

main()
{
    scanf("%d%d",&R,&C);
    return 0;
}

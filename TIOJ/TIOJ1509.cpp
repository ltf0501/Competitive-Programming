#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
#define MAXV 1000004
#define MAXE 1000004
#define INF 2147483647
#define LL long long
typedef pair<int,int> pr;
struct Edge
{
    int to,cost;
};
int v,e;
vector<Edge>edge1[MAXE],edge2[MAXE];
LL d[MAXV],ans;
int vis[MAXV];
priority_queue<pr,vector<pr>,greater<pr> > pq;
main()
{
    scanf("%d%d",&v,&e);
    int flag=1;
    for(int i=0;i<e;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        a--,b--;
        Edge t;t.to=b,t.cost=c;
        edge1[a].push_back(t);
        t.to=a;
        edge2[b].push_back(t);
    }
    fill(d,d+v,INF);
    d[0]=0;

    memset(vis,0,sizeof(vis));
    pq.push(pr(0,0));
    while(!pq.empty())
    {
        pr t;
        while(!pq.empty())
        {
            t=pq.top();pq.pop();
            if(!vis[t.second])break;
        }
        vis[t.second]=1;
        int v=t.second;
        if(d[v]<t.first)continue;
        for(int i=0;i<edge1[v].size();i++)
        {
            Edge e=edge1[v][i];
            if(d[e.to]>d[v]+e.cost)
            {
                d[e.to]=d[v]+e.cost;
                pq.push(pr(d[e.to],e.to));
            }
        }
    }

    for(int i=0;i<v;i++)
    {
        if(d[i]==INF){flag=0;break;}
        ans+=d[i];
    }
    memset(vis,0,sizeof(vis));
    fill(d,d+v,INF);
    d[0]=0;
    pq.push(pr(0,0));
    while(!pq.empty())
    {
        pr t;
        while(!pq.empty())
        {
            t=pq.top();pq.pop();
            if(!vis[t.second])break;
        }
        vis[t.second]=1;
		int v=t.second;
        if(d[v]<t.first)continue;
		for(int i=0;i<edge2[v].size();i++)
		{
			Edge e=edge2[v][i];
			if (d[e.to]>d[v]+e.cost)
			{
				d[e.to]=d[v]+e.cost;
				pq.push(pr((d[e.to]),e.to));
			}
		}
    }
    for(int i=0;i<v;i++)
    {
        if(d[i]==INF){flag=0;break;}
        ans+=d[i];
    }
    if(flag)printf("%lld\n",ans);
    else puts("0");
    return 0;
}

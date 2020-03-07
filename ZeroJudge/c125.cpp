#include<bits/stdc++.h>
using namespace std;
#define maxn 205
#define INF 10000000
int d[maxn];
bool vis[maxn];
struct P{int x,y;}a[maxn];
struct node
{
    int dis,id;
    bool operator < (const node& b)const
    {
        return dis>b.dis;
    }
};
int dis(P x,P y)
{
    return (x.x-y.x)*(x.x-y.x)+(x.y-y.y)*(x.y-y.y);
}
main()
{
    int n,cas=0;
    while(~scanf("%d",&n) && n)
    {
        for(int i=1;i<=n;i++)scanf("%d%d",&a[i].x,&a[i].y);
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++)d[i]=INF;
        priority_queue<node> pq;
        d[1]=0;
        pq.push((node){0,1});
        while(!pq.empty())
        {
            node t=pq.top();pq.pop();
            if(vis[t.id])continue;
            vis[t.id]=1;
            for(int i=1;i<=n;i++)
            {
                if(d[i]>max(d[t.id],dis(a[i],a[t.id])))
                {
                    d[i]=max(d[t.id],dis(a[i],a[t.id]));
                    pq.push((node){d[i],i});
                }
            }
        }
        printf("Scenario #%d\nFrog Distance = %.3f\n",++cas,sqrt(d[2]));
    }
    return 0;
}

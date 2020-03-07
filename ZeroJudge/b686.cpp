#include<bits/stdc++.h>
using namespace std;
#define inf 1000000000
#define maxn 510
#define maxq 200010
int n,m,r;
struct node
{
    int id,val;
    bool operator < (const node& b)const
    {
        return val<b.val;
    }
};
priority_queue<node> pq;
int a[maxn];
struct que
{
    int g,st,ed,id,ans;
}q[maxq];
bool cmp1(que x,que y){return x.g>y.g;}
bool cmp2(que x,que y){return x.id<y.id;}
int ans[maxq];
int dis[maxn][maxn];
bool ok[maxn];
main()
{
    scanf("%d%d%d",&n,&m,&r);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),pq.push({i,a[i]});
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[i][j]=inf;
    for(int i=1;i<=m;i++)
    {
        int x,y,d;scanf("%d%d%d",&x,&y,&d);
        dis[x][y]=min(dis[y][x],d);
        dis[y][x]=dis[x][y];
    }
    for(int i=1;i<=r;i++)scanf("%d%d%d",&q[i].g,&q[i].st,&q[i].ed),q[i].id=i;
    sort(q+1,q+r+1,cmp1);
    for(int i=1;i<=r;i++)
    {
        while(!pq.empty() && pq.top().val>=q[i].g)
        {
            int val=pq.top().val,id=pq.top().id;
            pq.pop();
            ok[id]=1;
            for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
                dis[i][j]=min(dis[i][j],dis[i][id]+dis[id][j]);
        }
        int st=q[i].st,ed=q[i].ed;
        if(ok[st] && ok[ed] && dis[st][ed]!=inf)q[i].ans=dis[st][ed];
        else q[i].ans=-1;
    }
    sort(q+1,q+r+1,cmp2);
    for(int i=1;i<=r;i++)printf("%d\n",q[i].ans);
    return 0;
}
/*
6 5 5
5 4 1 3 2 6
1 3 3
1 4 1
2 4 6
2 5 1
3 5 2
1 1 2
2 1 2
3 1 2
4 1 2
1 5 3
*/

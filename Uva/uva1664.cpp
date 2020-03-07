#include<cstdio>
#include<algorithm>
using namespace std;
#define maxn 200000+5
struct node
{
    int cnt;
    long long sum;
}town[maxn];

int fa[maxn];
int finds(int x)
{
    return fa[x]==x?x:fa[x]=finds(fa[x]);
}
struct Edge
{
    int u,v,cap;
    bool operator < (const Edge &y) const {
        return cap > y.cap;
    }
}road[maxn];
main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        for(int i=1;i<n;i++)scanf("%d%d%d",&road[i].u,&road[i].v,&road[i].cap);
        for(int i=1;i<=n;i++)
        {
            fa[i]=i;town[i].cnt=1;town[i].sum=0;
        }
        sort(road+1,road+n);
        for(int i=1;i<n;i++)
        {
            int x=finds(road[i].u),y=finds(road[i].v);
            long long t1=town[x].sum+(long long)town[y].cnt*(long long)road[i].cap;
            long long t2=town[y].sum+(long long)town[x].cnt*(long long)road[i].cap;
            if(t1>t2)swap(x,y),swap(t1,t2);
            fa[x]=y;
            town[y].sum=t2;
            town[y].cnt+=town[x].cnt;
        }
        printf("%lld\n",town[finds(1)].sum);
    }
    return 0;
}

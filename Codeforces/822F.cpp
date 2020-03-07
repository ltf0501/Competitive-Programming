#include<bits/stdc++.h>
using namespace std;
#define maxn 105
#define pii pair<int,int>
#define F first
#define S second
vector<int> g[maxn];
vector<pii> edge;
int n;
double ti[maxn];
int p[maxn];
void dfs(int u,int fa,double t)
{
    if(t>=2.0)t-=2.0;
    int deg=g[u].size();
    p[u]=fa;
    int cnt=0;
    for(int i=0;i<deg;i++)
    {
        int m=g[u][i];
        int v=(edge[m].F==u) ? edge[m].S : edge[m].F;
        if(v==fa)continue;
        ti[m]=t+(1.0*(++cnt)*2)/(deg*1.0);
        if(ti[m]>=2.0)ti[m]-=2.0;
        //printf("%d %f\n",m,ti[m]);
        dfs(v,u,ti[m]+1.0);
    }
}
main()
{
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        edge.push_back(pii(x,y));
        int m=edge.size();
        g[x].push_back(m-1),g[y].push_back(m-1);
    }
    printf("%d\n",n-1);
    dfs(1,0,0.0);
    for(int i=1;i<n;i++)
    {
        printf("1 %d ",i);
        pii t=edge[i-1];
        int u=(p[t.F]==t.S) ? t.S : t.F;
        int v=t.F+t.S-u;
        if(ti[i-1]<1.0)printf("%d %d %f\n",u,v,ti[i-1]);
        else printf("%d %d %f\n",v,u,ti[i-1]-1.0);
    }
    return 0;
}

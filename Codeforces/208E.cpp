#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
#define ALL(v) v.begin(),v.end()
int n;
vector<int> g[maxn],rt,umr[maxn];
int anc[20][maxn];
int in[maxn],out[maxn],dfs_clock,dep[maxn];
void dfs(int u,int d)
{
    dep[u]=d,in[u]=++dfs_clock;
    umr[d].push_back(in[u]);
    for(int v : g[u])
        dfs(v,d+1);
    out[u]=dfs_clock;
}
void pre()
{
    for(int u : rt)dfs(u,0);
    for(int j=1;j<=17;j++)
        for(int i=1;i<=n;i++)anc[j][i]=anc[j-1][anc[j-1][i]];
}
int cal(int v,int p)
{
    int ret=v;
    for(int i=17;i>=0;i--)
        if((1<<i)&p)ret=anc[i][ret];
    return ret;
}
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int p;scanf("%d",&p);
        if(p)g[p].push_back(i),anc[0][i]=p;
        else rt.push_back(i);
    }
    pre();
    int q;scanf("%d",&q);
    while(q--)
    {
        int v,p;scanf("%d%d",&v,&p);
        v=cal(v,p);
        //printf("v=%d\n",v);
        if(!v){printf("0 ");continue;}
        int d=dep[v]+p;
        int l=lower_bound(ALL(umr[d]),in[v])-umr[d].begin();
        int r=upper_bound(ALL(umr[d]),out[v])-umr[d].begin();
        printf("%d ",r-l-1);
    }
    return 0;
}

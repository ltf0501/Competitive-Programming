#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
#define ll long long
vector<int> g[maxn];
int n,L;
ll S;
int w[maxn],p[maxn];
int anc[20][maxn],dep[maxn],up[maxn],path[maxn];
ll sum[maxn];
void dfs(int u)
{
    sum[u]=sum[p[u]]+w[u];
    dep[u]=dep[p[u]]+1;
    int dis=L-1;
    int tmp=u;
    for(int i=17;i>=0;i--)if(anc[i][tmp] && (1<<i)<=dis)
    {
        int k=anc[i][tmp];
        if(sum[u]-sum[k]+w[k]<=S)
            dis-=(1<<i),tmp=anc[i][tmp];
    }
    up[u]=tmp;
    for(int v : g[u])dfs(v);
}
int cal(int u)
{
    int ret=0;
    int tmp=-1;
    for(int v : g[u])
    {
        ret+=cal(v);
        if(path[v]==v)continue;
        if(tmp==-1 || dep[path[v]]<dep[tmp])
            tmp=path[v];
    }
    if(tmp==-1)
        ret++,tmp=up[u];
    path[u]=tmp;
    return ret;
}
main()
{
    scanf("%d%d%lld",&n,&L,&S);
    for(int i=1;i<=n;i++)scanf("%d",&w[i]);
    for(int i=2;i<=n;i++)scanf("%d",&p[i]),g[p[i]].push_back(i);
    for(int i=1;i<=n;i++)anc[0][i]=p[i];
    for(int j=1;j<=17;j++)
        for(int i=1;i<=n;i++)anc[j][i]=anc[j-1][anc[j-1][i]];
    for(int i=1;i<=n;i++)
        if(w[i]>S)return 0*puts("-1");
    dfs(1);
    printf("%d\n",cal(1));
    return 0;
}

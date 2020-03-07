#include<bits/stdc++.h>
using namespace std;
#define maxn 35000
int n,q;
vector<int> g[maxn];
int a[maxn],c[maxn];
int in[maxn],out[maxn];
int dfs_clock,cnt;
void dfs(int u,int fa)
{
    in[u]=++dfs_clock;
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(v==fa)continue;
        dfs(v,u);
    }
    out[u]=++dfs_clock;
}
int sum(int x)
{
    int ret=0;
    while(x>0)ret+=c[x],x-=(x&-x);
    return ret;
}
void add(int x,int d)
{
    while(x<=2*n)c[x]+=d,x+=(x&-x);
}
main()
{
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++)g[i].clear();
        for(int i=0;i<n-1;i++)
        {
            int a,b;scanf("%d%d",&a,&b);
            g[a].push_back(b);g[b].push_back(a);
        }
        dfs_clock=cnt=0;
        dfs(0,-1);
        memset(c,0,sizeof(c));
        int q;scanf("%d",&q);
        while(q--)
        {
            int x,y;scanf("%d%d",&x,&y);
            add(in[x],y);add(out[x]+1,-y);
            printf("%d\n",sum(in[x]));
        }

    }
    return 0;
}

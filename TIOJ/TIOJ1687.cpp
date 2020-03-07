#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
int anc[maxn][20];
vector<int> g[maxn];
int fa[maxn],in[maxn],out[maxn],dfs_clock=0;
int n;
void dfs(int u,int f)
{
    in[u]=++dfs_clock;
    fa[u]=f;
    for(int v : g[u])
    {
        if(v==f)continue;
        dfs(v,u);
    }
    out[u]=++dfs_clock;
}
void build()
{
    for(int i=0;(1<<i)<=n;i++)for(int j=1;j<=n;j++)
        anc[j][i]=(i==0) ? fa[j] : anc[anc[j][i-1]][i-1];
}
bool ancestor(int x,int y)//判斷x是否為y祖先
{
    if(in[x]<=in[y] && out[x]>=out[y])return 1;
    return 0;
}
int LCA(int x,int y)
{
    if(ancestor(x,y))return x;
    if(ancestor(y,x))return y;
    for(int i=19;i>=0;i--)
    {
        if(!ancestor(anc[x][i],y))x=anc[x][i];
    }
    return fa[x];
}
int query(int x,int dis)
{
    if(!dis)return x;
    for(int i=19;dis;i--)if((1<<i)<=dis)
    {
        x=anc[x][i];
        dis^=(1<<i);
    }
    return x;
}
int dis(int x,int y)//判斷y到其祖先x的距離
{
    if(!ancestor(x,y))return -1;
    if(x==y)return 0;
    int sum=0;
    for(int i=19;i>=0;i--)
    {
        if(!ancestor(anc[y][i],x))y=anc[y][i],sum+=(1<<i);
    }
    sum++;
    return sum;
}
main()
{
    int q;scanf("%d%d",&n,&q);
    for(int i=0;i<n-1;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        g[x].push_back(y),g[y].push_back(x);
    }
    in[0]=0;
    dfs(1,0);
    out[0]=++dfs_clock;
    build();
    while(q--)
    {
        int x,y,k;scanf("%d%d%d",&x,&y,&k);
        int s=LCA(x,y);
        int d1=dis(s,x),d2=dis(s,y);
        if(s==x)
        {
            int t=query(y,k);
            if(!ancestor(s,t))puts("-1");
            else printf("%d\n",query(y,d2-k));
        }
        else if(s==y)
        {
            int t=query(x,k);
            if(!ancestor(s,t))puts("-1");
            else printf("%d\n",t);
        }
        else
        {
            if(d1+d2<k)puts("-1");
            else if(k<=d1)printf("%d\n",query(x,k));
            else printf("%d\n",query(y,d1+d2-k));
        }
    }
    return 0;
}

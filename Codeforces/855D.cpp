#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
struct E{int to,type;};
vector<E> g[maxn];
int n;
int sp[maxn],pt[maxn];
int in[maxn],out[maxn],dfs_clock=0;
int anc[18][maxn];
void dfs(int u,int fa)
{
    in[u]=++dfs_clock;
    anc[0][u]=fa;
    for(E i : g[u])if(i.to!=fa)
    {
        int v=i.to,t=i.type;
        if(t==0)
        {
            pt[v]=v;
            sp[v]=sp[u];
        }
        else
        {
            sp[v]=v;
            pt[v]=pt[u];
        }
        dfs(v,u);
    }
    out[u]=++dfs_clock;
}
bool ancestor(int x,int y){return in[x]<=in[y] && out[x]>=out[y];}
void pre()
{
    for(int i=1;i<=17;i++)for(int j=1;j<=n;j++)
        anc[i][j]=anc[i-1][anc[i-1][j]];
}
int LCA(int x,int y)
{
    if(ancestor(x,y))return x;
    if(ancestor(y,x))return y;
    for(int i=17;i>=0;i--)
        if(!ancestor(anc[i][x],y))x=anc[i][x];
    return anc[0][x];
}
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x,t;scanf("%d%d",&x,&t);
        if(x!=-1)g[i].push_back({x,t}),g[x].push_back({i,t});
    }
    for(int i=1;i<=n;i++)
        if(!in[i])sp[i]=pt[i]=i,dfs(i,0);
    out[0]=++dfs_clock;
    pre();
    int q;scanf("%d",&q);
    while(q--)
    {
        int t,x,y;scanf("%d%d%d",&t,&x,&y);
        if(x==y){puts("NO");continue;}
        if(t==1)
        {
            if(ancestor(x,y) && ancestor(sp[y],x))puts("YES");
            else puts("NO");
        }
        else
        {
            int l=LCA(x,y);
            if(!l || l==y){puts("NO");continue;}
            if(ancestor(sp[x],l) && ancestor(pt[y],l))puts("YES");
            else puts("NO");
        }
    }
    return 0;
}
/*
3
-1 -1
-1 -1
-1 -1
2
1 3 3
1 1 3

*/

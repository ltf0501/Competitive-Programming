#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
vector<int> g[maxn];
int n,q,anc[20][maxn];
int in[maxn],out[maxn],dfs_clock=0,lv[maxn];
void dfs(int u,int fa,int d)
{
    lv[u]=d;
    in[u]=++dfs_clock;
    anc[0][u]=fa;
    for(int v : g[u])if(v!=fa)
        dfs(v,u,d+1);
    out[u]=++dfs_clock;
}
bool ancestor(int x,int y){return in[x]<=in[y] && out[x]>=out[y];}
void build()
{
    for(int j=1;j<=17;j++)for(int i=1;i<=n;i++)
        anc[j][i]=anc[j-1][anc[j-1][i]];
}
int LCA(int x,int y)
{
    if(ancestor(x,y))return x;
    if(ancestor(y,x))return y;
    for(int i=17;i>=0;i--)if(!ancestor(anc[i][x],y))
        x=anc[i][x];
    x=anc[0][x];
    return x;
}
int query(int a,int b,int c)
{
    int z=LCA(b,c);
    int ab=LCA(a,b);
    int ac=LCA(a,c);
    return (lv[a]+lv[b]-lv[ab]*2+1 +
           lv[a]+lv[c]-lv[ac]*2+1 -
           (lv[b]+lv[c]-lv[z]*2))/2;
}
main()
{
    scanf("%d%d",&n,&q);
    for(int i=2;i<=n;i++)
    {
        int x;scanf("%d",&x);
        g[i].push_back(x),g[x].push_back(i);
    }
    dfs(1,0,0);
    out[0]=++dfs_clock;
    build();
    while(q--)
    {
        int a,b,c;scanf("%d%d%d",&a,&b,&c);
        //printf("%d\n",query(a,b,c));
        int ans=max(query(a,b,c),max(query(b,c,a),query(c,a,b)));
        printf("%d\n",ans);
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
vector<int> g[maxn];
int p[maxn],anc[20][maxn];
int n,m;
int in[maxn],out[maxn],dfs_clock;
int go[maxn],up[20][maxn];
void dfs1(int u)
{
    in[u]=++dfs_clock;
    for(int v : g[u])
        dfs1(v);
    out[u]=dfs_clock;
}
bool ancestor(int x,int y){return in[x]<=in[y] && out[x]>=out[y];}
int LCA(int u,int v)
{
    if(ancestor(u,v))return u;
    if(ancestor(v,u))return v;
    for(int i=17;i>=0;i--)
        if(!ancestor(anc[i][u],v))u=anc[i][u];
    return p[u];
}
void dfs2(int u)
{
    for(int v : g[u])
    {
        dfs2(v);
        if(ancestor(up[0][v],up[0][u]))up[0][u]=up[0][v];
    }
}
int check(int x,int l)
{
    int ret=0;
    for(int i=17;i>=0;i--)
        if(!ancestor(up[i][x],l))ret+=(1<<i),x=up[i][x];
    if(!ancestor(up[0][x],l))return -1;
    return ret+1;
}
int climb(int x,int d)
{
    int u=x;
    for(int i=17;i>=0;i--)
        if(d&(1<<i))u=up[i][u];
    return u;
}
vector<int> v[maxn<<2];
void update(int l,int r,int o,int x,int y)
{
    v[o].push_back(y);
    if(l==r)return ;
    int m=(l+r)>>1;
    if(x<=m)update(l,m,o<<1,x,y);
    else update(m+1,r,o<<1|1,x,y);
}
void build(int l,int r,int o)
{
    sort(v[o].begin(),v[o].end());
    if(l==r)return ;
    int m=(l+r)>>1;
    build(l,m,o<<1),build(m+1,r,o<<1|1);
}
bool query(int l,int r,int o,int ql,int qr,int le,int ri)
{
    if(ql<=l && r<=qr)
    {
        int k=lower_bound(v[o].begin(),v[o].end(),le)-v[o].begin();
        if(k<v[o].size() && v[o][k]<=ri)return 1;
        return 0;
    }
    int m=(l+r)>>1;
    if(ql<=m)
    {
        if(query(l,m,o<<1,ql,qr,le,ri))return 1;
    }
    if(qr>m)
    {
        if(query(m+1,r,o<<1|1,ql,qr,le,ri))return 1;
    }
    return 0;
}
main()
{
    scanf("%d",&n);
    for(int i=2;i<=n;i++)
    {
        scanf("%d",&p[i]);
        g[p[i]].push_back(i);
    }
    p[1]=1;
    for(int i=1;i<=n;i++)anc[0][i]=p[i];
    for(int k=1;k<=17;k++)
        for(int i=1;i<=n;i++)anc[k][i]=anc[k-1][anc[k-1][i]];
    dfs1(1);
    scanf("%d",&m);
    memset(go,-1,sizeof(go));
    for(int i=1;i<=m;i++)
    {
        int u,v;scanf("%d%d",&u,&v);
        int l=LCA(u,v);
        //printf("LCA = %d\n",l);
        if(go[u]==-1 || ancestor(l,go[u]))go[u]=l;
        if(go[v]==-1 || ancestor(l,go[v]))go[v]=l;
        update(1,n,1,in[u],in[v]);
        update(1,n,1,in[v],in[u]);
    }
    build(1,n,1);
    for(int i=1;i<=n;i++)up[0][i]=((go[i]==-1) ? i : go[i]);
    dfs2(1);
    for(int k=1;k<=17;k++)
        for(int i=1;i<=n;i++)up[k][i]=up[k-1][up[k-1][i]];
    int q;scanf("%d",&q);
    while(q--)
    {
        int x,y;scanf("%d%d",&x,&y);
        if(!ancestor(x,y))swap(x,y);
        if(ancestor(x,y)){printf("%d\n",check(y,x));continue;}
        int l=LCA(x,y);
        int a=check(x,l),b=check(y,l);
        //printf("%d %d %d\n",a,b,l);
        if(a==-1 || b==-1){puts("-1");continue;}
        int u=climb(x,a-1),v=climb(y,b-1);
        int ans=a+b-2;
        if(query(1,n,1,in[u],out[u],in[v],out[v]))ans++;
        else ans+=2;
        printf("%d\n",ans);
    }
    return 0;
}

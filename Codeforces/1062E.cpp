#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
int n,q;
vector<int> g[maxn];
int in[maxn],out[maxn],dfs_clock,dep[maxn];
int anc[20][maxn];
void dfs(int u,int fa)
{
    in[u]=++dfs_clock;
    for(int v : g[u])dep[v]=dep[u]+1,dfs(v,u);
    out[u]=dfs_clock;
}
void pre()
{
    for(int j=1;j<=17;j++)
        for(int i=1;i<=n;i++)anc[j][i]=anc[j-1][anc[j-1][i]];
}
bool ancestor(int x,int y){return in[x]<=in[y] && out[x]>=out[y];}
int LCA(int x,int y)
{
    if(!x)return y;
    if(!y)return x;
    if(ancestor(x,y))return x;
    if(ancestor(y,x))return y;
    for(int i=17;i>=0;i--)if(!ancestor(anc[i][x],y))
        x=anc[i][x];
    return anc[0][x];
}
#define pii pair<int,int>
#define F first
#define S second
pii mi[maxn<<2],mx[maxn<<2];
void push_up(int o){mi[o]=min(mi[o<<1],mi[o<<1|1]),mx[o]=max(mx[o<<1],mx[o<<1|1]);}
void build(int l,int r,int o)
{
    if(l==r){mi[o]=mx[o]=pii(in[l],l);return ;}
    int m=(l+r)>>1;
    build(l,m,o<<1),build(m+1,r,o<<1|1);
    push_up(o);
}
pii query(int l,int r,int o,int ql,int qr,bool flag)
{
    if(ql<=l && r<=qr)return flag ? mx[o] : mi[o];
    int m=(l+r)>>1;
    if(qr<=m)return query(l,m,o<<1,ql,qr,flag);
    if(ql>m)return query(m+1,r,o<<1|1,ql,qr,flag);
    pii le=query(l,m,o<<1,ql,qr,flag);
    pii ri=query(m+1,r,o<<1|1,ql,qr,flag);
    return flag ? max(le,ri) : min(le,ri);
}
pii cal(int l,int r,pii pos)
{
    int m=pos.S;
    int u=0,v=0;
    if(l<=m-1)u=LCA(query(1,n,1,l,m-1,0).S,query(1,n,1,l,m-1,1).S);
    if(r>=m+1)v=LCA(query(1,n,1,m+1,r,0).S,query(1,n,1,m+1,r,1).S);
    int L=LCA(u,v);
    return pii(dep[L],m);
}
main()
{
    scanf("%d%d",&n,&q);
    for(int i=2;i<=n;i++)
    {
        int p;scanf("%d",&p);
        g[p].push_back(i),anc[0][i]=p;
    }
    dfs(1,0);out[0]=dfs_clock;
    pre();
    //for(int i=1;i<=n;i++)printf("%d ",in[i]);puts("");
    //for(int i=1;i<=n;i++)printf("%d ",out[i]);puts("");
    build(1,n,1);
    while(q--)
    {
        int l,r;scanf("%d%d",&l,&r);
        pii ans=pii(0,1);
        for(int i=0;i<2;i++)
        {
            pii pos=query(1,n,1,l,r,i);
            //printf("%d: %d %d\n",i,pos.S,pos.F);
            ans=max(ans,cal(l,r,pos));
        }
        printf("%d %d\n",ans.S,ans.F);
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
#define ll long long
vector<int> g1[maxn],g2[maxn];
int b[maxn],sz[maxn],r[maxn],c[maxn];
int in[maxn],out[maxn],dfs_clock;
int anc1[18][maxn],dep[maxn];
ll a[maxn],val[maxn];
int n,m,Q;
struct node
{
    node *l,*r;
    int val;
    node(int v=0)
    {
        l=r=NULL;
        val=v;
    }
    void push_up(){val=l->val+r->val;}
}*root[maxn];
node *build(int l,int r)
{
    node *v=new node();
    if(l==r)return v;
    int m=(l+r)>>1;
    v->l=build(l,m),v->r=build(m+1,r);
    return v;
}
node *update(node *old,int l,int r,int pos,int val)
{
    if(l==r)return new node(old->val+val);
    int m=(l+r)>>1;
    node *v=new node();
    if(pos<=m)
    {
        v->l=update(old->l,l,m,pos,val);
        v->r=old->r;
    }
    else
    {
        v->l=old->l;
        v->r=update(old->r,m+1,r,pos,val);
    }
    v->push_up();
    return v;
}
int query(node *a,node *b,int l,int r,int k)
{
    if(l==r)return l;
    int m=(l+r)>>1;
    int tmp=(b->l->val)-(a->l->val);
    ///printf("tmp,k=%d %d\n",tmp,k);
    if(k<=tmp)return query(a->l,b->l,l,m,k);
    else return query(a->r,b->r,m+1,r,k-tmp);
}
void dfs(int u,int fa,int d)
{
    dep[u]=d;sz[u]=1;anc1[0][u]=fa;
    in[u]=++dfs_clock;b[dfs_clock]=u;
    for(int i=0;i<g1[u].size();i++)
    {
        int v=g1[u][i];
        if(v==fa)continue;
        dfs(v,u,d+1);sz[u]+=sz[v];
    }
    out[u]=dfs_clock;
}
void pre()
{
    for(int i=1;i<=17;i++)
        for(int j=1;j<=n;j++)anc1[i][j]=anc1[i-1][anc1[i-1][j]];
}
bool ancestor(int x,int y){return in[x]<=in[y] && out[x]>=out[y];}
int LCA(int x,int y)
{
    if(ancestor(x,y))return x;
    if(ancestor(y,x))return y;
    for(int i=17;i>=0;i--)if(!ancestor(anc1[i][x],y))
        x=anc1[i][x];
    return anc1[0][x];
}
int get_id(int x,int s)
{
    int l=1,r=s+1;
    while(l+1<r)
    {
        int m=(l+r)>>1;
        if(a[m]<x)l=m;
        else r=m;
    }
    return l;
}
int anc2[18][maxn],in2[maxn],out2[maxn],dfs_clock2;
ll ancsum[18][maxn];
void dfs2(int u,int fa)
{
    anc2[0][u]=fa;
    ancsum[0][u]=val[u];
    in2[u]=++dfs_clock2;
    for(int i=0;i<g2[u].size();i++)
    {
        int v=g2[u][i];
        if(v==fa)continue;
        dfs2(v,u);
    }
    out2[u]=dfs_clock2;
}
void pre2()
{
    for(int i=1;i<=17;i++)
        for(int j=1;j<=n;j++)
            anc2[i][j]=anc2[i-1][anc2[i-1][j]],
            ancsum[i][j]=ancsum[i-1][j]+ancsum[i-1][anc2[i-1][j]];
}
bool ancestor2(int x,int y){return in2[x]<=in2[y] && out2[x]>=out2[y];}
int LCA2(int x,int y)
{
    if(ancestor2(x,y))return x;
    if(ancestor2(y,x))return y;
    for(int i=17;i>=0;i--)if(!ancestor2(anc2[i][x],y))
        x=anc2[i][x];
    return anc2[0][x];
}
ll get_dist(int x,int y,int &p,int &q,int &l)
{
    l=LCA2(x,y);
    ll ret=0;
    if(x!=l)
    {
        for(int i=17;i>=0;i--)if(!ancestor(anc2[i][x],l))
            ret+=ancsum[i][x],x=anc2[i][x];
        ret+=ancsum[0][x];
    }
    if(y!=l)
    {
        for(int i=17;i>=0;i--)if(!ancestor(anc2[i][y],l))
            ret+=ancsum[i][y],y=anc2[i][y];
        ret+=ancsum[0][y];
    }
    p=x,q=y;
    return ret;
}
/*
void print(node *o)
{
    if(!o)return ;
    printf("%d ",o->val);
    print(o->l),print(o->r);
}
*/
int main()
{
    scanf("%d%d%d",&n,&m,&Q);
    for(int i=1;i<n;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        g1[x].push_back(y),g1[y].push_back(x);
    }
    dfs(1,0,0);out[0]=dfs_clock;
    pre();
    root[0]=build(1,n);
    for(int i=1;i<=n;i++)root[i]=update(root[i-1],1,n,b[i],1);
    ///for(int i=1;i<=n;i++)print(root[i]),puts("");
    int num=sz[1];r[1]=1;
    for(int i=2;i<=m+1;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        r[i]=x;
        a[i]=num;
        int id=get_id(y,i-1);
        g2[i].push_back(id),g2[id].push_back(i);
        int k=query(root[in[r[id]]-1],root[out[r[id]]],1,n,y-a[id]);
        ///printf("%d\n",k);
        c[i]=k;
        val[i]=dep[k]-dep[r[id]]+1;
        num+=sz[x];
    }
    ///for(int i=1;i<=m+1;i++)printf("%d ",val[i]);puts("");
    ///for(int i=1;i<=m+1;i++)printf("%d ",c[i]);puts("");
    dfs2(1,0);out2[0]=dfs_clock2;
    pre2();
    while(Q--)
    {
        int x,y;scanf("%d%d",&x,&y);
        int u=get_id(x,m+1),v=get_id(y,m+1);
        int k_u=query(root[in[r[u]]-1],root[out[r[u]]],1,n,x-a[u]);
        int k_v=query(root[in[r[v]]-1],root[out[r[v]]],1,n,y-a[v]);
        ll ans=(dep[k_u]-dep[r[u]])+(dep[k_v]-dep[r[v]]);
        int p,q,l;
        ans+=get_dist(u,v,p,q,l);
        if(u==l)p=k_u;
        else p=c[p];
        if(v==l)q=k_v;
        else q=c[q];
        //printf("%d %d\n",p,q);
        int L=LCA(p,q);
        //printf("L = %d\n",L);
        ans-=2*(dep[L]-dep[r[l]]);
        printf("%lld\n",ans);
    }
    return 0;
}
/*
5 2 100
1 4
1 3
4 2
4 5
4 3
3 2
6 9
1 8
5 3
*/

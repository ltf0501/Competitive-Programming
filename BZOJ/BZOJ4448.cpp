#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
struct node
{
    node *l,*r;
    int val;
    node(int v=0)
    {
        l=r=NULL;
        val=v;
    }
    void push_up()
    {
        val=l->val+r->val;
    }
}*root[maxn];
int a[maxn];
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
    if(!pos)return old;
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
int query(node *a,node *b,node *c,node *d,int l,int r,int k)
{
    if(k<=0)return 0;
    if(r<=k)return (a->val)+(b->val)-(c->val)-(d->val);
    int m=(l+r)>>1;
    if(k<=m)return query(a->l,b->l,c->l,d->l,l,m,k);
    else return (a->l->val)+(b->l->val)-(c->l->val)-(d->l->val)+query(a->r,b->r,c->r,d->r,m+1,r,k);
}
vector<int> g[maxn];
int anc[20][maxn],n,M;
int in[maxn],out[maxn],dfs_clock=0,dep[maxn];
void dfs(int u,int fa,int d)
{
    dep[u]=d;
    in[u]=++dfs_clock;
    anc[0][u]=fa;
    root[u]=update(root[fa],1,M,a[u],1);
    //for(int v : g[u])dfs(v,u,d+1);
    for(int i=0;i<g[u].size();i++)dfs(g[u][i],u,d+1);
    out[u]=++dfs_clock;
}
void pre()
{
    for(int i=1;i<20;i++)
        for(int j=1;j<=n;j++)anc[i][j]=anc[i-1][anc[i-1][j]];
}
bool ancestor(int x,int y){return in[x]<=in[y] && out[x]>=out[y];}
int LCA(int x,int y)
{
    if(ancestor(x,y))return x;
    if(ancestor(y,x))return y;
    for(int i=19;i>=0;i--)if(!ancestor(anc[i][x],y))
        x=anc[i][x];
    return anc[0][x];
}
struct Q{int x,y,c;}q[maxn];
/*
void print(node *o)
{
    if(!o)return ;
    printf("%d ",o->val);
    print(o->l);print(o->r);
}
*/
int main()
{
    scanf("%d",&n);
    int t;
    for(int i=1;i<=n;i++)
    {
        int x;scanf("%d",&x);
        if(!x)t=i;
        g[x].push_back(i);
    }
    scanf("%d",&M);
    for(int i=1;i<=M;i++)
    {
        int type;scanf("%d",&type);
        if(type==1)
        {
            int x,y,c;
            scanf("%d%d%d",&x,&y,&c);
            q[i].x=x,q[i].y=y,q[i].c=i-c-1;
        }
        else
        {
            int x;scanf("%d",&x);
            a[x]=i;
        }
    }
    root[0]=build(1,M);
    dfs(t,0,1);out[0]=++dfs_clock;
    //for(int i=1;i<=n;i++)print(root[i]),puts("");
    pre();
    for(int i=1;i<=M;i++)if(q[i].x)
    {
        int a=q[i].x,b=q[i].y;
        int c=LCA(a,b);
        int d=anc[0][c];
        printf("%d %d\n",dep[a]+dep[b]-dep[c]-dep[d],query(root[a],root[b],root[c],root[d],1,M,q[i].c));
    }
    return 0;
}
/*
7
0 1 1 2 2 3 3
6
1 4 7 0
2 1
2 4
2 7
1 4 7 1
1 4 7 3
*/

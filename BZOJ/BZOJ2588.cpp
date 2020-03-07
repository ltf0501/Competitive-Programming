#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
vector<int> g[maxn];
int a[maxn],n,m,M;
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
int query(node *a,node *b,node *c,node *d,int l,int r,int k)
{
    if(l==r)return l;
    int m=(l+r)>>1;
    int tmp=(a->l->val)+(b->l->val)-(c->l->val)-(d->l->val);
    if(k<=tmp)return query(a->l,b->l,c->l,d->l,l,m,k);
    else return query(a->r,b->r,c->r,d->r,m+1,r,k-tmp);
}
int anc[18][maxn],in[maxn],out[maxn],dfs_clock=0;
vector<int> V;
void dfs(int u,int fa)
{
    in[u]=++dfs_clock;
    anc[0][u]=fa;
    root[u]=update(root[fa],1,M,a[u],1);
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(v==fa)continue;
        dfs(v,u);
    }
    out[u]=++dfs_clock;
}
void pre()
{
    for(int i=1;i<=17;i++)
        for(int j=1;j<=n;j++)anc[i][j]=anc[i-1][anc[i-1][j]];
}
bool ancestor(int x,int y){return in[x]<=in[y] && out[x]>=out[y];}
int LCA(int x,int y)
{
    if(ancestor(x,y))return x;
    if(ancestor(y,x))return y;
    for(int i=17;i>=0;i--)if(!ancestor(anc[i][x],y))
        x=anc[i][x];
    return anc[0][x];
}
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
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),V.push_back(a[i]);
    sort(V.begin(),V.end());
    V.resize(unique(V.begin(),V.end())-V.begin());
    for(int i=1;i<=n;i++)a[i]=lower_bound(V.begin(),V.end(),a[i])-V.begin()+1;
    ///for(int i=1;i<=n;i++)printf("%d ",a[i]);puts("");
    M=V.size();
    for(int i=1;i<n;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        g[x].push_back(y),g[y].push_back(x);
    }
    root[0]=build(1,M);
    dfs(1,0);out[0]=++dfs_clock;
    ///for(int i=1;i<=n;i++)print(root[i]),puts("");
    pre();
    int pre_ans=0;
    while(m--)
    {
        int u,v,k;scanf("%d%d%d",&u,&v,&k);
        u^=pre_ans;
        int a=LCA(u,v),b=anc[0][a];
        ///printf("%d %d %d %d\n",u,v,a,b);
        pre_ans=V[query(root[u],root[v],root[a],root[b],1,M,k)-1];
        printf("%d",pre_ans);
        if(m)puts("");
    }
    return 0;
}
/*
8 5
105 2 9 3 8 5 7 7
1 2
1 3
1 4
3 5
3 6
3 7
4 8
2 5 1
0 5 2
10 5 3
11 5 4
110 8 2
*/

#include<bits/stdc++.h>
using namespace std;
#define maxp 3000010
#define maxn 50010
#define maxq 5010
vector<int> v;
struct Q
{
    char type[2];int a,b,c;
    void input()
    {
        scanf("%s",type);
        if(type[0]=='C')scanf("%d%d",&a,&b);
        else scanf("%d%d%d",&a,&b,&c);
    }
}q[maxq];
int n,m;
int a[maxn];
struct node
{
    static node p[maxp];
    node *l,*r;
    int val;
    node(int v=0)
    {
        l=r=NULL;
        val=v;
    }
    void push_up(){val=l->val+r->val;}
}node::p[maxp],*ptr=node::p;
node *build(int l,int r)
{
    node *u=new(ptr++) node();
    if(l==r)return u;
    int m=(l+r)>>1;
    u->l=build(l,m);
    u->r=build(m+1,r);
    return u;
}
node *Get(node *u)
{
    node *v=new(ptr++) node();
    v->l=u->l,v->r=u->r,v->val=u->val;
    return v;
}
node *update(node *u,int l,int r,int x,int val)
{
    if(l==r)return new(ptr++) node(u->val+val);
    int m=(l+r)>>1;
    node *v=new(ptr++) node();
    if(x<=m)
    {
        v->r=u->r;
        v->l=update(u->l,l,m,x,val);
    }
    else
    {
        v->l=u->l;
        v->r=update(u->r,m+1,r,x,val);
    }
    v->push_up();
    return v;
}
int query(int l,int r,int k,node *l_tree,node *r_tree,vector<node*> le,vector<node*> ri)
{
    if(l==r)return l;
    int m=(l+r)>>1;
    int l_sum=l_tree->l->val;
    int r_sum=r_tree->l->val;
    for(node* i : le)l_sum+=i->l->val;
    for(node* i : ri)r_sum+=i->l->val;
    if(k<=r_sum-l_sum)
    {
        for(node* &i : le)i=i->l;
        for(node* &i : ri)i=i->l;
        return query(l,m,k,l_tree->l,r_tree->l,le,ri);
    }
    else
    {
        for(node* &i : le)i=i->r;
        for(node* &i : ri)i=i->r;
        return query(m+1,r,k-r_sum+l_sum,l_tree->r,r_tree->r,le,ri);
    }
}
node *root[maxn];
node *bit[maxn];
main()
{
    scanf("%d%d",&n,&m);
    ptr=node::p;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),v.push_back(a[i]);
    for(int i=1;i<=m;i++)
    {
        q[i].input();
        if(q[i].type[0]=='C')v.push_back(q[i].b);
    }
    sort(v.begin(),v.end());
    v.resize(unique(v.begin(),v.end())-v.begin());
    for(int i=1;i<=n;i++)a[i]=lower_bound(v.begin(),v.end(),a[i])-v.begin()+1;
    for(int i=1;i<=m;i++)
        if(q[i].type[0]=='C')q[i].b=lower_bound(v.begin(),v.end(),q[i].b)-v.begin()+1;
    int N=v.size();
    root[0]=build(1,N);
    for(int i=1;i<=n;i++)
    {
        root[i]=update(root[i-1],1,N,a[i],1);
        bit[i]=Get(root[0]);
    }
    for(int i=1;i<=m;i++)
    {
        if(q[i].type[0]=='Q')
        {
            int l=q[i].a,r=q[i].b,k=q[i].c;
            vector<node*> le,ri;
            for(int j=r;j;j-=j&-j)ri.push_back(bit[j]);
            for(int j=l-1;j;j-=j&-j)le.push_back(bit[j]);
            int pos=query(1,N,k,root[l-1],root[r],le,ri);
            printf("%d\n",v[pos-1]);
        }
        else
        {
            int x=q[i].a,v=q[i].b;
            for(int j=x;j<=n;j+=j&-j)bit[j]=update(bit[j],1,N,a[x],-1);
            for(int j=x;j<=n;j+=j&-j)bit[j]=update(bit[j],1,N,v,1);
            a[x]=v;
        }
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define maxn 60010
#define maxm 10010
#define maxp 3000010
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
    void push_up()
    {
        val=l->val+r->val;
    }
}node::p[maxp],*ptr=node::p;
node *build(int l,int r)
{
    node *u=new(ptr++)node();
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
int a[maxn];
vector<int> v;
node *update(node *u,int l,int r,int pos,int val)
{
    if(l==r)return new(ptr++) node(u->val+val);
    int m=(l+r)>>1;
    node *v=new(ptr++) node();
    if(pos<=m)
    {
        v->l=update(u->l,l,m,pos,val);
        v->r=u->r;
    }
    else
    {
        v->l=u->l;
        v->r=update(u->r,m+1,r,pos,val);
    }
    v->push_up();
    return v;
}
node *root[maxn];
node *bit[maxn];
struct Q
{
    int type,a,b,c;
    void input()
    {
        scanf("%d",&type);
        if(type==1)scanf("%d%d%d",&a,&b,&c);
        else scanf("%d%d",&a,&b);
    }
}q[maxm];
int n,m,N;
int query(int l,int r,int k,node *l_tree,node *r_tree,vector<node*> le,vector<node*> ri)
{
    if(l==r)return l;
    int l_sum=l_tree->l->val;
    int r_sum=r_tree->l->val;
    for(node* i : le)l_sum+=i->l->val;
    for(node* i : ri)r_sum+=i->l->val;
    int m=(l+r)>>1;
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
main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        ptr=node::p;
        v.clear();
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]),v.push_back(a[i]);
        for(int i=1;i<=m;i++)
        {
            q[i].input();
            if(q[i].type==2)v.push_back(q[i].b);
        }
        sort(v.begin(),v.end());
        v.resize(unique(v.begin(),v.end())-v.begin());
        for(int i=1;i<=n;i++)a[i]=lower_bound(v.begin(),v.end(),a[i])-v.begin()+1;
        for(int i=1;i<=m;i++)
            if(q[i].type==2)q[i].b=lower_bound(v.begin(),v.end(),q[i].b)-v.begin()+1;
        N=v.size();
        root[0]=build(1,N);
        for(int i=1;i<=n;i++)
        {
            root[i]=update(root[i-1],1,N,a[i],1);
            bit[i]=Get(root[0]);
        }
        for(int i=1;i<=m;i++)
        {
            if(q[i].type==1)
            {
                vector<node*>le,ri;
                for(int j=q[i].b;j;j-=j&-j)ri.push_back(bit[j]);
                for(int j=q[i].a-1;j;j-=j&-j)le.push_back(bit[j]);
                int pos=query(1,N,q[i].c,root[q[i].a-1],root[q[i].b],le,ri);
                printf("%d\n",v[pos-1]);
            }
            else if(q[i].type==2)
            {
                for(int j=q[i].a;j<=n;j+=(j&(-j)))bit[j]=update(bit[j],1,N,a[q[i].a],-1);
                for(int j=q[i].a;j<=n;j+=(j&(-j)))bit[j]=update(bit[j],1,N,q[i].b,1);
                a[q[i].a]=q[i].b;
            }
            else puts("7122");
        }
    }
    return 0;
}

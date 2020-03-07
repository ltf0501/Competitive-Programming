#include<bits/stdc++.h>
using namespace std;
const int maxn=500010;
struct node
{
    node *l,*r;
    int val;
    node()
    {
        l=r=NULL;
        val=0;
    }
    node(int v)
    {
        l=r=NULL;
        val=v;
    }
    void push_up(){val=l->val+r->val;}
};
node *root[maxn];
node *update(node *u,int l,int r,int pos,int val)
{
    if(l==r)return new node(u->val+val);
    int m=(l+r)>>1;
    node *v=new node();
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
int query(int l,int r,node *ltree,node *rtree,int t)
{
    if(l==r)return l;
    int m=(l+r)>>1;
    if(rtree->l->val-ltree->l->val>t)return query(l,m,ltree->l,rtree->l,t);
    else if(rtree->r->val-ltree->r->val>t)return query(m+1,r,ltree->r,rtree->r,t);
    return 0;
}
main()
{
    int n,q;scanf("%d%d",&n,&q);
    int x;
    for(int i=1;i<=n;i++)scanf("%d",&x),root[i]=update(root[i-1],1,n,x,1);
    //for(int i=1;i<=n;i++)printf("%d ",root[i]->val);puts("");
    while(q--)
    {
        int l,r;scanf("%d%d",&l,&r);
        printf("%d\n",query(1,n,root[l-1],root[r],(r-l+1)/2));
    }
    return 0;
}

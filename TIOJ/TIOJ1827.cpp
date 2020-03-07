#include<bits/stdc++.h>
using namespace std;
#define maxn 100000+10
struct node
{
    node *l,*r;
    int v;
    node(int val)
    {
        l=r=NULL;
        v=val;
    }
};
node *build(int l,int r)
{
    if(l==r)return new node(0);
    int mid=(l+r)>>1;
    node *u=new node(0);
    u->l=build(l,mid);u->r=build(mid+1,r);
    return u;
}
node *update(int l,int r,node *u,int p)
{
    if(l==r)return new node(u->v+1);
    int mid=(l+r)>>1;
    node *v=new node(0);
    if(p<=mid)
    {
        v->r=u->r;
        v->l=update(l,mid,u->l,p);
    }
    else
    {
        v->l=u->l;
        v->r=update(mid+1,r,u->r,p);
    }
    v->v=v->l->v+v->r->v;
    return v;
}
node *root[maxn];
int query(int l,int r,int L,int R,node *u,node *v)
{
    if(l==L && r==R)return v->v-u->v;
    int mid=(L+R)>>1;
    if(r<=mid)return query(l,r,L,mid,u->l,v->l);
    else if(l>mid)return query(l,r,mid+1,R,u->r,v->r);
    else return query(l,mid,L,mid,u->l,v->l)+query(mid+1,r,mid+1,R,u->r,v->r);
}
main()
{
    int n,q;scanf("%d%d",&n,&q);
    root[0]=build(1,n);
    for(int i=1;i<=n;i++)
    {
        int x;scanf("%d",&x);
        root[i]=update(1,n,root[i-1],x);
    }
    while(q--)
    {
        int p,k;scanf("%d%d",&p,&k),p++;
        int l=0,r=n;
        while(r-l>1)
        {
            int mid=(l+r)>>1,lo=max(1,p-mid),hi=min(p+mid,n);
            if(query(1,mid,1,n,root[lo-1],root[hi])>=k)r=mid;
            else l=mid;
        }
        printf("%d\n",r);
    }
    return 0;
}

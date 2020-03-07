#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 300010
struct node
{
    node *l,*r,*pre;
    ll val,tag;
    node(int v)
    {
        pre=l=r=NULL;
        val=v;
        tag=0;
    }

};
int a[maxn];
node *root[maxn];
int n,m;
node *create(node *u)
{
    node *v=new node(0);
    v->pre=u,v->val=u->val,v->tag=u->tag;
    return v;
}
void push_down(node *u,int l,int r)
{
    if(!u->tag)return ;
    if(l!=r)
    {
        int m=(l+r)>>1;
        if(!u->l || !u->r)
        {
            u->l=create(u->pre->l);
            u->r=create(u->pre->r);
        }
        u->l->tag+=u->tag,u->l->val+=u->val;
        u->r->tag+=u->tag,u->r->val+=u->val;
    }
    u->tag=0;
}
void push_up(node *u)
{
    u->val=0;
    if(u->l!=NULL)u->val+=u->l->val;
    if(u->r!=NULL)u->val+=u->r->val;
}
node *build(int l,int r)
{
    if(l==r)return new node(a[l]);
    int m=(l+r)>>1;
    node *u=new node(0);
    u->l=build(l,m),u->r=build(m+1,r);
    push_up(u);
    return u;
}
node *update(int l,int r,node *u,int ql,int qr,int k)
{
    node *v=new node(0);
    if(ql<=l && r<=qr)
    {
        v->tag=u->tag+k;
        v->val=u->val+k*(r-l+1);
        return v;
    }
    int m=(l+r)>>1;
    push_down(u,l,r);
    if(ql<=m)v->l=update(l,m,u->l,ql,qr,k);
    if(qr>m)v->r=update(m+1,r,u->r,ql,qr,k);
    push_up(v);
    return v;
}
ll query(int l,int r,int ql,int qr,node *v)
{
    if(ql<=l && r<=qr)return v->val;
    push_down(v,l,r);
    int m=(l+r)>>1;
    ll ret=0;
    if(ql<=m)ret+=query(l,m,ql,qr,v->l);
    if(qr>m)ret+=query(m+1,r,ql,qr,v->r);
    return ret;
}
void print(node *u)
{
    printf("%d ",u->val);
    if(u->l)print(u->l);
    if(u->r)print(u->r);
}
void print2(node *u)
{
    printf("%d ",u->tag);
    if(u->l)print2(u->l);
    if(u->r)print2(u->r);
}
main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    root[0]=build(1,n);
    print(root[0]);
    puts("");
    print2(root[0]);
    puts("");
    for(int i=1;i<=m;i++)
    {
        int l,r,v;scanf("%d%d%d",&l,&r,&v);
        root[i]=update(1,n,root[i-1],l,r,v);
    }
    int q;scanf("%d",&q);
    while(q--)
    {
        int l,r,L,R;scanf("%d%d%d%d",&l,&r,&L,&R);
        printf("%lld\n",query(1,n,l,r,root[R]));
        print(root[R]);puts("");
        print2(root[R]);puts("");
    }
    return 0;
}
/*
5 3
1 3 2 7 9
1 5 10
1 3 -7
3 5 8
4
1 5 1 3
3 3 3 3
3 4 1 2
2 5 2 3
*/

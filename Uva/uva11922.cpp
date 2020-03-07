#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct node
{
    int val,sum,flip;
    node* ch[2];
    node(int val=0);
    int cmp(int v)
    {
        int d=v-(ch[0]==NULL ? 0 : ch[0]->sum);
        if(d==1) return -1;
        return d<=0 ? 0 : 1;
    }
    void maintain()
    {
        sum=1;
        if(ch[0]!=NULL)sum+=ch[0]->sum;
        if(ch[1]!=NULL)sum+=ch[1]->sum;
    }
    void pushdown()
    {
        if(flip)
        {
            flip=0;
            swap(ch[0],ch[1]);
            if(ch[0]!=NULL)ch[0]->flip=!ch[0]->flip;
            if(ch[1]!=NULL)ch[1]->flip=!ch[1]->flip;
        }
    }
};
node::node(int val)
{
    sum=1;
    flip=0;
    this->val=val;
    ch[0]=ch[1]=NULL;
}
void build(node* &o,int l,int r)
{
    if(l>r)return ;
    int m=l+(r-l)/2;
    o=new node(m);
    build(o->ch[0],l,m-1);
    build(o->ch[1],m+1,r);
    o->maintain();
}
void rot(node* &o,int d)
{
    node* k=o->ch[d^1];
    o->ch[d^1]=k->ch[d];
    k->ch[d]=o;
    o->maintain();
    k->maintain();
    o=k;
}
void splay(node* &o,int k)
{
    o->pushdown();
    int d=o->cmp(k);
    if(d==1)k-=(o->ch[0]==NULL ? 0 : o->ch[0]->sum)+1;
    if(d!=-1)
    {
        node* p=o->ch[d];
        p->pushdown();
        int d2=p->cmp(k);
        int k2=(d2==0 ? k : k-(p->ch[0]==NULL ? 0 : p->ch[0]->sum) - 1);
        if(d2!=-1)
        {
            splay(p->ch[d2],k2);
            if(d==d2)rot(o,d^1);else rot(o->ch[d],d);
        }
        rot(o,d^1);
    }
}
node* mrge(node* l,node* r)
{
    splay(l,l->sum);
    l->ch[1]=r;
    l->maintain();
    return l;
}
void split(node* &o,int k,node* &l,node* &r)
{
    splay(o,k);
    l=o;
    r=o->ch[1];
    o->ch[1]=NULL;
    l->maintain();
}
void print_ans(node* &o)
{
    o->pushdown();
    if(o->ch[0]!=NULL)print_ans(o->ch[0]);
    if(o->val)printf("%d\n",o->val);
    if(o->ch[1]!=NULL)print_ans(o->ch[1]);

    delete o;
    o=NULL;
}
main()
{
    int n,m,x,y;
    while(~scanf("%d%d",&n,&m))
    {
        node* root=NULL;
        node *l,*mid,*r,*o;
        build(root,0,n);
        print_ans(root);
        while(m--)
        {
            scanf("%d%d",&x,&y);
            split(root,x,l,o);
            split(o,y-x+1,mid,r);
            mid->flip^=1;
            root=mrge(mrge(l,r),mid);
        }
        print_ans(root);
    }
    return 0;
}

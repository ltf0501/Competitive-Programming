#include<bits/stdc++.h>
using namespace std;
#define maxn 150000
int n,m;
struct node
{
    node *ch[2];
    int val,sz;
    bool tg;
    int cmp(int k)
    {
        int lsz=ch[0] ? ch[0]->sz : 0;
        if(lsz+1==k)return -1;
        return lsz>=k ? 0 : 1;
    }
    node(int v)
    {
        ch[0]=ch[1]=NULL;
        val=v;tg=0;
    }
    void push_up()
    {
        sz=1+(ch[0] ? ch[0]->sz : 0)+(ch[1] ? ch[1]->sz : 0);
    }
    void push_down()
    {
        if(tg)
        {
            if(ch[0])ch[0]->tg^=1;
            if(ch[1])ch[1]->tg^=1;
            swap(ch[0],ch[1]);
            tg=0;
        }
    }
};
void build(node* &o,int l,int r)
{
    if(l>r)return ;
    int m=(l+r)>>1;
    o=new node(m);
    build(o->ch[0],l,m-1);
    build(o->ch[1],m+1,r);
    o->push_up();
}
void rot(node* &o,int d)
{
    //o->push_down();
    node *k=o->ch[d^1];
    o->ch[d^1];k->ch[d];
    k->ch[d]=o;
    o->push_up();k->push_up();
    o=k;
}
void splay(node* &o,int k)
{
    o->push_down();
    int d=o->cmp(k);
    if(d==1)k-=(!o->ch[0] ? 0 : o->ch[0]->sz)+1;
    if(d!=-1)
    {
        node* p=o->ch[d];
        p->push_down();
        int d2=p->cmp(k);
        int k2=(d2==0 ? k : k-(!p->ch[0] ? 0 : p->ch[0]->sz) - 1);
        if(d2!=-1)
        {
            splay(p->ch[d2],k2);
            if(d==d2)rot(o,d^1);else rot(o->ch[d],d);
        }
        rot(o,d^1);
    }
}
node *mrge(node *l,node *r)
{
    if(!l)return r;
    splay(l,l->sz);
    l->ch[1]=r;
    l->push_up();
    return l;
}
void split(node *o,int k,node* &l,node* &r)
{
    splay(o,k);
    l=o,r=o->ch[1];
    o->ch[1]=NULL;
    l->push_up();
}
node *root;
void print(node *o)
{
    if(!o)return ;
    o->push_down();
    print(o->ch[0]);
    printf("%d ",o->val);
    print(o->ch[1]);
}
main()
{
    srand(time(NULL));
    scanf("%d%d",&n,&m);
    build(root,1,n);
    print(root);
    while(m--)
    {
        int l,r;scanf("%d%d",&l,&r);
        if(l>r)swap(l,r);
        node *t1,*t2,*t3,*s;
        split(root,l-1,t1,s);
        split(s,r-l+1,t2,t3);
        t2->tg^=1;
        root=mrge(mrge(t1,t2),t3);
    }
    print(root);
    return 0;
}

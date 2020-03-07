//«D±ÛÂà¥­¿Å¾ğ
#include<bits/stdc++.h>
using namespace std;
struct node
{
    node *ch[2];
    int val,sz,r,tg;
    node(int v=0)
    {
        sz=1;val=v;r=rand();
        tg=0;
        ch[0]=ch[1]=NULL;
    }
    void maintain()
    {
        sz=1+(ch[0]?ch[0]->sz:0)+(ch[1]?ch[1]->sz:0);
    }
    void push_down()
    {
        if(!tg)return ;
        if(ch[0])ch[0]->tg^=1;
        if(ch[1])ch[1]->tg^=1;
        tg^=1;
        swap(ch[0],ch[1]);
    }
};

int n,m;
node *mrge(node *a,node *b)
{
    if(!b)return a;
    if(!a)return b;
    if(a->r>b->r){a->push_down();a->ch[1]=mrge(a->ch[1],b);a->maintain();return a;}
    b->push_down();b->ch[0]=mrge(a,b->ch[0]);b->maintain();return b;
}
typedef pair<node*,node*> pii;
pii split(node *a,int k)
{
    pii ret;
    if(!a)return pii(NULL,NULL);
    if(k<=0)return pii(NULL,a);
    if(k>=n)return pii(a,NULL);
    a->push_down();
    if(a->ch[0] && a->ch[0]->sz>=k)
    {
        ret=split(a->ch[0],k);
        a->ch[0]=ret.second;
        a->maintain();
        ret.second=a;
    }
    else
    {
        ret=split(a->ch[1],k-(a->ch[0]?a->ch[0]->sz:0)-1);
        a->ch[1]=ret.first;
        a->maintain();
        ret.first=a;
    }
    return ret;
}
node *build(int l,int r)
{
    if(l>r)return NULL;
    int m=(l+r)>>1;
    node *ret=new node(m);
    ret->ch[0]=build(l,m-1);
    ret->ch[1]=build(m+1,r);
    ret->maintain();
    return ret;
}
node *root;
void print(node *o)
{
    o->push_down();
    if(o->ch[0])print(o->ch[0]);
    printf("%d ",o->val);
    if(o->ch[1])print(o->ch[1]);
}
/*
void print2(node *o)
{
    o->push_down();
    printf("%d ",o->val);
    if(o->ch[0])print(o->ch[0]);
    if(o->ch[1])print(o->ch[1]);
}
*/
main()
{
    //srand(time(NULL));
    scanf("%d%d",&n,&m);
    root=build(1,n);///print(root);
    while(m--)
    {
        int l,r;scanf("%d%d",&l,&r);
        pii tmp1=split(root,l-1);

        ///printf("%d\n",tmp1.second->val);
        pii tmp2=split(tmp1.second,r-l+1);
        tmp2.first->tg^=1;
        root=mrge(mrge(tmp1.first,tmp2.first),tmp2.second);
    }
    print(root);puts("");
    return 0;
}

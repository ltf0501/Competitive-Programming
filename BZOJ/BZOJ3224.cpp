#include<bits/stdc++.h>
using namespace std;
struct node
{
    int val,sz,r,cnt;
    node* ch[2];
    int cmp(int k)
    {
        if(k==val)return -1;
        return k<val ? 0 : 1;
    }
    node(int v=0)
    {
        sz=cnt=1;
        ch[0]=ch[1]=NULL;
        val=v;
        r=rand();
    }
    void maintain()
    {
        sz=cnt;
        if(ch[0]!=NULL)sz+=ch[0]->sz;
        if(ch[1]!=NULL)sz+=ch[1]->sz;
    }
};
void rot(node* &o,int d)
{
    node* k=o->ch[d^1];
    o->ch[d^1]=k->ch[d];
    k->ch[d]=o;
    o->maintain(),k->maintain();
    o=k;
}
void insrt(node* &o,int x)
{
    if(o==NULL)
    {
        o=new node(x);
        return ;
    }
    int d=o->cmp(x);
    if(d==-1){o->sz++,o->cnt++;return ;}
    insrt(o->ch[d],x);
    o->maintain();
    if(o->ch[d]->r>o->r)rot(o,d^1);
}
int rk(node *o,int x)
{
    int s=o->ch[0]?o->ch[0]->sz:0;
    if(x==o->val)return s+1;
    if(x<o->val)return rk(o->ch[0],x);
    return s+o->cnt+rk(o->ch[1],x);
}
int kth(node *o,int k)
{
    int s=o->ch[0]?o->ch[0]->sz:0;
    if(k<=s)return kth(o->ch[0],k);
    else if(k<=s+o->cnt)return o->val;
    return kth(o->ch[1],k-s-o->cnt);
}
node* pre(node *o,int x)
{
    node *y=NULL;
    while(o)
    {
        if(x<=o->val)o=o->ch[0];
        else y=o,o=o->ch[1];
    }
    return y;
}
node* pos(node *o,int x)
{
    node *y=NULL;
    while(o)
    {
        if(x>=o->val)o=o->ch[1];
        else y=o,o=o->ch[0];
    }
    return y;
}
void del(node* &o,int x)
{
    if(!o)return ;
    int d=o->cmp(x);
    if(d==-1)
    {
        if(o->cnt>1)o->cnt--,o->sz--;
        else
        {
            if(!o->ch[0])o=o->ch[1];
            else if(!o->ch[1])o=o->ch[0];
            else
            {
                int d2=o->ch[0]->r>o->ch[1]->r?1:0;
                rot(o,d2);del(o->ch[d2],x);
                o->maintain();
            }
        }
        return ;
    }
    del(o->ch[d],x);
    o->maintain();
}
void print(node *o)
{
    if(o->ch[0])print(o->ch[0]);
    for(int i=1;i<=o->cnt;i++)printf("%d ",o->val);
    if(o->ch[1])print(o->ch[1]);
}
node *root;
main()
{
    srand(time(NULL));
    int n;scanf("%d",&n);
    while(n--)
    {
        int type,x;scanf("%d%d",&type,&x);
        if(type==1)insrt(root,x);
        else if(type==2)del(root,x);
        else if(type==3)printf("%d\n",rk(root,x));
        else if(type==4)printf("%d\n",kth(root,x));
        else if(type==5)printf("%d\n",pre(root,x)->val);
        else printf("%d\n",pos(root,x)->val);
        //print(root);
        //puts("");
    }
    return 0;
}

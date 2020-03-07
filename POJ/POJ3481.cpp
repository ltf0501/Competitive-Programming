#include<bits/stdc++.h>
using namespace std;
struct node
{
    node *ch[2];
    int val,id,r;
    bool cmp(int x)
    {
        if(x==val)return -1;
        return x<val ? 0 : 1;
    }
    node(int v,int i)
    {
        ch[0]=ch[1]=NULL;
        val=v,id=i,r=rand();
    }
};
void rot(node* &o,int d)
{
    node *k=o->ch[d^1];
    o->ch[d^1]=k->ch[d];
    k->ch[d]=o;
    o=k;
}
void insrt(node* &o,int x,int i)
{
    if(!o){o=new node(x,i);return ;}
    int d=o->cmp(x);
    if(d==-1)return ;
    insrt(o->ch[d],x,i);
    if(o->ch[d]->r>o->r)rot(o,d^1);
}
void del(node* &o,int x)
{
    if(!o)return ;
    int d=o->cmp(x);
    if(d==-1)
    {
        if(!o->ch[0] || !o->ch[1])
        {
            if(!o->ch[0])o=o->ch[1];
            else o=o->ch[0];
            return ;
        }
        int d2=o->ch[0]->r>o->ch[1]->r ? 1 : 0;
        rot(o,d2);del(o->d2,x);
    }
    else del(o->ch[d],x);
}
int find_min(node *o)
{
    if(!o->ch[0])return o->id;
    return find_min(o->ch[0]);
}
#define pii pair<int,int>
#define F first
#define S second
pii find_max(node *o)
{
    if(!o->ch[1])return o->id;
    return find_max(o->ch[1]);
}
node *root;
main()
{
    int type;
    while(~scanf("%d",&type) && type)
    {
        if(type==1)
        {
            int id,x;scanf("%d%d",&id,&x);
            insrt(root,x,id);
        }
        else if(type==2)
        {
            if(!o)puts("0");
            else
            {

            }
        }
    }
    return 0;
}

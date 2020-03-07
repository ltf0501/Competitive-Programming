#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF=1e11;
int n,m;
int a[maxn];
struct node
{
    node *ch[2];
    ll sum,mxsum,lsum,rsum;
    bool rev,same;
    int val,sz,r;
    int cmp(int v)
    {
        int d=v-(ch[0] ? ch[0]->sz : 0);
        if(d==1)return -1;
        return d>0 ? 1 : 0;
    }
    node(int v)
    {
        ch[0]=ch[1]=NULL;
        sum=mxsum=lsum=rsum=v;
        val=v;
        rev=same=0;
        sz=1,r=rand();
    }
    void push_down()
    {
        if(rev)
        {
            swap(ch[0],ch[1]);
            swap(lsum,rsum);
            ch[0]->rev^=1,ch[1]->rev^=1;
            rev=0;
        }
        if(same)
        {
            ch[0]->same=ch[1]->same=1;
            ch[0]->val=ch[1]->val=val;
            sum=1ll*val*sz;
            if(val>=0)mxsum=lsum=rsum=1ll*val*sz;
            else mxsum=lsum=rsum=val;
        }
    }
    void push_up()
    {
        sz=1,sum=val;
        if(ch[0])sz+=ch[0]->sz,sum+=ch[0]->sum;
        if(ch[1])sz+=ch[1]->sz,sum+=ch[1]->sum;
        if(ch[0])
        {
            lsum=max(ch[0]->lsum,ch[0]->sum+val);
            if(ch[1])lsum=max(lsum,ch[0]->sum+val+ch[1]->lsum);
        }
        else lsum=max(val,val+(ch[1] ? ch[1]->sum : 0));
        if(ch[1])
        {
            rsum=max(ch[1]->rsum,ch[1]->sum+val);
            if(ch[0])rsum=max(rsum,ch[1]->sum+val+ch[0]->sum);
        }
        else rsum=max(val,val+(ch[0] ? ch[0]->sum : 0));
        mxsum=val;
        if(ch[0])mxsum=max({mxsum,ch[0]->mxsum,ch[0]->rsum+val});
        if(ch[1])mxsum=max({mxsum,ch[1]->mxsum,ch[1]->lsum+val});
        if(ch[0] && ch[1])mxsum=max(mxsum,ch[0]->rsum+val+ch[1]->lsum);
    }
};
void build(node* &o,int l,int r)
{
    if(l>r)return ;
    int m=(l+r)>>1;
    o=new node(a[m]);
    build(o->ch[0],l,m),build(o->ch[1],m+1,r);
    o->push_up();
}
void rot(node* &o,int d)
{
    node *k=o->ch[d^1];
    o->ch[d^1]=k->ch[d],k->ch[d]=o;
    o->push_up(),k->push_up();
    o=k;
}
void splay(node* &o,int k)
{
    if(!o)return ;
    o->push_down();
    int d=o->cmp(k);
    if(d==1)k-=(o->ch[0] ? o->ch[0]->sum : 0)+1;
    if(d!=-1)
    {
        node *p=o->ch[d];
        if(p)p->push_down();
        int d2=p->cmp(k);
        int k2=(d2==0 ? k : k-(p->ch[0] ? p->ch[0]->sum : 0)-1);
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
    splay(l,l->sz);
    l->ch[1]=r;
    l->push_up();
    return l;
}
void split(node* &o,int k,node* &l,node* &r)
{
    splay(o,k);
    l=o,r=o->ch[1];
    o->ch[1]=NULL;
    l->maintain();
}
main()
{
    srand(time(NULL));
    scanf("%d%d",&n,&m);
    return 0;
}

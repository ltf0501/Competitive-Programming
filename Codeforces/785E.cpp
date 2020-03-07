#include<bits/stdc++.h>
using namespace std;
#define maxn 200000+10
#define ll long long
int a[maxn];
int n,q;
struct node
{
    node* ch[2];
    int val,sz,r;
    node(int x)
    {
        ch[0]=ch[1]=NULL;
        val=x,r=rand(),sz=1;
    }
    int cmp(int x)
    {
        if(x==val)return -1;
        return (x<val)?0:1;
    }
    void maintain()
    {
        sz=1;
        if(ch[0]!=NULL)sz+=ch[0]->sz;
        if(ch[1]!=NULL)sz+=ch[1]->sz;
    }
} *r[maxn];
void rot(node* &o,int d)
{
    node* k=o->ch[d^1];
    o->ch[d^1]=k->ch[d];
    k->ch[d]=o;
    o->maintain();k->maintain();
    o=k;
}
void insrt(node* &o,int x)
{
    if(o==NULL)o=new node(x);
    else
    {
        int d=o->cmp(x);
        insrt(o->ch[d],x);
        if(o->ch[d]->r>o->r)rot(o,d^1);
        o->maintain();
    }
}
void remov(node* &o,int x)
{
    int d=o->cmp(x);
    if(d==-1)
    {
        if(o->ch[0]==NULL)o=o->ch[1];
        else if(o->ch[1]==NULL)o=o->ch[0];
        else
        {
            int d2=( (o->ch[0]->r > o->ch[1]->r) ? 1 : 0 );
            rot(o,d2);remov(o->ch[d2],x);
        }
    }
    else remov(o->ch[d],x);
    if(o!=NULL)o->maintain();
}
ll ans(node* o,int x)
{
    node* k=o;
    ll ret=0;
    while(k!=NULL)
    {
        int d=k->cmp(x);
        if(d)
        {
            ret++;
            if(k->ch[0]!=NULL)ret+=k->ch[0]->sz;
            k=k->ch[1];
        }
        else k=k->ch[0];
    }
    return ret;
}
void add1(int x,int val)
{
    while(x<=n)insrt(r[x],val),x+=(x&-x);
}
void add2(int x,int val)
{
    while(x<=n)remov(r[x],val),x+=(x&-x);
}
ll get_ans(int x,int val)
{
    if(!x)return 0;
    ll ret=0;
    while(x)ret+=ans(r[x],val),x-=(x&-x);
    return ret;
}
main()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)a[i]=i,add1(i,i);
    ll now=0;
    while(q--)
    {
        int x,y;scanf("%d%d",&x,&y);
        if(x==y){printf("%I64d\n",now);continue;}
        if(x>y)swap(x,y);
        now+=2*((get_ans(y-1,a[y])-get_ans(x,a[y]))-(get_ans(y-1,a[x])-get_ans(x,a[x])));
        if(a[x]<a[y])now++;else now--;
        printf("%I64d\n",now);
        add2(y,a[y]),add2(x,a[x]),add1(y,a[x]),add1(x,a[y]);
        swap(a[x],a[y]);
    }
    return 0;
}

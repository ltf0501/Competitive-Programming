#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node
{
    node* ch[2];
    int val,r;
    ll sz,d;
    bool cmp(int x)
    {
        if(x==val)return -1;
        return x<val ? 0 : 1;
    }
    node(int v)
    {
        val=v;
        r=rand();
        sz=1;d=1;
        ch[0]=ch[1]=NULL;
    }
    void maintain()
    {
        sz=1;
        if(ch[0])sz+=ch[0]->sz;
        if(ch[1])sz+=ch[1]->sz;
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
void insrt(node* &o,int k)
{
    if(!o){o=new node(k);return ;}
    int d=o->cmp(k);
    if(d==-1)
    {
        o->d++,o->sz++;
    }
    else
    {
        insrt(o->ch[d],k);
        if(o->ch[d]->r>o->r)rot(o,d^1);
    }
    o->maintain();
}
ll query(node *o,int k)
{
    if(!o)return 0;
    int d=o->cmp(k);
    if(d==-1)return o->ch[1] ? o->ch[1]->sz : 0;
    if(d==0)return o->ch[1] ? o->ch[1]->sz : 0+o->d+query(o->ch[0],k);
    if(d==1)return query(o->ch[1],k);
}
void del(node* &o)
{
    if(o->ch[0])del(o->ch[0]);
    if(o->ch[1])del(o->ch[1]);
    delete o;
    o=NULL;
}
node* root;
main()
{
    srand(time(NULL));
    int n;
    while(~scanf("%d",&n) && n)
    {
        ll ans=0;
        for(int i=1;i<=n;i++)
        {
            int x;scanf("%d",&x);
            insrt(root,x);
            ans+=query(root,x);
        }
        printf("%lld\n",ans);
        del(root);
    }
    return 0;
}


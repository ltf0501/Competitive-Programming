#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
#define ll long long
int n,m;
int a[maxn],pos[maxn];
struct node
{
    node *ch[2];
    int val,sz,r;
    int cmp(int x)
    {
        if(x==val)return -1;
        return x<val ? 0 : 1;
    }
    node(int v=0)
    {
        val=v;sz=1;r=rand();
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
    node *k=o->ch[d^1];
    o->ch[d^1]=k->ch[d];
    k->ch[d]=o;
    o->maintain();k->maintain();
    o=k;
}
void insrt(node* &o,int x)
{
    if(!o){o=new node(x);return ;}
    int d=o->cmp(x);
    insrt(o->ch[d],x);
    o->maintain();
    if(o->ch[d]->r>o->r)rot(o,d^1);
}
void remov(node* &o,int x)
{
    if(!o)return ;
    int d=o->cmp(x);
    if(d==-1)
    {
        if(o->ch[0] && o->ch[1])
        {
            int d2=(o->ch[0]->r>o->ch[1]->r) ? 1 : 0;
            rot(o,d2),remov(o->ch[d2],x);
        }
        else
        {
            if(!o->ch[0])o=o->ch[1];
            else o=o->ch[0];
        }
    }
    else remov(o->ch[d],x);
    if(o)o->maintain();
}
ll rk(node* o,int x)//比x大的個數
{
    if(!o)return 0;
    int d=o->cmp(x);
    if(d==-1)return o->ch[1]?o->ch[1]->sz:0;
    if(d==1)return rk(o->ch[1],x);
    return (o->ch[1]?o->ch[1]->sz:0)+1+rk(o->ch[0],x);
}
node *root[maxn];
void ins(int x,int v)
{
    for(int i=x;i<=n;i+=i&-i)insrt(root[i],v);
}
void del(int x)
{
    for(int i=pos[x];i<=n;i+=i&-i)remov(root[i],x);
}
int bit[maxn];
void add(int x,int d)
{
    for(int i=x;i<=n;i+=i&-i)bit[i]+=d;
}
ll sum(int x)
{
    ll ret=0;
    for(int i=x;i;i-=i&-i)ret+=bit[i];
    return ret;
}
void gao(node* &o)
{
    if(!o)return ;
    gao(o->ch[0]),gao(o->ch[1]);
    delete o;
    o=NULL;
}
main()
{
    srand(7122);
    while(~scanf("%d%d",&n,&m))
    {
        ll ans=0;
        for(int i=1;i<=n;i++)bit[i]=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]),pos[a[i]]=i;
            ans+=i-1-sum(a[i]);
            add(a[i],1);
        }
        for(int i=1;i<=n;i++)ins(i,a[i]);
        while(m--)
        {
            int x;scanf("%d",&x);
            printf("%lld\n",ans);
            del(x);
            ll pre=0,suf=0;
            for(int i=pos[x];i;i-=i&-i)
            {
                ll tmp=rk(root[i],x);//比x大的數有tmp個
                pre+=tmp;
                int sz=root[i]?root[i]->sz:0;
                suf+=sz-tmp;
            }
            add(x,-1);
            suf=sum(x)-suf;
            ans-=(pre+suf);
        }
        for(int i=1;i<=n;i++)gao(root[i]);
    }
    return 0;
}
/*
5 4
1 5 3 4 2
5
1
4
2
6 5
4 3 6 1 5 2
4
6
5
1
2
*/

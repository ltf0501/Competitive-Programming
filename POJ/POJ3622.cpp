#include<cstdio>
#include<algorithm>
#include<utility>
#include<set>
using namespace std;
#define maxn 100010
#define ll long long
#define pii pair<int,int>
#define F first
#define S second
pii a[maxn],b[maxn];
int n,m;
bool flag=1;
bool cmp(pii x,pii y){return x.S>y.S;}
/*
struct node
{
    node *ch[2];
    int sz,val,r,num;
    int cmp(int x)
    {
        if(val)
    }
    node(int x)
    {
        ch[0]=ch[1]=NULL;
        sz=1,num=1,val=x,r=rand();
    }
    void push_up(){sz=num+(ch[0] ? ch[0]->sz : 0)+(ch[1] ? ch[1]->sz : 0);}
};
void rot(node* &o,bool d)
{
    node* k=o->ch[d^1];
    o->ch[d^1]=k->ch[d];
    k->ch[d]=o;
    o->push_up(),k->push_up();
    o=k;
}
void insrt(node* &o,int x)
{
    if(!o){o=new node(x);return ;}
    int d=o->cmp(x);
    if(d==-1){o->num++,o->sz++;return ;}
    insrt(o->ch[d],x);
    if(o->ch[d]->r>o->r)rot(o,d^1);
    o->push_up();
}
void del(node* &o,int x)
{
    if(!o){flag=0;return ;}
    int d=o->cmp(x);
    if(d==-1)
    {
        if(o->num>1)o->num--,o->sz--;
        else
        {
            if(!o->ch[0])o=o->ch[1];
            else if(!o->ch[1])o=o->ch[0];
            else
            {
                int d2=(o->ch[0]->r>o->ch[1]->r) ? 1 : 0;
                rot(o,d2),del(o->ch[d2],x);
            }
        }
    }
    else del(o->ch[d],x);
    o->push_up();
}
*/
multiset<int> s;
main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d%d",&a[i].F,&a[i].S);
    for(int i=1;i<=m;i++)scanf("%d%d",&b[i].F,&b[i].S);
    sort(a+1,a+n+1,cmp),sort(b+1,b+m+1,cmp);
    int now=1;
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        while(now<=m && b[now].S>=a[i].S)s.insert(b[now++].F);
        if(s.empty())return 0*puts("-1");
        multiset<int>::iterator it=s.lower_bound(a[i].F);
        if(it==s.end())return 0*puts("-1");
        ans+=*(it);
        //printf("%d %d\n",*(it),now);
        s.erase(it);
    }
    printf("%lld\n",ans);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define maxn 50010
set<int> s[maxn*2];
int a[maxn],pre[maxn];
vector<int> v;
int n,m,Sz;
struct Q
{
    char c[2];
    int x,y;
}q[maxn];
struct node
{
    node *ch[2];
    int val,r,sz,cnt;
    int cmp(int x)
    {
        if(x==val)return -1;
        return x<val ? 0 : 1;
    }
    node(int v=0)
    {
        ch[0]=ch[1]=NULL;
        val=v;sz=1;cnt=1;
        r=rand();
    }
    void maintain()
    {
        sz=cnt;
        if(ch[0])sz+=ch[0]->sz;
        if(ch[1])sz+=ch[1]->sz;
    }
};
node *root[maxn];
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
    if(d==-1){o->cnt++,o->sz++;return ;}
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
        if(o->cnt>1){o->cnt--,o->sz--;return ;}
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
int rk(node* a,int x)///比x小的個數
{
    if(!a)return 0;
    int s=a->ch[0]?a->ch[0]->sz:0;
    int d=a->cmp(x);
    if(d==-1)return s;
    if(d==0)return rk(a->ch[0],x);
    return s+a->cnt+rk(a->ch[1],x);
}
void ins(int x,int d)
{
    for(int i=x;i<=n;i+=i&-i)insrt(root[i],d);
}
void del(int x,int d)
{
    for(int i=x;i<=n;i+=i&-i)remov(root[i],d);
}
int ask(int x,int d)
{
    int ret=0;
    for(int i=x;i;i-=i&-i)ret+=rk(root[i],d);
    return ret;
}
/*
void print(node *o)
{
    if(!o)return ;
    print(o->ch[0]);
    for(int i=1;i<=o->cnt;i++)printf("%d ",o->val);
    print(o->ch[1]);
}
*/
main()
{
    srand(7122);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),v.push_back(a[i]);
    for(int i=1;i<=m;i++)
    {
        scanf("%s%d%d",q[i].c,&q[i].x,&q[i].y);
        q[i].x++;
        if(q[i].c[0]=='M')v.push_back(q[i].y);
    }

    sort(v.begin(),v.end());
    v.resize(unique(v.begin(),v.end())-v.begin());
    Sz=v.size();
    for(int i=1;i<=n;i++)a[i]=lower_bound(v.begin(),v.end(),a[i])-v.begin()+1;
    for(int i=1;i<=m;i++)
        if(q[i].c[0]=='M')q[i].y=lower_bound(v.begin(),v.end(),q[i].y)-v.begin()+1;
    for(int i=1;i<=Sz;i++)s[i].insert(0);
    for(int i=1;i<=n;i++)
    {
        pre[i]=*(--s[a[i]].end());
        ins(i,pre[i]);
        s[a[i]].insert(i);
    }
    /*
    root[i]存i~i-(i&-i+1)的pre[]
    s[k]存k的位置
    pre[i]存和a[i]一樣數值的前繼位置
    */
    for(int i=1;i<=Sz;i++)s[i].insert(n+1);
    for(int i=1;i<=m;i++)
    {
        if(q[i].c[0]=='M')
        {
            int x=q[i].x,y=q[i].y;
            int old=a[x];
            if(old==y)continue;
            ///把下一項的前繼改成前前個
            int ii=*s[old].upper_bound(x);
            //printf("%d ",ii);
            int z=pre[x];
            del(ii,x);
            ins(ii,z);
            pre[ii]=z;
            ///把插入位置的下一項前繼改成他自己
            auto it=s[y].lower_bound(x);
            ii=*it;
            //printf("%d\n",ii);
            int tmp=pre[ii];
            del(ii,tmp);
            ins(ii,x);
            pre[ii]=x;
            ///把自己的前繼改成插入位置的上一項
            del(x,z);
            ins(x,*(--it));
            pre[x]=*it;
            s[old].erase(x);
            s[y].insert(x);
            a[x]=y;
            /*
            for(int i=1;i<=n;i++)printf("%d ",a[i]);puts("");
            for(int i=1;i<=n;i++)printf("%d ",pre[i]);puts("");
            for(int k : s[y])printf("%d ",k);puts("");
            */
        }
        else
        {
            int x=q[i].x,y=q[i].y;
            printf("%d\n",ask(y,x)-ask(x-1,x));
        }
    }
    return 0;
}
/*
7 4
1 2 1 3 2 1 4
Q 1 6
M 3 2
Q 1 6
Q 3 5

3
2
1

10 7
1 1 5 2 3 4 2 9 5 3
Q 2 5
M 3 7
Q 2 5
M 6 7
M 0 2
Q 0 10
Q 5 9

3
3
7
4
*/

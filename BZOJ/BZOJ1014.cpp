#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
#define maxp 4000010
#define ll long long
const int p=890501;
const int mod=1e9+9;
ll pw[maxn];
char c[maxn];
struct node
{
    static node pool[maxp];
    //static node *ptr;
    node *l,*r;
    ll umr;
    int sz,val;
    void update()
    {
        sz=1+(l ? l->sz : 0)+(r ? r->sz : 0);
        int t=l ? l->sz : 0;
        umr=((l ? l->umr : 0)+(val*pw[t]%mod)+((r ? r->umr : 0)*pw[t+1]%mod))%mod;
    }
}node::pool[maxp],*ptr;
int SZ(node *a){return a ? a->sz : 0;}
node* newnode(int x)
{
    ptr->l=ptr->r=NULL;
    ptr->umr=ptr->val=x;
    ptr->sz=1;
    return ptr++;
}
node *root;
node *mrge(node *x,node *y)
{
    if(!x)return y;
    if(!y)return x;
    if(rand()&1)
    {
        x->r=mrge(x->r,y);
        x->update();
        return x;
    }
    y->l=mrge(x,y->l);
    y->update();
    return y;
}
typedef pair<node*,node*> Droot;
#define F first
#define S second
Droot split(node *o,int k)
{
    Droot d(NULL,NULL);
    if(!o)return d;
    if(k<=0)return Droot(NULL,o);
    if(k>=SZ(o))return Droot(o,NULL);
    int lsz=SZ(o->l);
    if(k<=lsz)
    {
        d=split(o->l,k);
        o->l=d.S;
        o->update();
        d.S=o;
    }
    else
    {
        d=split(o->r,k-lsz-1);
        o->r=d.F;
        o->update();
        d.F=o;
    }
    if(d.F)(d.F)->update();
    if(d.S)(d.S)->update();
    return d;
}
main()
{
    srand(time(NULL));
    ptr=node::pool;
    pw[0]=1;
    for(int i=1;i<maxn;i++)pw[i]=pw[i-1]*p%mod;
    scanf("%s",c+1);
    int n=strlen(c+1);
    for(int i=1;i<=n;i++)
    {
        node *x=newnode(c[i]-'a');
        root=mrge(root,x);
    }
    /*
    printf("%lld\n",root ? root->umr : 0);
    ll cal=0;
    for(int i=1;i<=n;i++)(cal+=1ll*(c[i]-'a')*pw[i-1])%=mod;
    printf("%lld\n",cal);
    */
    int q;scanf("%d",&q);
    while(q--)
    {
        char type[2];
        scanf("%s",type);
        if(type[0]=='Q')
        {
            int x,y;scanf("%d%d",&x,&y);
            if(x>y)swap(x,y);
            int mx=SZ(root)-y+1;
            int now=0;
            for(int i=20;i>=0;i--)if(now+(1<<i)<=mx)
            {
                ll l,r;
                now+=(1<<i);
                node *a,*b,*c;
                Droot(a,b)=split(root,x-1);
                Droot(b,c)=split(b,now);puts("XD");
                l=b->umr;
                printf("%d: %d %d %d\n",i,SZ(a),SZ(b),SZ(c));
                root=mrge(mrge(a,b),c);
                Droot(a,b)=split(root,y-1);
                Droot(b,c)=split(b,now);
                r=b->umr;
                root=mrge(mrge(a,b),c);
                if(l!=r)now-=(1<<i);
                printf("%lld %lld\n",l,r);
            }
            printf("%d\n",now);
        }
        else if(type[0]=='R')
        {
            int x;char s[2];
            scanf("%d %s",&x,s);
            int val=s[0]-'a';
            node *a,*b,*c;
            Droot(a,b)=split(root,x);
            Droot(b,c)=split(b,1);
            b->val=b->umr=val;
            root=mrge(mrge(a,b),c);
        }
        else
        {
            int x;char s[2];
            scanf("%d %s",&x,s);
            int val=s[0]-'a';
            node *a,*b,*c;
            Droot(a,b)=split(root,x);
            node *o=newnode(val);
            root=mrge(mrge(a,o),b);
        }
    }
    return 0;
}
/*
madamimadam
7
Q 1 7
Q 4 8
Q 10 11
R 3 a
Q 1 7
I 10 a
Q 2 11
*/

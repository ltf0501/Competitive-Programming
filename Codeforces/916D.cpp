#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
struct node
{
    node *l,*r;
    int val;
    node(){val=0,l=r=NULL;}
    void push_up(){val=(l?l->val:0)+(r?r->val:0);}
};
node *cop(node *o)
{
    node *v=new node();
    if(o)v->l=o->l,v->r=o->r,v->val=o->val;
    return v;
}
void update(node *o,int l,int r,int pos,int v)
{
    if(l==r){o->val+=v;return ;}
    int m=(l+r)>>1;
    if(pos<=m)o->l=cop(o->l),update(o->l,l,m,pos,v);
    else o->r=cop(o->r),update(o->r,m+1,r,pos,v);
    o->push_up();
}
int query(node *o,int l,int r,int ql,int qr)
{
    if(!o)return 0;
    if(ql<=l && r<=qr)return o->val;
    int m=(l+r)>>1;
    int ret=0;
    if(ql<=m)ret+=query(o->l,l,m,ql,qr);
    if(qr>m)ret+=query(o->r,m+1,r,ql,qr);
    return ret;
}
map<string,int> mp;
int id=0;
int get_id(string s)
{
    if(mp.find(s)!=mp.end())return mp[s];
    mp[s]=++id;
    return id;
}
node *root[maxn],*nm[maxn];
const int I=1e9;
main()
{
    int q;scanf("%d",&q);
    for(int i=1;i<=q;i++)
    {
        string type;cin>>type;
        if(type=="undo")
        {
            int d;scanf("%d",&d);
            root[i]=cop(root[i-d-1]);
            nm[i]=cop(nm[i-d-1]);
            continue;
        }
        root[i]=cop(root[i-1]);
        nm[i]=cop(nm[i-1]);
        string s;cin>>s;
        int v=get_id(s);
        int old=query(nm[i],1,q,v,v);
        //printf("%d %d\n",v,old);
        if(type=="set")
        {
            int x;scanf("%d",&x);
            if(old)update(root[i],0,I,old,-1);
            update(root[i],0,I,x,1);
            update(nm[i],1,q,v,x-old);
        }
        else if(type=="remove")
        {
            if(old)update(root[i],0,I,old,-1);
            update(nm[i],1,q,v,-old);
        }
        else
        {
            if(!old)puts("-1");
            else printf("%d\n",query(root[i],0,I,0,old-1));
            fflush(stdout);
        }
    }
    return 0;
}

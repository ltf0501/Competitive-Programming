#include<bits/stdc++.h>
using namespace std;
#define ll long long
int R,C,n;
struct seg
{
    ll val;
    int tg;
    seg *lt,*rt;
    seg():lt(NULL),rt(NULL),tg(-1),val(-1){}
    void push(int l,int r,int x,ll k)
    {
        int m=(l+r)/2;
        if(x<=m)
        {
            if(!lt)lt=new seg();
            lt->update(l,m,x,k);
        }
        else
        {
            if(!rt)rt=new seg();
            rt->update(m+1,r,x,k);
        }
    }
    void update(int l,int r,int x,ll k)
    {
        if(l==r){val=k;return ;}
        if(x==tg)val=k;
        else if(tg>=0)
        {
            push(l,r,tg,val);
            tg=-1;
        }
        else if(val<0)
        {
            tg=x;val=k;return ;
        }
        push(l,r,x,k);
        val=__gcd((lt ? lt->val : 0),(rt ? rt->val : 0));
    }
    ll query(int l,int r,int ql,int qr)
    {
        if(ql<=l && r<=qr)return val;
        if(l>qr || r<ql)return 0;
        if(tg>=0)return (ql<=tg && tg<=qr) ? val : 0;
        int m=(l+r)/2;
        return __gcd((lt ? lt->query(l,m,ql,qr) : 0),(rt ? rt->query(m+1,r,ql,qr) : 0));
    }
};
struct seg2D
{
    static int maxn;
    seg *val;
    seg2D *lt,*rt;
    seg2D():val(NULL),lt(NULL),rt(NULL){}
    void update(int l,int r,int x,int y,ll k)
    {
        if(l==r)
        {
            if(!val)val=new seg();
            val->update(0,maxn-1,y,k);
            return ;
        }
        int m=(l+r)/2;
        if(x<=m)
        {
            if(!lt)lt=new seg2D();
            lt->update(l,m,x,y,k);
        }
        else
        {
            if(!rt)rt=new seg2D();
            rt->update(m+1,r,x,y,k);
        }
        if(!val)val=new seg();
        ll le=(lt && lt->val) ? lt->val->query(0,maxn-1,y,y) : 0;
        ll ri=(rt && rt->val) ? rt->val->query(0,maxn-1,y,y) : 0;
        val->update(0,maxn-1,y,__gcd(le,ri));
    }
    ll query(int l,int r,int ql,int qr,int x,int y)
    {
        if(ql<=l && r<=qr)return val ? val->query(0,maxn-1,x,y) : 0;
        if(ql>r || l>qr)return 0;
        int m=(l+r)/2;
        return __gcd((lt ? lt->query(l,m,ql,qr,x,y) : 0),(rt ? rt->query(m+1,r,ql,qr,x,y) : 0));
    }
};
int seg2D::maxn;
main()
{
    scanf("%d%d%d",&R,&seg2D::maxn,&n);
    seg2D *root=new seg2D();
    while(n--)
    {
        int type;scanf("%d",&type);
        if(type==1)
        {
            int x,y;ll k;scanf("%d%d%lld",&x,&y,&k);
            root->update(0,R-1,x,y,k);
        }
        else
        {
            int a,b,c,d;scanf("%d%d%d%d",&a,&b,&c,&d);
            if(a>c)swap(a,c);
            if(b>d)swap(b,d);
            printf("%lld\n",root->query(0,R-1,a,c,b,d));
        }
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
struct Q
{
    int x,y;
    char c[2];
    void input(){scanf("%d%d%s",&x,&y,c);}
}q[maxn];
int n,m;
vector<int> vx,vy;
struct segtree
{
    int st[maxn<<2],tg[maxn<<2];
    void push_down(int l,int r,int o)
    {
        if(!tg[o])return ;
        st[o<<1]=max(st[o<<1],tg[o]),st[o<<1|1]=max(st[o<<1|1],tg[o]);
        tg[o<<1]=max(tg[o<<1],tg[o]);tg[o<<1|1]=max(tg[o<<1|1],tg[o]);
        tg[o]=0;
    }
    void push_up(int o){st[o]=max(st[o<<1],st[o<<1|1]);}
    void update(int l,int r,int o,int ql,int qr,int v)
    {
        if(ql<=l && r<=qr){st[o]=max(st[o],v),tg[o]=max(tg[o],v);return ;}
        push_down(l,r,o);
        int m=(l+r)>>1;
        if(ql<=m)update(l,m,o<<1,ql,qr,v);
        if(qr>m)update(m+1,r,o<<1|1,ql,qr,v);
        push_up(o);
    }
    int query(int l,int r,int o,int p)
    {
        if(l==r)return st[o];
        push_down(l,r,o);
        int m=(l+r)>>1;
        if(p<=m)return query(l,m,o<<1,p);
        return query(m+1,r,o<<1|1,p);
    }
}up,lft;
void norm(vector<int> &v)
{
    sort(v.begin(),v.end());
    v.resize(unique(v.begin(),v.end())-v.begin());
}
main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)q[i].input(),vx.push_back(q[i].x),vy.push_back(q[i].y);
    vx.push_back(0);
    vy.push_back(0);
    norm(vx),norm(vy);
    int SZ=vx.size();
    for(int i=1;i<=m;i++)
    {
        q[i].x=lower_bound(vx.begin(),vx.end(),q[i].x)-vx.begin();
        q[i].y=lower_bound(vy.begin(),vy.end(),q[i].y)-vy.begin();
    }
    for(int i=1;i<=m;i++)
    {
        if(q[i].c[0]=='L')
        {
            int s=lft.query(1,SZ,1,q[i].y);
            printf("%d\n",vx[q[i].x]-vx[s]);
            lft.update(1,SZ,1,q[i].y,q[i].y,q[i].x);
            if(s!=q[i].x)up.update(1,SZ,1,s+1,q[i].x,q[i].y);
        }
        else
        {
            int s=up.query(1,SZ,1,q[i].x);
            printf("%d\n",vy[q[i].y]-vy[s]);
            up.update(1,SZ,1,q[i].x,q[i].x,q[i].y);
            if(s!=q[i].y)lft.update(1,SZ,1,s+1,q[i].y,q[i].x);
        }
    }
    return 0;
}

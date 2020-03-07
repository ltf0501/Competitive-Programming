#include<bits/stdc++.h>
using namespace std;
#define maxn 2000010
#define ALL(v) v.begin(),v.end()
const int INF=1e9+7;
int seg[maxn<<2],tg[maxn<<2];
int n;
vector<int> v;
struct Q
{
    int type;
    int x,y;
}q[maxn];
void push_up(int o){seg[o]=seg[o<<1]+seg[o<<1|1];}
void push_down(int l,int r,int o)
{
    if(tg[o]==-1)return ;
    int m=(l+r)>>1;
    seg[o<<1]=tg[o]*(m-l+1),seg[o<<1|1]=tg[o]*(r-m);
    tg[o<<1]=tg[o],tg[o<<1|1]=tg[o];
    tg[o]=-1;
}
void update(int l,int r,int o,int ql,int qr,int k)
{
    if(ql<=l && r<=qr){seg[o]=(r-l+1)*k,tg[o]=k;return ;}
    int m=(l+r)>>1;
    push_down(l,r,o);
    if(ql<=m)update(l,m,o<<1,ql,qr,k);
    if(qr>m)update(m+1,r,o<<1|1,ql,qr,k);
    push_up(o);
}
int query(int l,int r,int o,int k)
{
    if(l==r)return l;
    int m=(l+r)>>1;
    push_down(l,r,o);
    if(!k)
    {
        if(seg[o<<1])return query(l,m,o<<1,k);
        else if(seg[o<<1|1])return query(m+1,r,o<<1|1,k);
        else return -1;
    }
    else
    {
        if(seg[o<<1|1])return query(m+1,r,o<<1|1,k);
        else if(seg[o<<1])return query(l,m,o<<1,k);
        else return -1;
    }
}
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&q[i].type);
        if(q[i].type==1){scanf("%d",&q[i].x);q[i].y=INF;}
        else scanf("%d%d",&q[i].x,&q[i].y);
        v.push_back(q[i].x);
        if(q[i].y!=INF)v.push_back(q[i].y);
    }
    for(int i=1;i<(maxn<<2);i++)tg[i]=-1;
    sort(ALL(v));
    v.resize(unique(ALL(v))-v.begin());
    for(int i=1;i<=n;i++)
    {
        q[i].x=lower_bound(ALL(v),q[i].x)-v.begin()+1;
        if(q[i].y!=INF)q[i].y=lower_bound(ALL(v),q[i].y)-v.begin()+1;
    }
    int mm=v.size();
    for(int i=1;i<=n;i++)
    {
        if(q[i].type==1)update(1,mm,1,q[i].x,q[i].x,1);
        else update(1,mm,1,q[i].x,q[i].y,0);
        int l=query(1,mm,1,0),r=query(1,mm,1,1);
        //printf("%d %d\n",l,r);
        if(l==-1 && r==-1)puts("0");
        else if(l==r)printf("1 %d\n",v[l-1]);
        else printf("2 %d %d\n",v[l-1],v[r-1]);
    }
    return 0;
}

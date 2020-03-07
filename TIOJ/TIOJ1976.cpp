#include<bits/stdc++.h>
using namespace std;
#define maxn 400010
#define pii pair<int,int>
#define F first
#define S second
struct P
{
    int x,val,pos;
    bool operator < (const P& b)const
    {
        if(x!=b.x)return x<b.x;
        return pos>b.pos;
    }
}a[maxn];
int n;
vector<int> v;
int seg[maxn<<2],tg[maxn<<2];
void push_down(int o)
{
    if(tg[o])
    {
        seg[o<<1]+=tg[o],seg[o<<1|1]+=tg[o];
        tg[o<<1]+=tg[o],tg[o<<1|1]+=tg[o];
        tg[o]=0;
    }
}
void push_up(int o){seg[o]=max(seg[o<<1],seg[o<<1|1]);}
void update(int l,int r,int o,int ql,int qr,int x)
{
    if(ql<=l && r<=qr){seg[o]+=x,tg[o]+=x;return ;}
    push_down(o);
    int m=(l+r)>>1;
    if(ql<=m)update(l,m,o<<1,ql,qr,x);
    if(qr>m)update(m+1,r,o<<1|1,ql,qr,x);
    push_up(o);
}
int query(int l,int r,int o,int ql,int qr)
{
    if(ql<=l && r<=qr)return seg[o];
    push_down(o);
    int m=(l+r)>>1;
    if(qr<=m)return query(l,m,o<<1,ql,qr);
    if(ql>m)return query(m+1,r,o<<1|1,ql,qr);
    return max(query(l,m,o<<1,ql,qr),query(m+1,r,o<<1|1,ql,qr));
}
main()
{
    scanf("%d",&n);
    int tot=0;
    for(int i=1;i<=n;i++)
    {
        int l,r,w;scanf("%d%d%d",&l,&r,&w);
        v.push_back(l),v.push_back(r);
        v.push_back(r+1);
        a[++tot]={l,w,1};
        a[++tot]={r,w,-1};
        a[++tot]={r+1,0,1};
        a[++tot]={r+1,0,-1};
    }
    sort(a+1,a+tot+1);
    sort(v.begin(),v.end());
    v.resize(unique(v.begin(),v.end())-v.begin());
    for(int i=1;i<=tot;i++)a[i].x=lower_bound(v.begin(),v.end(),a[i].x)-v.begin()+1;
    int N=v.size();
    int ans=0,cur=0;
    for(int i=tot;i>=1;i--)
    {
        if(a[i].pos==-1)
        {
            cur+=a[i].val;
            ans=max(ans,cur+query(1,N,1,a[i].x,N));
            //printf("%d %d\n",cur,query(1,N,1,a[i].x,N));
        }
        else
        {
            ans=max(ans,cur+query(1,N,1,a[i].x,N));
            //printf("%d %d\n",cur,query(1,N,1,a[i].x,N));
            update(1,N,1,a[i].x,N,a[i].val);
            cur-=a[i].val;
        }
    }
    printf("%d\n",ans);
    return 0;
}
/*
3
0 2 -5
1 5 10
4 6 -2
*/

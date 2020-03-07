#include<bits/stdc++.h>
using namespace std;
#define maxc 22
#define maxn 100010
#define ll long long
#define pii pair<int,int>
#define F first
#define S second
struct P
{
    int l_sz,r_sz;
    pii l[maxc],r[maxc];
    ll ans;
}seg[maxn<<2];
int a[maxn];
int n,m,x;
P push_up(P &rt,P l_son,P r_son)
{
    rt.l_sz=l_son.l_sz;
    for(int i=0;i<rt.l_sz;i++)rt.l[i]=l_son.l[i];
    for(int i=0;i<r_son.l_sz;i++)
    {
        pii tmp=rt.l[rt.l_sz-1];
        pii cur=r_son.l[i];
        cur.F|=tmp.F;
        if(tmp.F<cur.F)rt.l[rt.l_sz++]=cur;
    }
    rt.r_sz=r_son.r_sz;
    for(int i=0;i<rt.r_sz;i++)rt.r[i]=r_son.r[i];
    for(int i=0;i<l_son.r_sz;i++)
    {
        pii tmp=rt.r[rt.r_sz-1];
        pii cur=l_son.r[i];
        cur.F|=tmp.F;
        if(tmp.F<cur.F)rt.r[rt.r_sz++]=cur;
    }
    rt.ans=l_son.ans+r_son.ans;
    for(int i=r_son.l_sz-1,j=0;i>=0;i--)
    {
        while(j<l_son.r_sz && (r_son.l[i].F|l_son.r[j].F)<x)j++;
        if(j<l_son.r_sz)
        {
            int ri;
            if(i+1<r_son.l_sz)ri=r_son.l[i+1].S-r_son.l[i].S;
            else ri=r_son.r[0].S-r_son.l[i].S+1;
            int le=l_son.r[j].S-l_son.l[0].S+1;
            rt.ans+=1ll*ri*le;
        }
    }
}
void build(int l,int r,int o)
{
    if(l==r)
    {
        P &tmp=seg[o];
        tmp.l_sz=tmp.r_sz=1;
        tmp.l[0]=tmp.r[0]=pii(a[l],l);
        tmp.ans=(a[l]>=x);
        return ;
    }
    int m=(l+r)>>1;
    build(l,m,o<<1),build(m+1,r,o<<1|1);
    push_up(seg[o],seg[o<<1],seg[o<<1|1]);
}
void update(int l,int r,int o,int p,int v)
{
    if(l==r)
    {
        P &tmp=seg[o];
        tmp.l_sz=tmp.r_sz=1;
        tmp.l[0]=tmp.r[0]=pii(v,l);
        tmp.ans=(v>=x);
        return ;
    }
    int m=(l+r)>>1;
    if(p<=m)update(l,m,o<<1,p,v);
    else update(m+1,r,o<<1|1,p,v);
    push_up(seg[o],seg[o<<1],seg[o<<1|1]);
}
P query(int l,int r,int o,int ql,int qr)
{
    if(ql<=l && r<=qr)return seg[o];
    int m=(l+r)>>1;
    if(qr<=m)return query(l,m,o<<1,ql,qr);
    if(ql>m)return query(m+1,r,o<<1|1,ql,qr);
    P ret={};
    push_up(ret,query(l,m,o<<1,ql,qr),query(m+1,r,o<<1|1,ql,qr));
    return ret;
}
main()
{
    scanf("%d%d%d",&n,&m,&x);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    build(1,n,1);
    /*
    for(int i=1;i<=7;i++)
    {
        printf("node_id = %d\n",i);
        printf("l_sz = %d: ",seg[i].l_sz);
        for(int j=0;j<seg[i].l_sz;j++)printf("%d ",seg[i].l[j]);puts("");
        printf("r_sz = %d: ",seg[i].r_sz);
        for(int j=0;j<seg[i].r_sz;j++)printf("%d ",seg[i].r[j]);puts("");
        printf("ans = %d\n\n",seg[i].ans);
    }
    */
    while(m--)
    {
        int type,x,y;scanf("%d%d%d",&type,&x,&y);
        if(type==1)update(1,n,1,x,y);
        else printf("%lld\n",query(1,n,1,x,y).ans);
    }
    return 0;
}

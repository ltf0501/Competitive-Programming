#include<bits/stdc++.h>
using namespace std;
#define maxn 250010
#define ll long long
ll sum[maxn<<2];
ll tg1[maxn<<2],tg2[maxn<<2],tg3[maxn<<2],setv[maxn<<2];
bool flag[maxn<<2];
void push_up(int o){sum[o]=sum[o<<1]+sum[o<<1|1];}
void push_down(int l,int r,int o)
{
    int m=(l+r)>>1;
    if(flag[o])
    {
        flag[o<<1]=flag[o<<1|1]=1;
        setv[o<<1]=setv[o<<1|1]=setv[o];
        tg1[o<<1]=tg1[o<<1|1]=0;
        tg2[o<<1]=tg2[o<<1|1]=0;
        tg3[o<<1]=tg3[o<<1|1]=0;
        sum[o<<1]=(ll)(m-l+1)*setv[o];
        sum[o<<1|1]=(ll)(r-m)*setv[o];
        flag[o]=0;
    }
    if(tg1[o] || tg2[o] || tg3[o])
    {
        ll t=tg1[o]+tg3[o]*(m-l);
        tg1[o<<1]+=tg1[o],tg1[o<<1|1]+=t+tg3[o];
        tg2[o<<1]+=t,tg2[o<<1|1]+=tg2[o];
        tg3[o<<1]+=tg3[o],tg3[o<<1|1]+=tg3[o];
        sum[o<<1]+=(tg1[o]+t)*(ll)(m-l+1)/2;
        sum[o<<1|1]+=(t+tg3[o]+tg2[o])*(ll)(r-m)/2;
        tg1[o]=tg2[o]=tg3[o]=0;
    }
}
void updateAB(int l,int r,int o,int ql,int qr,int step)
{
    if(ql<=l && r<=qr)
    {
        ll L,R;
        if(step>0)L=l-ql+1,R=r-ql+1;
        else L=qr-l+1,R=qr-r+1;
        tg1[o]+=L,tg2[o]+=R,tg3[o]+=step;
        sum[o]+=(L+R)*(ll)(r-l+1)/2;
        return ;
    }
    push_down(l,r,o);
    int m=(l+r)>>1;
    if(ql<=m)updateAB(l,m,o<<1,ql,qr,step);
    if(qr>m)updateAB(m+1,r,o<<1|1,ql,qr,step);
    push_up(o);
}
void updateC(int l,int r,int o,int ql,int qr,int x)
{
    if(ql<=l && r<=qr)
    {
        setv[o]=x,flag[o]=1;
        tg1[o]=tg2[o]=tg3[o]=0;
        sum[o]=(ll)(r-l+1)*(ll)x;
        return ;
    }
    push_down(l,r,o);
    int m=(l+r)>>1;
    if(ql<=m)updateC(l,m,o<<1,ql,qr,x);
    if(qr>m)updateC(m+1,r,o<<1|1,ql,qr,x);
    push_up(o);
}
ll query(int l,int r,int o,int ql,int qr)
{
    if(ql<=l && r<=qr)return sum[o];
    push_down(l,r,o);
    int m=(l+r)>>1;
    ll ret=0;
    if(ql<=m)ret+=query(l,m,o<<1,ql,qr);
    if(qr>m)ret+=query(m+1,r,o<<1|1,ql,qr);
    return ret;
}
main()
{
    int t;scanf("%d",&t);
    int n=250000;
    while(t--)
    {
        char c[2];
        int l,r,d;
        scanf("%s",&c);
        if(c[0]=='A')
        {
            scanf("%d%d",&l,&r);
            updateAB(1,n,1,l,r,1);
        }
        else if(c[0]=='B')
        {
            scanf("%d%d",&l,&r);
            updateAB(1,n,1,l,r,-1);
        }
        else if(c[0]=='C')
        {
            scanf("%d%d%d",&l,&r,&d);
            updateC(1,n,1,l,r,d);
        }
        else
        {
            scanf("%d%d",&l,&r);
            printf("%lld\n",query(1,n,1,l,r));
        }
    }
    return 0;
}

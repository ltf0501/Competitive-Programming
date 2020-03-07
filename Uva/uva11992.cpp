#include<bits/stdc++.h>
using namespace std;
#define maxr 20+5
#define maxn 1000010
int tg1[maxr][maxn<<2],tg2[maxr][maxn<<2];
int sum[maxr][maxn<<2],mx[maxr][maxn<<2],mi[maxr][maxn<<2];
bool flag[maxr][maxn<<2];
struct P
{
    int sum,mx,mi;
    P operator + (const P& b)
    {
        P ret;
        ret.sum=sum+b.sum;
        ret.mx=max(mx,b.mx);
        ret.mi=min(mi,b.mi);
        return ret;
    }
};
void push_up(int s,int o)
{
    sum[s][o]=sum[s][o<<1]+sum[s][o<<1|1];
    mx[s][o]=max(mx[s][o<<1],mx[s][o<<1|1]);
    mi[s][o]=min(mi[s][o<<1],mi[s][o<<1|1]);
}
void push_down(int s,int l,int r,int o)
{
    int m=(l+r)>>1;
    if(flag[s][o])
    {
        flag[s][o<<1]=flag[s][o<<1|1]=1;
        tg2[s][o<<1]=tg2[s][o<<1|1]=tg2[s][o];
        tg1[s][o<<1]=tg1[s][o<<1|1]=0;
        sum[s][o<<1]=(m-l+1)*tg2[s][o];
        sum[s][o<<1|1]=(r-m)*tg2[s][o];
        mx[s][o<<1]=mi[s][o<<1]=mx[s][o<<1|1]=mi[s][o<<1|1]=tg2[s][o];
        flag[s][o]=tg2[s][o]=0;
    }
    if(tg1[s][o])
    {
        tg1[s][o<<1]+=tg1[s][o],tg1[s][o<<1|1]+=tg1[s][o];
        sum[s][o<<1]+=tg1[s][o]*(m-l+1);
        sum[s][o<<1|1]+=tg1[s][o]*(r-m);
        mx[s][o<<1]+=tg1[s][o];
        mi[s][o<<1]+=tg1[s][o];
        mx[s][o<<1|1]+=tg1[s][o];
        mi[s][o<<1|1]+=tg1[s][o];
        tg1[s][o]=0;
    }
}
void build(int s,int l,int r,int o)
{
    if(l==r)
    {
        flag[s][o]=0;
        tg1[s][o]=tg2[s][o]=0;
        sum[s][o]=mx[s][o]=mi[s][o]=0;
        return ;
    }
    int m=(l+r)>>1;
    build(s,l,m,o<<1),build(s,m+1,r,o<<1|1);
    push_up(s,o);
}
void update1(int s,int l,int r,int o,int ql,int qr,int d)
{
    if(ql<=l && r<=qr)
    {
        sum[s][o]+=d*(r-l+1);
        mx[s][o]+=d,mi[s][o]+=d;
        tg1[s][o]+=d;
        return ;
    }
    push_down(s,l,r,o);
    int m=(l+r)>>1;
    if(ql<=m)update1(s,l,m,o<<1,ql,qr,d);
    if(qr>m)update1(s,m+1,r,o<<1|1,ql,qr,d);
    push_up(s,o);
}
void update2(int s,int l,int r,int o,int ql,int qr,int d)
{
    if(ql<=l && r<=qr)
    {
        sum[s][o]=(r-l+1)*d;
        mi[s][o]=mx[s][o]=d;
        flag[s][o]=1,tg2[s][o]=d;
        tg1[s][o]=0;
        return ;
    }
    push_down(s,l,r,o);
    int m=(l+r)>>1;
    if(ql<=m)update2(s,l,m,o<<1,ql,qr,d);
    if(qr>m)update2(s,m+1,r,o<<1|1,ql,qr,d);
    push_up(s,o);
}
P query(int s,int l,int r,int o,int ql,int qr)
{
    if(ql<=l && r<=qr)return {sum[s][o],mx[s][o],mi[s][o]};
    push_down(s,l,r,o);
    int m=(l+r)>>1;
    P ret={0,0,0};
    if(ql<=m)ret=ret+query(s,l,m,o<<1,ql,qr);
    if(qr>m)ret=ret+query(s,m+1,r,o<<1|1,ql,qr);
    return ret;
}*/
main()
{
    int r,c,m;
    while(scanf("%d%d%d",&r,&c,&m)!=EOF)
    {

        for(int i=1;i<=r;i++)build(i,1,c,1);
        while(m--)
        {
            int type,x1,y1,x2,y2,d;
            scanf("%d",&type);
            if(type==1)
            {
                scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&d);
                for(int i=x1;i<=x2;i++)update1(i,1,c,1,y1,y2,d);
            }
            else if(type==2)
            {
                scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&d);
                for(int i=x1;i<=x2;i++)update2(i,1,c,1,y1,y2,d);
            }
            else
            {
                scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
                P ans={0,0,0};
                for(int i=x1;i<=x2;i++)ans=ans+query(i,1,c,1,y1,y2);
                printf("%d %d %d\n",ans.sum,ans.mx,ans.mi);
            }
        }
    }
    return 0;
}

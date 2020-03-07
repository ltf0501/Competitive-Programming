#include<cstdio>
#include<algorithm>
using namespace std;
#define maxn 200005
#define inf 2147483647
int mx[4*maxn],tg[4*maxn];
void push_up(int o){mx[o]=max(mx[o<<1],mx[o<<1|1]);}
void push_down(int o)
{
    if(tg[o])
    {
        mx[o<<1]+=tg[o],tg[o<<1]+=tg[o];
        mx[o<<1|1]+=tg[o],tg[o<<1|1]+=tg[o];
        tg[o]=0;
    }
}
void update(int l,int r,int o,int ql,int qr,int v)
{
    if(ql<=l && r<=qr){mx[o]+=v,tg[o]+=v;return ;}
    push_down(o);
    int m=(l+r)>>1;
    if(ql<=m)update(l,m,o<<1,ql,qr,v);
    if(qr>m)update(m+1,r,o<<1|1,ql,qr,v);
    push_up(o);
}
struct node
{
    int x,y1,y2,w;
    bool operator < (const node& b)const{return x<b.x;}
}rec[maxn];
int dis[maxn];
main()
{
    int n;scanf("%d",&n);
    int tR=0,tN=0;
    for(int i=1;i<=n;i++)
    {
        int x1,y1,x2,y2,w;scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&w);
        rec[++tR]={x1,y1,y2+1,-w},rec[++tR]={x2+1,y1,y2+1,w};
        dis[tN++]=y1,dis[tN++]=y2;
    }
    sort(dis,dis+tN);
    tN=unique(dis,dis+tN)-dis;
    for(int i=1;i<=tR;i++)
    {
        rec[i].y1=lower_bound(dis,dis+tN,rec[i].y1)-dis+1;
        rec[i].y2=lower_bound(dis,dis+tN,rec[i].y2)-dis+1;
        if(rec[i].w>0)update(1,tN,1,rec[i].y1,rec[i].y2-1,rec[i].w);
    }
    sort(rec+1,rec+tR+1);
    rec[tR+1]={inf,0,0,0};
    int ans=0,cur=0;
    for(int i=1;i<=tR;i++)
    {
        update(1,tN,1,rec[i].y1,rec[i].y2-1,rec[i].w);
        cur-=rec[i].w;
        if(rec[i].x!=rec[i+1].x)ans=max(ans,cur+mx[1]);
    }
    printf("%d\n",ans);
    return 0;
}

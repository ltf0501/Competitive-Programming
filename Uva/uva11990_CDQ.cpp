#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
#define maxm 400010
#define ll long long
int n,m;
int a[maxn],pos[maxn];
int del[maxn];
bool isdel[maxn];
ll ans[maxm];
struct P{int id,x,y;};
bool cmp(P a,P b)
{
    if(a.x!=b.x)return a.x<b.x;
    return a.id<b.id;
}
P p[maxm],tmp1[maxm],tmp2[maxm];
int bit[maxn];
void add(int x,int d)
{
    for(int i=x;i<=n;i+=i&-i)bit[i]+=d;
}
int query(int x)
{
    int ret=0;
    for(int i=x;i;i-=i&-i)ret+=bit[i];
    return ret;
}
void cdq(int l,int r)
{
    if(l==r)return ;
    int m=(l+r)>>1;
    for(int i=l;i<=r;i++)///計算(l,m)對(m+1,r)的貢獻
    {
        if(p[i].id<=m)add(p[i].y,1);
        else ans[p[i].id]+=query(p[i].y-1);
    }
    for(int i=l;i<=r;i++)if(p[i].id<=m)add(p[i].y,-1);///把上面復原
    int t1=0,t2=0;
    for(int i=l;i<=r;i++)///把時間對m分開
    {
        if(p[i].id<=m)tmp1[++t1]=p[i];
        else tmp2[++t2]=p[i];
    }
    int cur=l-1;///將p按照時間排好
    for(int i=1;i<=t1;i++)p[++cur]=tmp1[i];
    for(int i=1;i<=t2;i++)p[++cur]=tmp2[i];
    cdq(l,m),cdq(m+1,r);
}
void init()
{
    memset(isdel,0,sizeof(isdel));
    memset(ans,0,sizeof(ans));
}
main()
{
    while(~scanf("%d%d",&n,&m))
    {
        init();
        for(int i=1;i<=n;i++)scanf("%d",&a[i]),pos[a[i]]=i;
        for(int i=1;i<=m;i++)scanf("%d",&del[i]),isdel[del[i]]=1;
        int cnt=0;
        for(int i=1;i<=n;i++)if(!isdel[i])p[++cnt]={cnt,pos[i],n-i+1};
        for(int i=m;i>=1;i--)p[++cnt]={cnt,pos[del[i]],n-del[i]+1};
        ///for(int i=1;i<=n;i++)bit[i]=0;
        sort(p+1,p+cnt+1,cmp);
        cdq(1,n);
        for(int i=1;i<=cnt;i++)p[i].x=n-p[i].x+1,p[i].y=n-p[i].y+1;
        ///for(int i=1;i<=n;i++)bit[i]=0;
        sort(p+1,p+cnt+1,cmp);
        cdq(1,n);
        for(int i=1;i<=cnt;i++)ans[i]+=ans[i-1];
        for(int i=cnt;i>=cnt-m+1;i--)printf("%lld\n",ans[i]);
    }
    return 0;
}

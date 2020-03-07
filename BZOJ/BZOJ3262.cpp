#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
#define maxm 200010
struct P{int x,y,z,id,cnt;}p[maxn],tmp1[maxn],tmp2[maxn];
bool operator < (P a,P b)
{
    if(a.x!=b.x)return a.x<b.x;
    if(a.y!=b.y)return a.y<b.y;
    return a.z<b.z;
}
bool operator == (P a,P b){return a.x==b.x && a.y==b.y && a.z==b.z;}
bool cmp(P a,P b)
{
    if(a.y!=b.y)return a.y<b.y;
    if(a.id!=b.id)return a.id<b.id;
    return a.z<b.z;
}
int bit[maxm];
int n,m,tot,ans[maxn],rev[maxn];
void add(int x,int d)
{
    for(int i=x;i<=m;i+=i&-i)bit[i]+=d;
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
    for(int i=l;i<=r;i++)
    {
        if(p[i].id<=m)add(p[i].z,p[i].cnt);
        else ans[p[i].id]+=query(p[i].z);
    }
    for(int i=l;i<=r;i++)if(p[i].id<=m)add(p[i].z,-p[i].cnt);
    int t1=0,t2=0;
    for(int i=l;i<=r;i++)
    {
        if(p[i].id<=m)tmp1[++t1]=p[i];
        else tmp2[++t2]=p[i];
    }
    int cur=l-1;
    for(int i=1;i<=t1;i++)p[++cur]=tmp1[i];
    for(int i=1;i<=t2;i++)p[++cur]=tmp2[i];
    cdq(l,m),cdq(m+1,r);
}
main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].z);
    sort(p+1,p+n+1);
    p[++tot].id=1,p[tot].cnt=1;
    for(int i=2;i<=n;i++)
    {
        if(p[i]==p[i-1])p[tot].cnt++;
        else p[++tot]=p[i],p[tot].id=tot,p[tot].cnt=1;
    }
    sort(p,p+tot+1,cmp);
    for(int i=1;i<=tot;i++)ans[p[i].id]=p[i].cnt-1;
    cdq(1,tot);
    //for(int i=1;i<=tot;i++)printf("%d %d %d: %d\n",p[i].x,p[i].y,p[i].z,ans[p[i].id]);
    for(int i=1;i<=tot;i++)rev[ans[i]]+=p[i].cnt;
    for(int i=1;i<=tot;i++)printf("%d ",ans[i]);puts("");
    for(int i=0;i<n;i++)printf("%d\n",rev[i]);
    return 0;
}
/*
10
7 2 6
8 6 4
6 6 3
3 1 7
8 7 8
8 7 2
7 10 1
5 6 4
1 3 1
7 3 1
*/

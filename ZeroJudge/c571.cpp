#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
int n;
struct P{int x,y,z,id,ans;}a[maxn],tmp1[maxn],tmp2[maxn];
int ans[maxn];
bool cmp(P a,P b)
{
    if(a.y!=b.y)return a.y<b.y;
    return a.x<b.x;
}
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
    for(int i=l;i<=r;i++)
    {
        if(a[i].x<=m)add(a[i].z,1);
        else a[i].ans+=query(a[i].z-1);
    }
    for(int i=l;i<=r;i++)if(a[i].x<=m)add(a[i].z,-1);
    int t1=0,t2=0;
    for(int i=l;i<=r;i++)
    {
        if(a[i].x<=m)tmp1[++t1]=a[i];
        else tmp2[++t2]=a[i];
    }
    int cur=l-1;
    for(int i=1;i<=t1;i++)a[++cur]=tmp1[i];
    for(int i=1;i<=t2;i++)a[++cur]=tmp2[i];
    cdq(l,m),cdq(m+1,r);
}
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x,y,z;scanf("%d%d%d",&x,&y,&z);
        x=n+1-x,y=n+1-y,z=n+1-z;
        a[i]={x,y,z,i,0};
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++)printf("%d ",a[i].id);puts("");
    cdq(1,n);
    for(int i=1;i<=n;i++)printf("%d %d %d: %d %d\n",a[i].x,a[i].y,a[i].z,a[i].id,a[i].ans);
    return 0;
}
/*
10

3 3 3

2 3 3

2 3 1

3 1 1

3 1 2

1 3 1

1 1 2

1 2 2

1 3 2

1 2 1
*/

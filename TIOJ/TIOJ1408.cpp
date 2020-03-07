#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 1000000+5
struct busy
{
    int l,r,c;
}a[maxn];
bool cmp(busy a,busy b)
{
    return a.r<b.r || (a.r==b.r && a.c>b.c) || (a.r==b.r && a.c==b.c && a.l<b.l);
}
int n;
int bsp[maxn*3];
void add(int a,int b,int id,int l,int r)
{
    if(b<a || a>r || b<l) return;
    if(a<=l && b>=r){bsp[id]=r-l+1;return;}
    int mid=l+(r-l)/2;
    add(a,b,id*2+1,l,mid);
    add(a,b,id*2+2,mid+1,r);
    bsp[id]=bsp[id*2+1]+bsp[id*2+2];
}
int sum(int a,int b,int id,int l,int r)
{
    if(b<a || a>r || b<l)return 0;
    if(a<=l && b>=r)return bsp[id];
    if(bsp[id]==r-l+1)return min(r-a+1,r-l+1);
    int mid=l+(r-l)/2;
    return sum(a,b,id*2+1,l,mid)+sum(a,b,id*2+2,mid+1,r);
}
main()
{
    while(scanf("%d",&n)==1 && n)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d%d%d",&a[i].l,&a[i].r,&a[i].c);
            if(a[i].l>a[i].r)swap(a[i].l,a[i].r);
        }
        memset(bsp,0,sizeof(bsp));
        sort(a,a+n,cmp);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int t=a[i].c-sum(a[i].l,a[i].r-1,0,0,99999);
            if(t<=0)continue;
            ans+=t;
            int l=a[i].l,r=a[i].r;
            while(l<r-1)
            {
                int mid=l+(r-l)/2;;
                if(a[i].r-mid-sum(mid,a[i].r-1,0,0,99999)<t)r=mid;
                else l=mid;
            }
            add(l,a[i].r-1,0,0,99999);
        }
        printf("%d\n",ans);
    }
    return 0;
}

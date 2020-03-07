#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 100000+10
struct node
{
    int l,r,h;
}a[maxn];
int n,setv[maxn<<2],maxv[maxn<<2],ans;
void build(int L,int R,int o)
{
    int M=L+(R-L)/2;
    maxv[o]=0;
    setv[o]=0;
    if(L==R)return ;
    build(L,M,o*2);
    build(M+1,R,o*2+1);
}
void pushdown(int L,int R,int o)
{
    if(setv[o])
    {
        setv[o*2]=setv[o*2+1]=setv[o];
        maxv[o*2]=maxv[o*2+1]=setv[o];
        setv[o]=0;
    }
}
void update(int l,int r,int h,int L,int R,int o)
{
    int M=L+(R-L)/2;
    if(setv[o] && maxv[o]>h)return ;
    if(l<=L && R<=r)
    {
        if(maxv[o]<=h)
        {
            maxv[o]=h;
            setv[o]=h;
            ans+=(R-L+1);
            return ;
        }
    }
    if(L==R)return;
    pushdown(L,R,o);
    if(l<=M)update(l,r,h,L,M,o*2);
    if(M<r)update(l,r,h,M+1,R,o*2+1);
    maxv[o]=max(maxv[o*2],maxv[o*2+1]);
}
main()
{
    int t;
    while(scanf("%d",&t)==1 && t)
    {
        while(t--)
        {
            scanf("%d",&n);
            int m=0;
            for(int i=0;i<n;i++){scanf("%d%d%d",&a[i].l,&a[i].r,&a[i].h);m=max(m,a[i].r);}
            build(1,m,1);
            ans=0;
            for(int i=0;i<n;i++)
            {
                update(a[i].l,a[i].r-1,a[i].h,1,m,1);
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}

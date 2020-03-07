#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 1000000+5
int T[maxn];
int n;
long long cnt;
struct node
{
    int x,v;
    bool operator < (const node& b)const
    {
        return x<b.x || (x==b.x && v<b.v);
    }
}A[maxn];
void mrge(int l,int r)
{
    if(r-l==1)return ;
    int m=l+(r-l)/2;
    mrge(l,m);mrge(m,r);
    int a=l,b=m,idx=l;
    while(a<m && b<r)
    {
        if(A[a].v<=A[b].v)T[idx++]=A[a++].v;
        else T[idx++]=A[b++].v,cnt+=(m-a);
    }
    while(a<m)T[idx++]=A[a++].v;
    while(b<r)T[idx++]=A[b++].v;
    for(int i=l;i<r;i++)A[i].v=T[i];
}
main()
{
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++)scanf("%d%d",&A[i].x,&A[i].v);
        sort(A,A+n);
        //for(int i=0;i<n;i++)printf("%d %d\n",A[i].x,A[i].v);
        cnt=0;
        mrge(0,n);
        printf("%lld\n",cnt);
    }
    return 0;
}


#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 1000000+5
#define INF 2147483647
#define LL long long
LL mx[maxn*4],mi[maxn*4],h[maxn];
int n,m;
void push_up(int id)
{
    mx[id]=max(mx[id*2],mx[id*2+1]);
    mi[id]=min(mi[id*2],mi[id*2+1]);
}
void build(int l,int r,int id)
{
    if(l==r){mx[id]=mi[id]=h[l];return ;}
    int m=l+(r-l)/2;
    build(l,m,id*2);build(m+1,r,id*2+1);
    push_up(id);
}
LL query_max(int L,int R,int l,int r,int id)
{
    if(L<=l && r<=R)return mx[id];
    int m=l+(r-l)/2;
    LL ans=0;
    if(L<=m)ans=max(ans,query_max(L,R,l,m,id*2));
    if(R>m)ans=max(ans,query_max(L,R,m+1,r,id*2+1));
    return ans;
}
LL query_min(int L,int R,int l,int r,int id)
{
    if(L<=l && r<=R)return mi[id];
    int m=l+(r-l)/2;
    LL ans=INF;
    if(L<=m)ans=min(ans,query_min(L,R,l,m,id*2));
    if(R>m)ans=min(ans,query_min(L,R,m+1,r,id*2+1));
    return ans;
}
main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&h[i]);
    build(1,n,1);
    while(m--)
    {
        int L,R;scanf("%d%d",&L,&R);
        LL MX=query_max(L,R,1,n,1);
        LL MI=query_min(L,R,1,n,1);
        printf("%lld\n",MX-MI);
    }
    return 0;
}

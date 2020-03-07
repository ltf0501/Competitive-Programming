#include<bits/stdc++.h>
using namespace std;
#define maxn 300010
#define ll long long
struct P
{
    int x,y;
    ll d;
    bool operator < (const P& rhs)const
    {
        return x<rhs.x || (x==rhs.x && y>rhs.y);
    }
}a[maxn];
int n,m,k;
ll bit[maxn];
void update(int x,ll d)
{
    for(int i=x;i<=m;i+=i&-i)bit[i]=max(bit[i],d);
}
ll query(int x)
{
    ll ret=0;
    for(int i=x;i;i-=i&-i)ret=max(ret,bit[i]);
    return ret;
}
main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=k;i++)scanf("%d%d%lld",&a[i].x,&a[i].y,&a[i].d);
    sort(a+1,a+k+1);
    ll ans=0;
    //for(int i=1;i<=k;i++)printf("%d %d %lld\n",a[i].x,a[i].y,a[i].d);
    for(int i=1;i<=k;i++)
    {
        ll tmp=query(a[i].y-1)+a[i].d;
        //printf("%lld\n",tmp);
        ans=max(ans,tmp);
        update(a[i].y,tmp);
    }
    printf("%lld\n",ans);
    return 0;
}
/*
2 3 6
1 1 3
1 2 4
1 3 6
2 1 7
2 2 2
2 3 4
*/

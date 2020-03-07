#include<bits/stdc++.h>
using namespace std;
#define maxn 1100
#define ll long long
ll c[maxn][maxn];
int n;
void add(int x,int y,int d)
{
    for(;x<=n;x+=(x&-x))
        for(int j=y;j<=n;j+=(j&-j))c[x][j]+=d;
}
ll sum(int x,int y)
{
    ll ret=0;
    for(;x;x-=(x&-x))
        for(int j=y;j;j-=(j&-j))ret+=c[x][j];
    return ret;
}
main()
{
    scanf("%d",&n);
    int c;
    while(~scanf("%d",&c))
    {
        if(c==1)
        {
            int x,y,d;scanf("%d%d%d",&x,&y,&d);
            x++,y++;
            add(x,y,d);
        }
        else
        {
            int x1,y1,x2,y2;scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            x1++,y1++,x2++,y2++;
            ll ans=sum(x2,y2)-sum(x2,y1-1)-sum(x1-1,y2)+sum(x1-1,y1-1);
            printf("%lld\n",ans);
        }
    }
    return 0;
}

#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 100000+5
struct node
{
    int x,y,h;
    bool operator < (const node& b)const
    {
        return x*x+y*y<b.x*b.x+b.y*b.y;
    }
}p[maxn];
main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        for(int i=1;i<=n;i++)scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].h);
        sort(p+1,p+n+1);
        int ans=0,Max=0;
        for(int i=1;i<=n;i++)
        {
            ans=max(ans,Max-p[i].h);
            Max=max(Max,p[i].h);
        }
        printf("%d\n",ans);
    }
    return 0;
}

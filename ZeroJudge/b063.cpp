#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
#define maxn 1000+10
#define inf 2147483647
int d[maxn][maxn];
struct Point
{
    int x,y;
    bool operator < (const Point& rhs) const
    {
        return x<rhs.x || (x==rhs.x && y<rhs.y);
    }
};
int dist(Point a,Point b)
{
    return abs(a.x-b.x)+abs(a.y-b.y);
}
main()
{
    int n;
    Point p[maxn];
    while(scanf("%d",&n)==1)
    {
        for(int i=1;i<=n;i++)scanf("%d %d",&p[i].x,&p[i].y);
        sort(p+1,p+n+1);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)d[i][j]=dist(p[i],p[j]);
        /*
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)printf("%d ",d[i][j]);
            puts("");
        }
        */
        int ans=inf,idx=0;
        for(int i=1;i<=n;i++)
        {
            int t=0;
            for(int j=1;j<=n;j++)t+=d[i][j];
            if(t<ans)
            {
                idx=i;
                ans=t;
            }
        }
        printf("%d %d\n%d\n",p[idx].x,p[idx].y,ans);

    }
    return 0;
}

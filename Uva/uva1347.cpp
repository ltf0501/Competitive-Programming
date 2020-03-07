#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
#define maxn 1000+10
int n;
struct Point
{
    int x,y;
    bool operator < (const Point& rhs) const
    {
        return (x<rhs.x) || ((x==rhs.x) && (y<rhs.y));
    }
}p[maxn];
double dp[maxn][maxn];
double dist(Point a,Point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

main()
{
    while(scanf("%d",&n)==1)
    {
        for(int i=1;i<=n;i++)scanf("%d%d",&p[i].x,&p[i].y);
        sort(p+1,p+n+1);
        for(int i=1;i<n-1;i++)dp[n-1][i]=dist(p[n-1],p[n])+dist(p[i],p[n]);
        for(int i=n-2;i>=1;i--)
        {
            for(int j=1;j<i;j++)
            {
                dp[i][j]=min(dp[i+1][j]+dist(p[i],p[i+1]),dp[i+1][i]+dist(p[j],p[i+1]));
            }
        }
        printf("%.2lf\n",dp[2][1]+dist(p[1],p[2]));
    }

    return 0;
}

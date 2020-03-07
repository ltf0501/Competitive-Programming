#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
struct Point
{
    double x,y;
    bool operator < (const Point& rhs)const
    {
        return x<rhs.x;
    }
}point[10005];
double dis(Point a,Point b)
{
    return (double)sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
}
double combine(Point *a,int low,int mid,int high,double min_left,double min_right)
{
    double d=min(min_left,min_right);
    double line=(double)(a[mid].x+a[mid+1].x)*0.5;
    double min_d=d;
    for(int i=mid+1;a[i].x<line+d && i<=high;i++)
    {
        for(int j=mid;a[j].x>line-d && j>=low;j--)
        {
            min_d=min(min_d,dis(a[i],a[j]));
        }
    }
    return min_d;
}
double divide(Point *a,int low,int high)
{
    if(low>=high) return 99999;
    int mid=low+(high-low)/2;
    double min_left=divide(a,low,mid);
    double min_right=divide(a,mid+1,high);
    return combine(a,low,mid,high,min_left,min_right);
}

main()
{
    int n;
    while(scanf("%d",&n)==1 && n)
    {
        for(int i=0;i<n;i++)scanf("%lf%lf",&point[i].x,&point[i].y);
        sort(point,point+n);
        double dist=divide(point,0,n-1);
        if(dist>=10000.0)printf("INFINITY\n");
        else printf("%.4lf\n",dist);
    }
    return 0;
}

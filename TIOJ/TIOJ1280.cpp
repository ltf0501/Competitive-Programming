#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

struct point
{
    int x,y;
    point(){x=0,y=0;}
	point(int _x,int _y){x=_x,y=_y;}
    bool operator < (const point& b)const
    {
        return x<b.x || (x==b.x && y<b.y);
    }
    int operator % (const point& b)const
    {
        return x*b.y-y*b.x;
    }
    point operator - (const point& b)const
    {
        point a(x-b.x,y-b.y);
        return a;
    }
};
int cross(point a,point b)
{
    return a%b;
}
int area(vector<point> p)
{
    int ans=0;
    for(int i=0;i<p.size();i++)
        ans+=cross(p[i],p[(i+1)%p.size()]);
    return ans;
}
main()
{
    int n,x,y;
    point a;
    scanf("%d",&n);
    vector<point> v;
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&x,&y);
        a.x=x;
        a.y=y;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    vector<point> ans(v.size()*2);
    int top=0;
    for(int i=0;i<v.size();i++)
    {
        while(top>1 && cross(v[i]-ans[top-1],ans[top-1]-ans[top-2])<=0)top--;
        ans[top++]=v[i];
    }
    int t=top;
    for(int i=v.size()-2;i>=0;i--)
    {
        while(top>t && cross(v[i]-ans[top-1],ans[top-1]-ans[top-2])<=0)top--;
		ans[top++]=v[i];
    }
    ans.resize(top-1);
    int ar=area(ans);
    printf("%d\n",(int)(abs(ar)/2.0+0.5));
    return 0;
}

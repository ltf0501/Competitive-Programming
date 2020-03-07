#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
#define ll long long 
struct Point
{
	ll x,y;
	Point(){}
	Point(ll _x,ll _y){x=_x,y=_y;}
	bool operator < (const Point& rhs)const
	{
		return x!=rhs.x ? x<rhs.x : y<rhs.y;
	}
	Point operator + (const Point& rhs)const 
	{
		return Point(x+rhs.x,y+rhs.y);
	}
	Point operator - (const Point& rhs)const 
	{
		return Point(x-rhs.x,y-rhs.y);
	}
	ll operator * (const Point& rhs)const 
	{
		return x*rhs.x+y*rhs.y;
	}
	ll operator ^ (const Point& rhs)const 
	{
		return x*rhs.y-y*rhs.x;
	}
};
ll dis(Point a, Point b)
{
	return (a-b)*(a-b);
}
struct Geometry
{
	vector<Point> v;
	vector<int> convex;
	void init()
	{
		v.clear();
		convex.clear();
	}
	void add_point(int a,int b)
	{
		v.push_back(Point(a,b));
	}
	void Convex_Hull(int &r)
	{
		sort(v.begin(),v.end());
		vector<int> tmp;
		for(int i=0;i<(int)v.size();i++)
		{
			int SZ;
			while((SZ=(int)tmp.size())>=2 && ((v[tmp[SZ-1]]-v[tmp[SZ-2]])^(v[i]-v[tmp[SZ-2]]))<=0)tmp.pop_back();
			tmp.push_back(i);
		}
		r=(int)tmp.size()-1;
		for(int i=0;i<(int)tmp.size();i++)convex.push_back(tmp[i]);
		tmp.clear();
		for(int i=(int)v.size()-1;i>=0;i--)
		{
			int SZ;
			while((SZ=(int)tmp.size())>=2 && ((v[tmp[SZ-1]]-v[tmp[SZ-2]])^(v[i]-v[tmp[SZ-2]]))<=0)tmp.pop_back();
			tmp.push_back(i);
		}
		for(int i=1;i<(int)tmp.size();i++)convex.push_back(tmp[i]);
	}
	ll cal()
	{
		if(v.size()==1)return 0;
		if(v.size()==2)return dis(v[0],v[1]);
		int r;
		Convex_Hull(r);
//		for(int i : convex)printf("%d: %lld %lld\n",i,v[i].x,v[i].y);
		ll ans=0;
		for(int i=0,j=r;i<r && r<(int)convex.size()-1;i++)
		{
//			printf("%d %d: %lld\n",convex[i],convex[j],dis(v[convex[i]],v[convex[j]]));
			ans=max(ans,dis(v[convex[i]],v[convex[j]]));
			while(((v[convex[i+1]]-v[convex[i]])^(v[convex[j+1]]-v[convex[j]]))>0)j++,ans=max(ans,dis(v[convex[i]],v[convex[j]]));
//				printf("%d %d: %lld\n",convex[i],convex[j],dis(v[convex[i]],v[convex[j]]));
		}
		return ans;
	}
};

int main()
{
	int n;scanf("%d",&n);
	Geometry solver;
	solver.init();
	for(int i=1;i<=n;i++)
	{
		ll x,y;scanf("%lld%lld",&x,&y);
		solver.add_point(x,y);
	}
	printf("%lld\n",solver.cal());
	return 0;
}

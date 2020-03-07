#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define F first
#define S second
pii a[4],b[4];
bool check(double x,double y,int l,int r,int u,int d)
{
    return l<=x && x<=r && d<=y && y<=u;
}
bool gao()
{
    double x=(b[0].F+b[1].F+b[2].F+b[3].F)/4,y=(b[0].S+b[1].S+b[2].S+b[3].S)/4;
    int u=max({a[0].S,a[1].S,a[2].S,a[3].S});
    int d=min({a[0].S,a[1].S,a[2].S,a[3].S});
    int l=min({a[0].F,a[1].F,a[2].F,a[3].F});
    int r=max({a[0].F,a[1].F,a[2].F,a[3].F});
    bool flag=check(x,y,l,r,u,d);
    for(int i=0;i<4;i++)flag|=check(b[i].F,b[i].S,l,r,u,d);
    return flag;
}
main()
{
    for(int i=0;i<4;i++)scanf("%d%d",&a[i].F,&a[i].S);
    for(int i=0;i<4;i++)scanf("%d%d",&b[i].F,&b[i].S);
    if(gao())return 0*puts("YES");
    for(int i=0;i<4;i++)swap(a[i],b[i]);
    for(int i=0;i<4;i++)
    {
        int x=a[i].F,y=a[i].S;
        a[i].F=x+y,a[i].S=x-y;
        x=b[i].F,y=b[i].S;
        b[i].F=x+y,b[i].S=x-y;
    }
    if(gao())puts("YES");
    else puts("NO");
    return 0;
}


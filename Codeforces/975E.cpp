#include<bits/stdc++.h>
using namespace std;
#define maxn 10010
const double pi=acos(-1.0);
struct P
{
    double x,y;
    P(){}
    P(double x,double y):x(x),y(y){}
    P operator + (const P& a)const{return P(x+a.x,y+a.y);}
    P operator - (const P& a)const{return P(x-a.x,y-a.y);}
    P operator * (double t)const{return P(x*t,y*t);}
    P operator / (double t)const{return P(x/t,y/t);}
    double operator % (const P& a){return x*a.y-y*a.x;}
    double operator * (const P& a){return x*a.x+y*a.y;}
    P rot(double angle)
    {
        return P(x*cos(angle)-y*sin(angle),x*sin(angle)+y*cos(angle));
    }
    double operator ^ (const P& a){return atan2(*this%a,*this*a);}
};
P cen,point[maxn];
int n,q;
void print(P c)
{
    cout<<fixed<<setprecision(10)<<c.x<<" "<<c.y<<'\n';
}
main()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)scanf("%lf%lf",&point[i].x,&point[i].y);
    double mm=0;
    for(int i=2;i<n;i++)
    {
        P tmp=(point[1]+point[i]+point[i+1])/3;
        double tmm=fabs((point[i+1]-point[1])%(point[i]-point[1]));
        cen=cen*mm+tmp*tmm;
        mm+=tmm;
        cen=cen/mm;
    }
    //print(cen);
    for(int i=1;i<=n;i++)point[i]=point[i]-cen;
    double angle=0;
    int a=1,b=2;
    while(q--)
    {
        int type;scanf("%d",&type);
        if(type==1)
        {
            int c;scanf("%d",&c);
            if(a!=c)swap(a,b);
            cen=cen+point[b].rot(angle);
            double tmp=(point[b].rot(angle))^(P(0,1));
            angle+=tmp;
            if(angle>2*pi)angle-=2*pi;
            if(angle<0)angle+=2*pi;
            cen=cen-point[b].rot(angle);
            scanf("%d",&c);
            a=c;
        }
        else
        {
            int id;scanf("%d",&id);
            P ans=point[id].rot(angle)+cen;
            print(ans);
        }
    }
    return 0;
}

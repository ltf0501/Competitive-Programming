#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
const double eps=1e-9;
int x[maxn],y[maxn];
int n;
double val(double b,double x,double y)
{
    x=fabs(b-x);
    y=fabs(y);
    return (x*x+y*y)/(2*y);
}
double cal(double b)
{
    double ret=0;
    for(int i=1;i<=n;i++)
    {
        ret=max(ret,val(b,x[i],y[i]));
    }
    return ret;
}
main()
{
    cin.tie(0);ios::sync_with_stdio(false);
    cin>>n;
    int flag=0;
    for(int i=1;i<=n;i++)
    {
        cin>>x[i]>>y[i];
        if(y[i]>0)flag|=2;
        else flag|=1;
    }
    if(flag==3)return cout<<-1<<'\n',0;
    double l=-1e7,r=1e7;
    double x=cal(l),y=cal(r);
    while(1)
    {
        double t1,t2;
        double k1=(2*l+r)/3,k2=(l+2*r)/3;
        if((t1=cal(k1))<(t2=cal(k2)))r=k2,y=t2;
        else l=k1,x=t1;
        //cout<<x<<' '<<y<<'\n';
        if(r-l<1e-6)break;
    }
    cout<<fixed<<setprecision(9)<<(x+y)/2<<'\n';
    return 0;
}

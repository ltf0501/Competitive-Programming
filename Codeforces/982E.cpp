#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,dx,dy;
int Exgcd(int a,int b,int &x,int &y)
{
    if(!b)
    {
        x=1;y=0;
        return a;
    }
    int d=Exgcd(b,a%b,x,y);
    int t=x;
    x=y;
    y=t-(a/b)*y;
    return d;
}
main()
{
    scanf("%d%d%d%d%d",&n,&m,&x,&y,&dx,&dy);
    if(dx==0)
    {
        if(x==0 || x==n)printf("%d %d\n",x,dy==-1 ? 0 : m);
        else puts("-1");
        return 0;
    }
    if(dy==0)
    {
        if(y==0 || y==m)printf("%d %d\n",dx==1 ? n : 0,y);
        else puts("-1");
        return 0;
    }
    int g=__gcd(n,m);
    if(dx==-1)x=-x;
    if(dy==-1)y=-y;
    int k=x-y;
    if(k%g!=0)return 0*puts("-1");
    m/=g,n/=g,k/=g;

    return 0;
}

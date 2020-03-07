#include<bits/stdc++.h>
using namespace std;
#define ll long long
void exgcd(ll a,ll b,ll &d,ll &x,ll &y)
{
    if(!b)d=a,x=1,y=0;
    else exgcd(b,a%b,d,y,x),y-=(a/b)*x;
}
void gao(int t1,int t2,int a,int b,int x,int y)
{
    int cura=0,curb=0;
    while(1)
    {
        if(curb==b)
        {
            printf("2 %d\n",t2);
            y--;
            curb=0;
        }
        else
        {
            if(!cura)
            {
                printf("1 %d\n",t1);
                x--;
                cura=a;
            }
            printf("3 %d %d\n",t1,t2);
            if(cura>b-curb)cura-=b-curb,curb=b;
            else curb+=cura,cura=0;
        }
        if(!x && !y)break;
    }
    if(cura && curb)
    {
        if(b>a)printf("3 %d %d\n",t2,t1);
        else printf("3 %d %d\n",t1,t2);
    }
}
main()
{
    ll a,b,k;scanf("%lld%lld%lld",&a,&b,&k);
    if(k>a && k>b)return 0*puts("0");
    ll d,x,y;
    exgcd(a,b,d,x,y);y=-y;

    if(k%d!=0)return 0*puts("0");
    int s=k/d;
    x*=s,y*=s;
    while(x<0 || y<0)x+=b,y+=a;
    while(x>=0 && y>=0)x-=b,y-=a;
    x+=b,y+=a;
    //printf("%lld %lld\n",x,y);
    if(x+y<=a+b)gao(1,2,a,b,x,y);
    else
    {
        x=-x,y=-y;
        while(x<0 || y<0)x+=b,y+=a;
        while(x>=0 && y>=0)x-=b,y-=a;
        x+=b,y+=a;
        if(x+y<=a+b)gao(2,1,b,a,y,x);
    }
    puts("0");
    return 0;
}

#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define LL long long
main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
       // printf("%d\n",t)
        LL a[5];
        for(int i=1;i<=3;i++)scanf("%lld",&a[i]);
       // puts("°®");
        sort(a+1,a+4);
        if(a[3]*a[3]-a[2]*a[2]>a[1]*a[1])puts("obtuse triangle");
        if(a[3]*a[3]-a[2]*a[2]==a[1]*a[1])puts("right triangle");
        if(a[3]*a[3]-a[2]*a[2]<a[1]*a[1])puts("acute triangle");
    }
    return 0;
}

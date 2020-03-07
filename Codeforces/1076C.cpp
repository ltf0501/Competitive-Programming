#include<bits/stdc++.h>
using namespace std;
int n;
main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int d;scanf("%d",&d);
        if(d*d-4*d<0){puts("N");continue;}
        double a=(double)(d+sqrt(d*d-4*d))/2.0;
        double b=(double)(d-sqrt(d*d-4*d))/2.0;
        printf("Y %.9f %.9f\n",a,b);
    }
    return 0;
}

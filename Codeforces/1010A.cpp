#include<bits/stdc++.h>
using namespace std;
#define maxn 1010
int n,m;
int a[maxn],b[maxn];
main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)scanf("%d",&b[i]);
    double l=0,r=1e9+7;
    for(int t=0;t<100;t++)
    {
        double M=(l+r)/2;
        double umr=M;
        for(int i=1;i<=n;i++)
        {
            umr-=(umr+m)/a[i];
            if(umr<0)break;
            umr-=(umr+m)/b[i];
            if(umr<0)break;
        }
        if(umr>=0)r=M;
        else l=M;
    }
    if(r>=1e9+5)puts("-1");
    else printf("%.9f\n",r);
    return 0;
}


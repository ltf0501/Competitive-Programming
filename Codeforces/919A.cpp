#include<bits/stdc++.h>
using namespace std;

main()
{
    int n,m;scanf("%d%d",&n,&m);
    int now_a=1000000,now_b=1;
    for(int i=1;i<=n;i++)
    {
        int a,b;scanf("%d%d",&a,&b);
        if(now_a*b>now_b*a)now_a=a,now_b=b;
    }
    double ans=(m*now_a*1.0)/(now_b*1.0);
    printf("%f\n",ans);
    return 0;
}


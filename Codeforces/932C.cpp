#include<bits/stdc++.h>
using namespace std;

main()
{
    int n,a,b;scanf("%d%d%d",&n,&a,&b);
    int x,y;
    bool flag=0;
    for(int i=0;i*a<=n;i++)if((n-i*a)%b==0)
    {
        x=i,y=(n-i*a)/b,flag=1;
        break;
    }
    if(!flag)return 0*puts("-1");
    int cur=1;
    while(x--)
    {
        for(int i=1;i<a;i++)printf("%d ",cur+i);
        printf("%d ",cur);
        cur+=a;
    }
    while(y--)
    {
        for(int i=1;i<b;i++)printf("%d ",cur+i);
        printf("%d ",cur);
        cur+=b;
    }
    return 0;
}


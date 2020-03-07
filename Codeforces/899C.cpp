#include<bits/stdc++.h>
using namespace std;

main()
{
    int n;scanf("%d",&n);
    if(n%4==1)
    {
        puts("1");
        int k=n/4;
        printf("%d ",2*k+1);
        printf("%d ",1);
        for(int i=1;i<=k;i++)printf("%d ",4*i-2);
        for(int i=1;i<=k;i++)printf("%d ",4*i+1);
    }
    else if(n%4==2)
    {
        puts("1");
        int k=n/4;
        printf("%d ",2*k+1);
        for(int i=1;i<=k+1;i++)printf("%d ",4*i-3);
        for(int i=1;i<=k;i++)printf("%d ",4*i);
    }
    else if(n%4==3)
    {
        puts("0");
        int k=n/4;
        printf("%d ",2*k+1);
        printf("%d ",3);
        for(int i=1;i<=k;i++)printf("%d ",4*i);
        for(int i=1;i<=k;i++)printf("%d ",4*i+3);
    }
    else
    {
        puts("0");
        int k=n/4;
        printf("%d ",2*k);
        for(int i=1;i<=k;i++)printf("%d ",4*i-3);
        for(int i=1;i<=k;i++)printf("%d ",4*i);
    }
    return 0;
}

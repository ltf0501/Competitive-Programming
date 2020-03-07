#include<bits/stdc++.h>
using namespace std;

main()
{
    int s=1;
    for(int i=0;i<18;i++)s*=2;
    int n,x;scanf("%d%d",&n,&x);
    if(n==1)
    {
        puts("YES");
        printf("%d\n",x);
        return 0;
    }
    if(n==2)
    {
        if(x==0)puts("NO");
        else
        {
            puts("YES");
            printf("%d %d\n",x,0);
        }
        return 0;
    }
    puts("YES");
    int t=0;
    for(int i=1;i<n-1;i++)t^=i;
    if(t!=x)
    {
        printf("%d %d ",s,s^x^t);
        for(int i=1;i<n-1;i++)printf("%d ",i);
        puts("");
    }
    else
    {
        t^=(1^(n-1));
        printf("%d %d ",s,s^x^t);
        for(int i=2;i<n;i++)printf("%d ",i);
        puts("");
    }
    return 0;
}

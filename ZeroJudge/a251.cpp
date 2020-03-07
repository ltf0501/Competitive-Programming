#include<bits/stdc++.h>
using namespace std;
int a[25];
main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int n;scanf("%d",&n);
        for(int i=1;i<=4;i++)scanf("%d",&a[i]);
        for(int i=5;i<=n;i++)a[i]=a[i-1]+a[i-4];
        sort(a+1,a+n+1);
        if(n&1)printf("%d\n",a[(n+1)/2]);
        else printf("%d\n",(a[n/2]+a[n/2]+1)/2);

    }
    return 0;
}

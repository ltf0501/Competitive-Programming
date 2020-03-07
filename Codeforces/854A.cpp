#include<bits/stdc++.h>
using namespace std;

main()
{
    int n;scanf("%d",&n);
    int a;
    for(int i=n/2;i>=1;i--)if(__gcd(i,n)==1)
    {
        a=i;break;
    }
    printf("%d %d\n",a,n-a);
    return 0;
}


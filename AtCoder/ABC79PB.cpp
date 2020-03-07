#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[90];
main()
{
    int n;scanf("%d",&n);
    a[0]=2;a[1]=1;
    for(int i=2;i<=86;i++)a[i]=a[i-1]+a[i-2];
    printf("%lld\n",a[n]);
    return 0;
}


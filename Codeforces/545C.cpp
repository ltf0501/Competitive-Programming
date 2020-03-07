#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
int a[maxn],h[maxn],n;
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d%d",&a[i],&h[i]);
    if(n==1)return 0*puts("1");
    int cnt=2;
    int d=0;
    for(int i=2;i<n;i++)
    {
        if(h[i]+d<a[i]-a[i-1])cnt++,d=0;
        else if(h[i]<a[i+1]-a[i])cnt++,d=h[i];
        else d=0;
    }
    printf("%d\n",cnt);
    return 0;
}

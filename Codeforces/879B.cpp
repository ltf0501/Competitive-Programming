#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[505],n;
ll k;
main()
{
    scanf("%d%I64d",&n,&k);
    int s;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    if(k>=n-1){printf("%d\n",n);return 0;}
    ll cnt=0;
    int id=1;
    for(int i=2;i<=n;i++)
    {
        if(a[id]>a[i])cnt++;
        else id=i,cnt=1;
        if(cnt==k){printf("%d\n",a[id]);return 0;}
    }
    printf("%d\n",n);
    return 0;
}

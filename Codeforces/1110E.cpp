#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
#define ll long long
ll a[maxn],b[maxn];
main()
{
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++)scanf("%lld",&b[i]);
    if(a[1]!=b[1] || a[n]!=b[n])return 0*puts("No");
    for(int i=1;i<n;i++)a[i]=a[i+1]-a[i],b[i]=b[i+1]-b[i];
    sort(a+1,a+n),sort(b+1,b+n);
    for(int i=1;i<n;i++)if(a[i]!=b[i])return 0*puts("No");
    puts("Yes");
    return 0;
}

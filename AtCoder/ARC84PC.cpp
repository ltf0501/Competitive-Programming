#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 100010
int n;
int a[maxn],b[maxn],c[maxn];
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)scanf("%d",&b[i]);
    for(int i=1;i<=n;i++)scanf("%d",&c[i]);
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    sort(c+1,c+n+1);
    ll cnt=0;
    for(int i=1;i<=n;i++)
    {
        int x=lower_bound(a+1,a+n+1,b[i])-a;
        int y=upper_bound(c+1,c+n+1,b[i])-c;
        cnt+=(ll)(x-1)*(ll)(n-y+1);
    }
    printf("%lld\n",cnt);
    return 0;
}


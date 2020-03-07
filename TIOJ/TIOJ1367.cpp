#include<bits/stdc++.h>
using namespace std;
#define maxn 50010
#define ll long long
int a[maxn],b[maxn];
int n;
main()
{
    while(~scanf("%d",&n))
    {
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        for(int i=1;i<=n;i++)scanf("%d",&b[i]);
        ll ans=0;
        sort(a+1,a+n+1),sort(b+1,b+n+1);
        for(int i=1;i<=n;i++)ans+=a[i]*b[n-i+1];
        printf("%lld\n",ans);
    }
    return 0;
}

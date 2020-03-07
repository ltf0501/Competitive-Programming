#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
int a[maxn],ok[maxn],sum[maxn];
int n,k;
main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)scanf("%d",&ok[i]);
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+(1-ok[i])*a[i];
    int ans=0;
    for(int i=1;i<=n;i++)ans+=ok[i]*a[i];
    int mx=0;
    for(int i=k;i<=n;i++)mx=max(mx,sum[i]-sum[i-k]);
    printf("%d\n",ans+mx);
    return 0;
}


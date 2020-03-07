#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
#define ll long long
int n;
int a[maxn],num[maxn];
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
    {
        num[i]=num[i-1];
        num[i]=max(num[i],a[i]+1);
    }
    for(int i=n-1;i>=1;i--)num[i]=max(num[i],num[i+1]-1);
    //for(int i=1;i<=n;i++)printf("%d ",num[i]);puts("");
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        ans+=num[i]-a[i]-1;
        //printf("%d %d\n",i,num[i]==num[i-1] ? num[i]-a[i]-1 : 0);
    }
    printf("%lld\n",ans);
    return 0;
}

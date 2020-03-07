#include<cstdio>
#include<algorithm>
using namespace std;
#define maxn 5000000+5
#define ll long long
ll A[maxn],c[maxn];
main()
{
    int n;scanf("%d",&n);
    ll sum=0;
    for(int i=1;i<=n;i++)scanf("%lld",&A[i]),sum+=A[i];
    sum/=n;
    c[0]=0;
    for(int i=1;i<n;i++)c[i]=c[i-1]+A[i]-sum;
    sort(c,c+n);
    ll k=c[n/2],ans=0;
    for(int i=0;i<n;i++)ans+=abs(k-c[i]);
    printf("%lld\n",ans);
    return 0;
}

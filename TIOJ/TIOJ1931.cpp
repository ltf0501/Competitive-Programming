#include<cstdio>
#include<algorithm>
using namespace std;
#define maxn 100000+5
#define LL long long
LL a[maxn];
main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int n;scanf("%d",&n);
        for(int i=0;i<n;i++)scanf("%lld",&a[i]);
        sort(a,a+n);
        LL sum=0;
        for(int i=n-2;i>=0;i-=2)sum+=a[i];
        printf("%lld\n",4*sum);
    }
    return 0;
}

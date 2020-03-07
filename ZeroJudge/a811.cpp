#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define LL long long
#define maxn 10000+5
LL gcd(LL a,LL b)
{
    if(a<b)swap(a,b);
    return b==0 ? a : gcd(b,a%b);
}
int n;
LL a[maxn],s[maxn];
main()
{
    int t;scanf("%d",&t);
    while(t--)
    {

        scanf("%d",&n);
        a[0]=0;
        for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
        sort(a+1,a+n+1);
        for(int i=1;i<=n-1;i++)s[i]=a[i+1]-a[i];

        if(n==2)printf("%lld\n",s[1]);
        else
        {
            LL ans=gcd(s[1],s[2]);
            for(int i=3;i<=n-1;i++)ans=gcd(ans,s[i]);
            printf("%lld\n",ans);
        }
    }
    return 0;
}

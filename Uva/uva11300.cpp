#include<cstdio>
#include<algorithm>
using namespace std;
#define maxn 1000000+10
long long A[maxn],C[maxn],total,M;
main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        total=0;
        for(int i=1;i<=n;i++){scanf("%lld",&A[i]); total+=A[i];}
        M=total/n;
        C[0]=0;
        for(int i=1;i<n;i++)C[i]=C[i-1]+A[i]-M;
        sort(C,C+n);
        long long x=C[n/2],ans=0;
        for(int i=0;i<n;i++)ans+=abs(x-C[i]);

        printf("%lld\n",ans);
    }
    return 0;
}


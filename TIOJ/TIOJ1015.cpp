#include<cstdio>
#include<algorithm>
using namespace std;

long long m,n;
int main()
{
    while(~scanf("%lld %lld",&m,&n) && m+n)
    {
        if(m<n)swap(m,n);
        printf("%lld\n",m*n*(n+1)-n*(n+1)/2*(m+n)+n*(n+1)*(2*n+1)/6);
    }
    return 0;
}

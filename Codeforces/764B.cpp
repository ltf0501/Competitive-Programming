#include<cstdio>
#include<algorithm>
using namespace std;
#define maxn 100000+5
int a[2*maxn];
main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        for(int i=1;i<=n-i+1;i+=2)swap(a[i],a[n-i+1]);
        for(int i=1;i<=n;i++)printf("%d ",a[i]);
        puts("");
    }
    return 0;
}

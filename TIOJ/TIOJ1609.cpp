#include<cstdio>
#include<algorithm>
using namespace std;
#define maxn 1000000+10
int a[maxn];
main()
{
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    sort(a,a+n);
    for(int i=0;i<n;i++)printf("%d ",a[i]);
    puts("");
    return 0;
}

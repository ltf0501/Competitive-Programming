#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 500000+10
int n,q;
int a[maxn];
main()
{
    while(scanf("%d%d",&n,&q)==2)
    {
        for(int i=0;i<n;i++)scanf("%d",&a[i]);
        sort(a,a+n);
        while(q--)
        {
            int p;scanf("%d",&p);
            int cnt=upper_bound(a,a+n,p)-a;
            printf("%d\n",cnt%2);
        }
    }
    return 0;
}

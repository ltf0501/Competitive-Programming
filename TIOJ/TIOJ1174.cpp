#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 100000+5
#define INF 1000000000
int a[maxn],b[maxn];
main()
{
    int n,m;scanf("%d%d",&n,&m);
    if(n<m)swap(n,m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=m;i++)scanf("%d",&b[i]);
    int ans=INF;
    sort(a+1,a+n+1);
    for(int i=1;i<=m;i++)
    {
        int k=lower_bound(a+1,a+n+1,b[i])-a;
        if(k>1)ans=min(ans,b[i]-a[k-1]);
        if(k<=n)ans=min(ans,a[k]-b[i]);
    }
    printf("%d\n",ans);
    return 0;
}

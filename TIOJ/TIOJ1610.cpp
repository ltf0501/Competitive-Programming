#include<cstdio>
#include<algorithm>
using namespace std;
#define maxn 20000+5
#define LL long long
int L[maxn],W[maxn];
bool cmp(int i,int j)
{
    return i>j;
}
main()
{
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&W[i]);
    for(int i=1;i<n;i++)scanf("%d",&L[i]);
    sort(L+1,L+n,cmp);
    sort(W+1,W+n+1);
    LL ans=0,w=W[1];
    for(int i=1;i<n;i++)ans+=L[i]*w,w+=W[i+1];
    printf("%lld\n",ans);
    return 0;
}

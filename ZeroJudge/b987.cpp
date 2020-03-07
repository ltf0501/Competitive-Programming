#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 1000000+5
#define ll long long
int n,m;
int r[maxn],f[maxn],s[maxn],t[maxn];
ll a[maxn];
bool check(int k)
{
    memset(a,0,sizeof(a));
    for(int i=1;i<=k;i++)a[s[i]]+=f[i],a[t[i]+1]-=f[i];
    ll sum=0;
    for(int i=1;i<=n;i++){sum+=a[i];if(sum>r[i])return 0;}
    return 1;
}
main()
{
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=1;i<=n;i++)scanf("%d",&r[i]);
        for(int i=1;i<=m;i++)scanf("%d%d%d",&f[i],&s[i],&t[i]);
        int l=0,r=m+1;
        while(l+1<r)
        {
            int mid=(l+r)/2;
            if(check(mid))l=mid;
            else
                r=mid;
        }
        if(l==m)printf("0\n");
        else printf("-1\n%d\n",l+1);
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
#define ll long long
int n,k,l;
int a[maxn];
main()
{
    scanf("%d%d%d",&n,&k,&l);
    int m=n*k;//¤Àn°ï
    for(int i=1;i<=m;i++)scanf("%d",&a[i]);
    sort(a+1,a+m+1);
    if(a[n]-a[1]>l)return 0*puts("0");
    ll ans=0;
    int cur=k;
    //for(int i=1;i<=m;i++)printf("%d ",a[i]);puts("");
    for(int i=m;i>=1;i--)
    {
        if(m+1-i>=cur && a[i]-a[1]<=l)
            ans+=a[i],cur+=k;
    }
    printf("%lld\n",ans);
    return 0;
}

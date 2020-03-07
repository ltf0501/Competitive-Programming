#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
#define ll long long
int n,k,m;
int a[maxn];
main()
{
    scanf("%d%d%d",&n,&k,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    sort(a+1,a+n+1,greater<int>());
    double ans=0.0;
    ll sum=0;
    for(int i=1;i<=n;i++)
    {
        sum+=a[i];
        if(m<(n-i))continue ;
        double tmp=(double)(sum+min(1ll*k*i,(ll)(m-(n-i))))/(double)i;
        ans=max(ans,tmp);
       // printf("%d: %.9f\n",i,tmp);
    }
    printf("%.9f\n",ans);
    return 0;
}

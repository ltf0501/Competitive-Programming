#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
main()
{
    scanf("%d%lld",&n,&m);
    ll k=n,cnt=0;
    while((n+k-1)*(n-k)<=2*m && k>=0)cnt++,k--;
    k++,cnt--;
    ll s=m-(n-1+k)*(n-k)/2;
    //printf("%lld %lld %lld\n",k,cnt,s);
    for(int i=1;i<=cnt;i++)printf("%d ",n-i+1);
    for(int i=1;i<=n-cnt-s-1;i++)printf("%d ",i);
    if(n>cnt)printf("%d ",n-cnt);
    for(int i=n-cnt-s;i<=n-cnt-1;i++)printf("%d ",i);
    puts("");
    return 0;
}

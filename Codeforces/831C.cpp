#include<bits/stdc++.h>
using namespace std;
#define maxn 2010
#define ll long long
ll a[maxn],b[maxn],sum[maxn];
int n,k;
set<ll> s,t,Sum;
main()
{
    scanf("%d%d",&k,&n);
    for(int i=1;i<=k;i++)scanf("%lld",&a[i]),sum[i]=sum[i-1]+a[i],Sum.insert(sum[i]);
    for(int i=1;i<=n;i++)scanf("%lld",&b[i]),t.insert(b[i]);
    for(ll S : Sum)s.insert(b[1]-S);
    //for(ll v : s)printf("%d ",v);puts("");
    //for(ll S : Sum)printf("%d ",S);puts("");
    int ans=s.size();
    for(ll v : s)
    {
        int cnt=0;
       // printf("%d\n",v);
        for(ll S : Sum)if(t.find(v+S)!=t.end())cnt++;
        if(cnt!=n)ans--;
    }
    printf("%d\n",ans);
    return 0;
}
/*
5 2
-1 0 0 1 2
3 5
*/

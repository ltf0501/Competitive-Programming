#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 100010
ll a[maxn];
ll n;int k;
main()
{
    scanf("%lld%d",&n,&k);
	for(int i=1;i<=k;i++)scanf("%lld",&a[i]);
	ll mx=-1,id=-1;
	for(int i=1;i<=k;i++)
    {
		ll cur=n-n%a[i];
		if(cur>mx)
		{
			mx=cur;
			id=i;
		}
	}
	//printf("%d %lld\n",id,(ll)n/a[id]);
	cout<<id<<' '<<n/a[id]<<'\n';
	return 0;
}

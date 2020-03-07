#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define maxn 100010
vector<ll> v;
ll a[maxn];
ll pre[maxn];
int main()
{
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	if(n!=1)
	{
		for(int i=1;i<n;i++)v.push_back(a[i+1]-a[i]);
		sort(v.begin(),v.end());
		pre[0]=v[0];
		for(int i=1;i<(int)v.size();i++)pre[i]=pre[i-1]+v[i];
	}
	//	for(ll x : v)printf("%lld ",x);puts("");
	int q;scanf("%d",&q);
	while(q--)
	{
		ll le,ri;scanf("%lld%lld",&le,&ri);
		ll num=ri-le+1;
		if(n==1){printf("%lld\n",num);continue ;}
		int k=lower_bound(v.begin(),v.end(),num)-v.begin();
		printf("%lld\n",1ll*num*n-(k*num-pre[k-1]));
	}
	return 0;
}

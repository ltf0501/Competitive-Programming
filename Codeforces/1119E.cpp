#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main()
{
	int n;scanf("%d",&n);
	ll tmp=0,ans=0;
	for(int i=0;i<n;i++)
	{
		ll x;scanf("%lld",&x);
		ll mi=min(x/2,tmp);
		x-=2*mi,tmp-=mi;
		ans+=mi+x/3;
		tmp+=(x%3);
	}
	printf("%lld\n",ans);
	return 0;
}

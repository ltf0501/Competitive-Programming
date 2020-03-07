#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
#define ll long long
int a[maxn];
int n;
main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	ll ans=0;
	for(int i=n-1;i>=1;i--)
	{
		if(a[i+1])a[i]=min(a[i],a[i+1]-1);
		else a[i]=0;
	}
		for(int i=1;i<=n;i++)ans+=a[i];
	printf("%lld\n",ans);

	return 0;
}

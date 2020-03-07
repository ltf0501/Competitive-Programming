#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
#define ll long long 
#define pii pair<int,int>
#define F first
#define S second
pii a[maxn];
int n;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&a[i].F,&a[i].S);
	ll ans=0;
	sort(a+1,a+n+1,[&](pii x,pii y){return x.F-x.S>y.F-y.S;});
	for(int i=1;i<=n;i++)ans+=(1ll*a[i].F*(i-1)+1ll*a[i].S*(n-i));
	printf("%lld\n",ans);
	return 0;
}

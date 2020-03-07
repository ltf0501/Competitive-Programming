#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=2e7+10;
ll a[maxn];
int main()
{
	int n;scanf("%d",&n);
	ll tot=0;
	for(int i=0;i<n;i++)scanf("%lld",&a[i]),tot+=a[i];
	ll sum=0;
	for(int i=0;i<n;i++)sum+=1ll*i*a[i];
	int ans=maxn;
	if(sum%tot==0)ans=sum/tot;
	for(int i=0;i<n/2;i++)
	{

	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
ll V;
void read()
{
	scanf("%lld",&V);
}
vector<int> facs;
void build()
{
	for(int i=1;i*i<=V;i++) if(V%i==0)
		facs.pb(i);
	int x=V;
	for(int f:facs) while(f!=1 && x%f==0)
		x/=f;
	if(x>1) facs.pb(x);
}
void sol()
{
	ll a=1,b=1,c=V;ll suf=2*(a*b+b*c+c*a);
	auto upd=[&](ll i,ll j,ll k)
	{
		ll cs=2*(i*j+j*k+k*i);
		if(tie(cs,i,j,k) < tie(suf,a,b,c))
			suf=cs,a=i,b=j,c=k;
	};
	for(int i:facs)
	{
		for(auto it=lower_bound(ALL(facs),i);it!=facs.end();it++)
		{
			ll j=*it;
			if(1LL*i*j*j>V || 0.9*i*j*j>V) break;
			if(V%(i*j)==0) upd(i,j,V/i/j);
		}
	}
	printf("%lld %lld %lld %lld\n",suf,a,b,c);
}
int main()
{
	read();
	build();
	sol();
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
#define ll long long 
const int mod=1e9+7;
vector<int> p;
int mu[maxn],pre[maxn];
int pp[maxn];
void prep()
{
	mu[1]=1;
	for(int i=2;i<maxn;i++)
	{
		if(!pp[i])p.push_back(i),pp[i]=i,mu[i]=-1;
		for(int j=0;j<(int)p.size() && 1ll*i*p[j]<maxn;j++)
		{
			pp[i*p[j]]=p[j];
			if(i%p[j]==0)break;
			else mu[i*p[j]]=-mu[i];
		}
	}
//for(int i=1;i<maxn;i++)pre[i]=pre[i-1]+mu[i];
//for(int i=1;i<=50;i++)printf("%d: %d\n",i,pp[i]);
}
ll pw(ll a,int n)
{
	ll res=1;
	while(n)
	{
		if(n&1)res=res*a%mod;
		a=a*a%mod,n>>=1;
	}
	return res;
}
ll INV(ll a){return pw(a,mod-2);}
main()
{
	prep();
	int n;scanf("%d",&n);
	ll ans=1;
	for(int i=2;i<=n;i++)
	{
		int k=n/i;
		ans=(ans-mu[i]*k*INV(n-k)%mod+mod)%mod;
	}
	if(ans<0)ans+=mod;
	printf("%d\n",ans);
	return 0;
}

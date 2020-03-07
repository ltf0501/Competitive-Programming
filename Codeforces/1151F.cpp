#include<bits/stdc++.h>
using namespace std;
#define maxn 105
#define ll long long
const int mod=1e9+7;
int n,k;
int t[maxn];
struct M
{
	ll a[maxn][maxn];
	M operator * (const M& rhs)const
	{
		M res;
		for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)
		{
			res.a[i][j]=0;
			for(int k=0;k<=n;k++)(res.a[i][j]+=a[i][k]*rhs.a[k][j]%mod)%=mod;
		}
		return res;
	}
};
M ppw(M a,int k)
{
	M res;
	for(int i=0;i<n;i++)res.a[i][i]=1;
	while(k)
	{
		if(k&1)res=res*a;
		a=a*a,k>>=1;
	}
	return res;
}
ll pw(ll a,int n)
{
	ll res=1;
	while(n)
	{
		if(n&1)res=res*a%mod;
		a=a*a%mod;n>>=1;
	}
	return res;
}
ll INV(ll a){return pw(a,mod-2);}
ll fac[maxn],inv[maxn];
int main()
{
	fac[0]=1;
	for(int i=1;i<maxn;i++)fac[i]=fac[i-1]*i%mod;
	inv[maxn-1]=INV(fac[maxn-1]);
	for(int i=maxn-2;i>=0;i--)inv[i]=inv[i+1]*(i+1)%mod;
	scanf("%d%d",&n,&k);
	int a=0;
	for(int i=1;i<=n;i++)scanf("%d",&t[i]),a+=t[i];
	int b=n-a;
	int x=0;
	for(int i=n;i>n-a;i--)x+=(t[i]==0);
	M tmp;
	int kk=min(a,b);
	tmp.a[0][0]=a*(a-1)/2+b*(b-1)/2;
	tmp.a[0][1]=a*b;
	for(int i=1;i<kk;i++)
	{
		tmp.a[i][i]=a*(a-1)/2+b*(b-1)/2+i*(a-i)+i*(b-i);
		tmp.a[i][i-1]=i*i;
		tmp.a[i][i+1]=(b-i)*(a-i);
	}
	tmp.a[kk][kk]=a*(a-1)/2+b*(b-1)/2+kk*(a-kk)+kk*(b-kk);
	tmp.a[kk][kk-1]=kk*kk;
	/*
	for(int i=0;i<=kk;i++)
	{
		for(int j=0;j<=kk;j++)printf("%lld ",tmp.a[i][j]);puts("");
	}
	*/
	M res=ppw(tmp,k);
	ll ans=res.a[0][x];
	ans=ans*pw(INV(n*(n-1)/2),k)%mod;
	ans=ans*fac[x]%mod*fac[x]%mod*fac[a-x]%mod*fac[b-x]%mod*inv[a]%mod*inv[b]%mod;
	//ans=ans*(1/C(a,x)C(b,x))
	printf("%lld\n",ans);
	return 0;
}

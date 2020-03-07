#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
#define ll long long 
const int mod=1e9+7;
int p[maxn],sz[maxn];
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
int finds(int x){return p[x]==x ? x : p[x]=finds(p[x]);}
void Union(int x,int y)
{
	x=finds(x),y=finds(y);
	if(x==y)return ;
	if(sz[x]<sz[y])swap(x,y);
	sz[x]+=sz[y],p[y]=x;
}
main()
{
	int n,k;scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)sz[i]=1,p[i]=i;
	for(int i=1;i<n;i++)
	{
		int x,y,c;scanf("%d%d%d",&x,&y,&c);
		if(!c)Union(x,y);
	}
	ll ans=pw(n,k);
	//printf("%lld\n",ans);
	for(int i=1;i<=n;i++)if(p[i]==i)
	{
		ans=(ans-pw(sz[i],k)+mod)%mod;
	}
	if(ans<0)ans+=mod;
	printf("%lld\n",ans);
	return 0;
}

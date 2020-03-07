#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define maxn 200010
const int mod=998244353;
int f[maxn];
int deg[maxn];

int main()
{
	int n;scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		deg[x]++,deg[y]++;
	}
	f[0]=1;
	for(int i=1;i<=n;i++)f[i]=1ll*f[i-1]*i%mod;
	int ans=n;
	for(int i=1;i<=n;i++)ans=1ll*ans*f[deg[i]]%mod;
	printf("%d\n",ans);
	return 0;
}

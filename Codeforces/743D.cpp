#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
#define ll long long 
const ll INF=1e16+10;
vector<int> g[maxn];
int in[maxn],out[maxn],dfs_clock,euler[maxn];
int n;
int a[maxn];
ll sum[maxn],sufmax[maxn];
void dfs(int u,int fa)
{
	in[u]=++dfs_clock;
	euler[dfs_clock]=u;
	sum[u]=a[u];
	for(int v : g[u])if(v!=fa)
	{
		dfs(v,u);
		sum[u]+=sum[v];
	}
	out[u]=dfs_clock;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<n;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		g[x].push_back(y),g[y].push_back(x);
	}
	dfs(1,-1);
	sufmax[n+1]=-INF;
	for(int i=n;i>=1;i--)sufmax[i]=max(sufmax[i+1],sum[euler[i]]);
	ll ans=-INF;
	for(int i=1;i<=n;i++)if(out[i]!=n)
	{
		ans=max(ans,sum[i]+sufmax[out[i]+1]);
	}
	if(ans!=-INF)printf("%lld\n",ans);
	else puts("Impossible");
	return 0;
}

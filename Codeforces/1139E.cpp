#include<bits/stdc++.h>
using namespace std;
#define maxn 5010
int p[maxn],c[maxn],k[maxn];
int n,m,d;
int ans[maxn];
bool flag[maxn],vis[maxn];
int match[maxn];
vector<int> g[maxn];
bool dfs(int u)
{
	vis[u]=1;
	for(int v : g[u])
	{
		if(match[v]==-1 || (!vis[match[v]] && dfs(match[v])))
		{
			match[v]=u;
			return 1;
		}
	}
	return 0;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&p[i]);
	for(int i=1;i<=n;i++)scanf("%d",&c[i]);
	scanf("%d",&d);
	for(int i=1;i<=d;i++)scanf("%d",&k[i]),flag[k[i]]=1;
	for(int i=1;i<=n;i++)if(!flag[i])g[p[i]].push_back(c[i]);
	int cur=0;
	memset(match,-1,sizeof(match));
	for(int i=d;i>=1;i--)
	{
		while(1)
		{
			memset(vis,0,sizeof(vis));
			if(dfs(cur))cur++;
			else break ;
		}
		ans[i]=cur;
		g[p[k[i]]].push_back(c[k[i]]);
	}
	for(int i=1;i<=d;i++)printf("%d\n",ans[i]);
	return 0;
}

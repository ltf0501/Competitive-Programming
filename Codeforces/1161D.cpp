#include<bits/stdc++.h>
using namespace std;
#define maxn 2010
#define ll long long
const int mod=998244353;
char c[maxn];
vector<int> g[maxn],g2[maxn],gg[maxn];
int com[maxn],cnt;
int vis[maxn];
void dfs1(int u)
{
	com[u]=cnt;
	for(int v : g[u])
		if(com[v]==-1)dfs1(v);
}
bool dfs2(int u,int c)
{
	vis[u]=c;
//	printf("u = %d\n",u);
	for(int v : gg[u])
	{
		if(vis[v]==vis[u])return 0;
		else if(!vis[v])
		{
			if(!dfs2(v,3-c))return 0;
		}
	}
	return 1;
}
int32_t main()
{
	scanf("%s",c);
	int n=strlen(c);
	int tot=0;
	for(int m=1;m<n;m++)
	{
		int node_0=n+m,node_1=n+m+1;
		for(int i=0;i<n+m+2;i++)g[i].clear(),g2[i].clear();
		g2[node_0].push_back(node_1),g2[node_1].push_back(node_0);
		g[n+m-1].push_back(node_1),g[node_1].push_back(n+m-1);
		for(int i=0;i<n/2;i++)if(i!=n-1-i)
		{
			g[i].push_back(n-1-i);
			g[n-1-i].push_back(i);
		}
		for(int i=0;i<m/2;i++)if(i!=m-1-i)
		{
			g[i+n].push_back(m-1-i+n);
			g[m-1-i+n].push_back(i+n);
		}
		for(int i=0;i<m;i++)
		{
			if(c[n-1-i]=='0')
			{
				g[i].push_back(i+n);
				g[i+n].push_back(i);
			}
			else if(c[n-1-i]=='1')
			{
				g2[i].push_back(i+n);
				g2[i+n].push_back(i);
			}
		}
		for(int i=m;i<n;i++)
		{
			if(c[n-1-i]=='0')
			{
				g[i].push_back(node_0);
				g[node_0].push_back(i);
			}
			else if(c[n-1-i]=='1')
			{
				g[i].push_back(node_1);
				g[node_1].push_back(i);
			}
		}
		memset(com,-1,sizeof(com));
		cnt=0;
		for(int i=0;i<n+m+2;i++)
			if(com[i]==-1)dfs1(i),cnt++;
	//	for(int i=0;i<n+m+2;i++)printf("%d ",com[i]);puts("");
		memset(vis,0,sizeof(vis));
		bool flag=1;
		for(int i=0;i<n+m+2;i++)
		{
			for(int j : g2[i])
				if(com[i]==com[j]){flag=0;break;}
		}
		if(!flag)continue;
		for(int i=0;i<cnt;i++)gg[i].clear();
		for(int i=0;i<n+m+2;i++)
		{
			for(int j : g2[i])
			{
				gg[com[i]].push_back(com[j]);
			}
		}
		int ans=1;
		bool umr=0;
	//	printf("cnt = %d\n",cnt);
		for(int i=0;i<cnt;i++)if(!vis[i])
		{
			if(!dfs2(i,1)){flag=0;break;}
			//printf("i = %d\n",i);
			if(umr)ans=ans*2%mod;
			umr=1;
		}
		if(!flag)continue; 
		tot=(tot+ans)%mod;
	}
	printf("%d\n",tot);
	return 0;
}

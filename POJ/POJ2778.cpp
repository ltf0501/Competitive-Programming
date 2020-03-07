#include<cstdio>
#include<algorithm>
using namespace std;
#define maxnode 105
#define sigma_size 4
#define ll long long 
const int mod=1e5;
int sz;
struct Matrix 
{
	ll a[maxnode][maxnode];
	Matrix operator * (const Matrix& rhs)const
	{
		Matrix res;
		for(int i=0;i<=sz;i++)for(int j=0;j<=sz;j++)
		{
			res.a[i][j]=0;
			for(int k=0;k<=sz;k++)(res.a[i][j]+=a[i][k]*rhs.a[k][j]%mod)%=mod;
		}
		return res;
	}
};
struct AC
{
	Matrix ma;
	int node[maxnode][sigma_size];
	int fail[maxnode],match[maxnode];
	inline void init(){sz=0;}
	inline int idx(char c)
	{
		if(c=='A')return 0;
		if(c=='T')return 1;
		if(c=='C')return 2;
		return 3;
	}
	void insert(char *S)
	{
		int n=strlen(S),cur=0;
		for(int i=0;i<n;i++)
		{
			int c=idx(S[i]);
			if(!node[cur][c])node[cur][c]=++sz;
			cur=node[cur][c];
		}
		match[cur]=1;
	}
	void getfail()
	{
		queue<int> q;
		for(int i=0;i<sigma_size;i++)if(node[0][i])q.push(node[0][i]);
		while(!q.empty())
		{
			int now=q.front();q.pop();
			for(int i=0;i<sigma_size;i++)
			{
				if(!node[now][i]){node[now][i]=node[fail[now]][i];continue ;}
				int j=fail[now],nx=node[now];
				while(j && !node[j][i])j=fail[j];
				fail[nx]=node[j][i];
				match[nx]|=match[fail[nx]];
				q.push(nx);
			}
		}
	}
	bool vis[maxnode];
	void dfs(int u)
	{
		vis[u]=1;
		for(int i=0;i<sigma_size;i++)
		{
			int v=node[u][i];
			if(match[v])continue ;
			ma.a[u][v]++;
			if(!vis[v])dfs(v);
		}
	}	
	void solve(int n)
	{
		dfs(0);
		Matrix ans;
		for(int i=0;i<=sz;i++)ans.a[i][i]=1;
		for(;n;n>>=1,ma=ma*ma)
			if(n&1)ans=ans*ma;
		ll tot=0;
		for(int i=0;i<=sz;i++)if(!match[i])(tot+=ans.a[0][i])%=mod;
		printf("%lld\n",tot);
	}
}solver;
char c[15];
int main()
{
	int m,n;scanf("%d%d",&m,&n);
	for(int i=0;i<m;i++)
	{
		scanf("%s",s);
		solver.insert(s);
	}
	solver.getfail();
	solver.solve();
	return 0;
}

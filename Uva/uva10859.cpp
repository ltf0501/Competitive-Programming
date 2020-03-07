#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>

#define INF 0x3f3f3f3f
#define NODENUM 1005
#define EDGENUM 1005
#define MAXN 1005
using namespace std;

int root;
const int m=2000;

struct EdgeNode{int to,next;} E[2*EDGENUM];
int edgenum,head[NODENUM],N,T,M;
bool vis[NODENUM];
int ans,dp[NODENUM][2];

void init()
{
	edgenum=0;
	memset(head,-1,sizeof(head));
	memset(vis,0,sizeof(vis));
	ans=0;
}

void add(int x,int y)
{
	edgenum++;
	E[edgenum].next=head[x];
	head[x]=edgenum;
	E[edgenum].to=y;
}

void dfs(int s)
{
	vis[s]=1;
	int sum0=0,sum1=0;

	for(int p=head[s];p!=-1;p=E[p].next)
	{
		int v=E[p].to;
		if(!vis[v])
		{
			dfs(v);
			sum0+=dp[v][0];
			sum1+=dp[v][1];
		}
	}

	if(s==root) dp[s][0]=min(sum1+m,sum0),ans+=dp[s][0];
	else dp[s][1]=min(sum0+1,sum1+m),dp[s][0]=sum1+m+1;

}

void build()
{
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;++i)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		add(a,b);
		add(b,a);
	}
}

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		init();
		build();
		for(int i=0;i<N;++i) if(!vis[i]) dfs(root=i);
		printf("%d %d %d\n",ans/m,M-ans%m,ans%m);
	}
	return 0;
}

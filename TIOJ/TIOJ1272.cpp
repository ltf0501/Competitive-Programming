#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> g[100010];
int now=0;
int in[100010],out[100010];
void dfs(int i)
{
	in[i]=++now;
	for(int j:g[i])
		dfs(j);
	out[i]=now;
}
bool bit[100010];
void add(int i)
{
	while(i<=n)
	{
		bit[i]^=1;
		i+=i&-i;
	}
}
bool sum(int i)
{
	bool s=0;
	while(i>0)
	{
		s^=bit[i];
		i-=i&-i;
	}
	return s;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int cnt;
		cin>>cnt;
		while(cnt--)
		{
			int v;
			cin>>v;
			g[i].push_back(v);
		}
	}
	dfs(1);
	while(m--)
	{
		int a,b;
		cin>>a>>b;
		if(a==0)
		{
			add(in[b]);
			add(out[b]+1);
		}
		else
		{
			cout<<sum(in[b])<<'\n';
		}
	}
}

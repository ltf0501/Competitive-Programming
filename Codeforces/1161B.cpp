#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
vector<int> v[maxn];
int n,m;
int f[maxn];
int lcs(int a,int b)
{
	return a/__gcd(a,b)*b;
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		x--,y--;
		if(x>y)swap(x,y);
		if(y-x<x-y+n)v[y-x].push_back(x);
		else if(y-x>x-y+n)v[x-y+n].push_back(y);
		else v[y-x].push_back(x),v[y-x].push_back(y);
	}
	for(int i=1;i<=n;i++)sort(v[i].begin(),v[i].end());
	int cur=1;
	for(int i=1;i<=n;i++)
	{
		if(v[i].empty())continue ; 
		vector<int> tmp;
		int N=(int)v[i].size();
		//printf("N = %d\n",N);
		//for(int j : v[i])printf("%d ",j);puts("");
		for(int j=1;j<N;j++)tmp.push_back(v[i][j]-v[i][j-1]);
		tmp.push_back(v[i][0]-v[i][N-1]+n);
		f[0]=f[1]=0;
		for(int j=1;j<N;j++)
		{
			int k=f[j];
			while(k && tmp[j]!=tmp[k])k=f[k];
			f[j+1]=(tmp[j]==tmp[k]) ? k+1 : 0;
		}
		if(N%(N-f[N])!=0 || f[N]==0)return 0*puts("No");
		int len=N-f[N];
		int sum=0;
		for(int j=0;j<len;j++)sum+=tmp[j];
		cur=lcs(cur,sum);
	}
	if(cur==n)puts("No");
	else puts("Yes");
	return 0;
}

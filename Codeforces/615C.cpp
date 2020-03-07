#include<bits/stdc++.h>
using namespace std;
#define maxn 2110
int lcp[maxn][maxn],lcp2[maxn][maxn];
char s[maxn],t[maxn];
#define pii pair<int,int>
#define F first
#define S second
int main()
{
	scanf("%s%s",s,t);
	int n=strlen(s),m=strlen(t);
	for(int i=m-1;i>=0;i--)
	{
		for(int j=n-1;j>=0;j--)
			if(t[i]==s[j])lcp[i][j]=lcp[i+1][j+1]+1;
		for(int j=0;j<n;j++)
			if(t[i]==s[j])lcp2[i][j]=(j==0 ? 0 : lcp2[i+1][j-1])+1;
	}
	vector<pii> ans;
	for(int i=0;i<m;)
	{
		int i1=max_element(lcp[i],lcp[i]+n)-lcp[i];
		int i2=max_element(lcp2[i],lcp2[i]+n)-lcp2[i];
		int len=max(lcp[i][i1],lcp2[i][i2]);
		if(len==0)return 0*puts("-1");
		if(len==lcp[i][i1])
		{	
			ans.push_back(pii(i1,i1+len-1));
		}
		else 
		{
			ans.push_back(pii(i2,i2-len+1));
		}
		i+=len;
	}
	printf("%d\n",(int)ans.size());
	for(pii t : ans)printf("%d %d\n",t.F+1,t.S+1);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define maxn 500010
char c[maxn],s[maxn];
int cnt[2];
int suf[2][maxn];
int f[maxn];
void quit()
{
	for(int i=0;i<cnt[0];i++)putchar('0');
	for(int i=0;i<cnt[1];i++)putchar('1');
	puts("");
	exit(0);
}
int main()
{
	scanf("%s%s",c,s);
	int n=strlen(c);
	for(int i=0;i<n;i++)cnt[c[i]-'0']++;
	n=strlen(s);
	for(int i=n-1;i>=0;i--)
	{
		suf[0][i]=suf[0][i+1];
		suf[1][i]=suf[1][i+1];
		suf[s[i]-'0'][i]++;
	}
	f[0]=-1;
	for(int i=1;i<n;i++)
	{
		int j=f[i-1];
		while(j>=0 && s[j+1]!=s[i])j=f[j];
		if(s[j+1]==s[i])f[i]=j+1;
		else f[i]=j;
	}
	if(cnt[0]>=suf[0][0] && cnt[1]>=suf[1][0])
	{
		printf("%s",s);
		cnt[0]-=suf[0][0];
		cnt[1]-=suf[1][0];
	}
	else quit();
	int k=f[n-1];
	while(cnt[0] || cnt[1])
	{
		if(cnt[0]>=suf[0][k+1] && cnt[1]>=suf[1][k+1])
		{
			for(int i=k+1;i<n;i++)putchar(s[i]);
			cnt[0]-=suf[0][k+1],cnt[1]-=suf[1][k+1];
		}
		else quit();
	}
	puts("");
	return 0;
}

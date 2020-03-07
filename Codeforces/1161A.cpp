#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
int l[maxn],r[maxn];
int main()
{
	int n,k;scanf("%d%d",&n,&k);
	memset(l,-1,sizeof(l));
	memset(r,-1,sizeof(r));
	for(int i=1;i<=k;i++)
	{
		int x;scanf("%d",&x);
		if(l[x]==-1)l[x]=i;
		r[x]=i;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		if(l[i]==-1)ans++;
	for(int i=1;i<n;i++)
		if(l[i]==-1 || r[i+1]==-1 || r[i+1]<l[i])ans++;
	for(int i=2;i<=n;i++)
		if(l[i]==-1 || r[i-1]==-1 || r[i-1]<l[i])ans++;
	printf("%d\n",ans);
	return 0;
}

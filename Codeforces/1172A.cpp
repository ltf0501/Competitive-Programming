#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
int a[maxn],b[maxn];
int pos[maxn];
int main()
{
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]),pos[b[i]]=i;
	if(pos[1]>0)
	{
		int id=2;
		while(pos[id]-id==pos[1]-1)id++;
		if(pos[id-1]==n)
		{
			int j=id;
			while(j<=n && pos[j]<=j-id)j++;
			if(j>n)return 0*printf("%d\n",n-id+1);
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)ans=max(ans,pos[i]-i+1+n);
	printf("%d\n",ans);
	return 0;
}

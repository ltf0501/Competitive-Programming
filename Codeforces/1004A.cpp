#include<bits/stdc++.h>
using namespace std;
int n,d;
int a[10000];
int main()
{
	scanf("%d %d",&n,&d);
	int ans=2;
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	for(int i=0;i<n-1;i++)
    {
		if(a[i+1]-a[i]==2*d)ans++;
		if(a[i+1]-a[i]>2*d)ans+=2;
	}
	printf("%d",ans);
	return 0;
}

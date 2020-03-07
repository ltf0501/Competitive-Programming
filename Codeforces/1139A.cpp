#include<bits/stdc++.h>
using namespace std;
#define maxn 65100
char s[maxn];
main()
{
	int n;scanf("%d",&n);
	scanf("%s",s);
	int ans=0;
	for(int i=0;i<n;i++)
		if((s[i]-'0')%2==0)ans+=(i+1);
	printf("%d\n",ans);
	return 0;
}

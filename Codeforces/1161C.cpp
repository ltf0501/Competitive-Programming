#include<bits/stdc++.h>
using namespace std;
#define maxn 55
int a[maxn];
int main()
{
	int n;scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	sort(a,a+n);
	int m=n/2;
	if(a[0]==a[m])puts("Bob");
	else puts("Alice");
	return 0;
}

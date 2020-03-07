#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define L 15010
#define maxn 20010
#define MOD 10000
int A[maxn],B[maxn];
struct Big
{
	int n[L],l;
	void times(int a)
	{
	    int i;
		for(i=0;i<l;i++)
			n[i]*=a;
		for(i=0;i<l;i++)
			n[i+1]+=n[i]/MOD,n[i]%=MOD;
		if(n[i] && l<=i)l=i+1;
	}
	void print()
	{
		printf("%d",n[l-1]);
		for(int i=l-2;i>=0;i--)printf("%04d",n[i]);
		puts("");
	}
}s;
main()
{
	int n;scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&A[i]);
	for(int i=0;i<n;i++)
		scanf("%d",&B[i]);
	sort(A,A+n);
	sort(B,B+n);
	s.n[0]=1,s.l=1;
	for(int i=0;i<n;i++)
	{
		int a=A[i]+B[n-i-1];
		s.times(a);
	}
	s.print();
	return 0;
}

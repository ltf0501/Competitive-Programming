#include<bits/stdc++.h>
using namespace std;
#define maxn 700010
int bit[maxn];
int n;
int query(int k)
{
	int x=0,now=0;
	for(int i=20;i>=0;i--)
        if(x+(1<<i)<=n && now+bit[x+(1<<i)]<k)x+=(1<<i),now+=bit[x];
    x++;
	for(int i=x;i<=n;i+=i&-i)bit[i]--;
	return x;
}
int main()
{
	scanf("%d",&n);
	int sum=n;
	for(int i=1;i<=n;i++)
    {
        bit[i]++;
        if(i+(i&-i)<=n)bit[i+(i&-i)]+=bit[i];
    }
	for(int i=n;i>=1;i--)
	{
	    int x;scanf("%d",&x);
		int k=x%i+1;
		if(i-sum>=k)sum=sum+k-1;
		else sum=k+sum-i-1;
		printf("%d\n",query(sum+1));
	}
}

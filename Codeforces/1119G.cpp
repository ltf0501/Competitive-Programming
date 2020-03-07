#include<bits/stdc++.h>
using namespace std;
#define maxn 1000010
#define ll long long 
#define SZ(v) (int)v.size()
int n,m;
int a[maxn];
vector<int> v,tmp,ans;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)scanf("%d",&a[i]);
	v.push_back(0),v.push_back(n);
	ll sum=0;
	for(int i=1;i<m;i++)sum+=a[i],v.push_back(sum%n);
	sort(v.begin(),v.end());
	for(int i=0;i<m;i++)tmp.push_back(v[i+1]-v[i]);
	for(int i=1,cur=0;i<=m;i++)
	{
		while(a[i]>0)
		{
			ans.push_back(i),a[i]-=tmp[cur%m];
			cur++;
		}
	}
	while(SZ(ans)%m!=0)ans.push_back(1);
	printf("%d\n",SZ(ans)/m);
	for(int i : tmp)printf("%d ",i);puts("");
	for(int i=0;i<SZ(ans);i++)printf("%d%c",ans[i]," \n"[(i+1)%m==0]);
	return 0;
}

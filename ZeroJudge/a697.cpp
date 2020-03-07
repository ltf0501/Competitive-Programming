#include<bits/stdc++.h>
using namespace std;
int a[101];
int n,m;
int f[101][101];
int dfs(int i,int m)
{
	if(f[i][m]>0)return f[i][m];
	if(m==0)return 1;
	if(i==0 && m!=0)return 0;
	for(int k=0;k<=a[i];k++)
		if(m>=k)
			f[i][m]=(f[i][m]+dfs(i-1,m-k))%1000007;
	return f[i][m];
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=n;i>=1;i--)scanf("%d",&a[i]);
        printf("%d\n",dfs(n,m));
    }
    return 0;
}

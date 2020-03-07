#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
#define inf 0x3f3f3f3f
int w, n;
int a[55], dp[55][2000];
int path[55];
vector< vector<int> > ret;
void dfs(int n,int w,int dep)
{
    if(n==0)
    {
		vector<int> buf;
		for(int i=dep-1;i>=0;i--)
			buf.push_back(path[i]);
		ret.push_back(buf);
		return;
	}
	if(dp[n][w]==dp[n-1][w])dfs(n-1,w,dep);
	if(w-a[n]>=0 && dp[n][w]==dp[n-1][w-a[n]]+1)
    {
		path[dep]=a[n];
		dfs(n-1,w-a[n],dep+1);
	}

}
main()
{
    while(scanf("%d%d",&w,&n)==2)
    {
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        memset(dp,inf,sizeof(dp));
        dp[0][0]=0;

        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=w;j++)
            {
                dp[i][j]=dp[i-1][j];
                if(j-a[i]>=0)
                {
                    dp[i][j]=min(dp[i][j],dp[i-1][j-a[i]]+1);
                }
            }
        }
        ret.clear();
        dfs(n,w,0);
        sort(ret.begin(), ret.end());
        printf("%d %d\n",dp[n][w],ret.size());
        for(int i=0;i<ret.size();i++)
        {
            vector<int> &v=ret[i];
            for(int j=0;j<v.size();j++)printf("%d ",v[j]);
            printf("\n");
        }
    }
    return 0;
}

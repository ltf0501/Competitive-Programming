#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 1000+10
#define inf 0x3f3f3f3f
int n;
struct Light
{
    int v,k,c,l;
    bool operator < (const Light& rhs)const
    {
        return v<rhs.v;
    }
};
Light a[maxn];
int dp[maxn];
main()
{
    while(scanf("%d",&n)==1 && n)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d%d%d%d",&a[i].v,&a[i].k,&a[i].c,&a[i].l);
        }
        sort(a,a+n);
        for(int i=0;i<n;i++)
        {
            dp[i]=inf;
            int sum=0;
            for(int j=i;j>=0;j--)
            {
                sum+=a[j].l;
                if(j)dp[i]=min(dp[i],dp[j-1]+sum*a[i].c+a[i].k);
                else dp[i]=min(dp[i],a[i].k+sum*a[i].c);
            }
        }
        printf("%d\n",dp[n-1]);
    }
    return 0;
}

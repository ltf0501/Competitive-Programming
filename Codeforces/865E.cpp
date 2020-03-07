#include<bits/stdc++.h>
using namespace std;
int dp[2005][105];
int n;
struct P
{
    int t,d,p,id;
    void input(int i)
    {
        scanf("%d%d%d",&t,&d,&p);
        id=i;
    }
    bool operator < (const P& b)const
    {
        return d<b.d;
    }
}a[105];
vector<int> v;
main()
{
    scanf("%d",&n);
    int m=0;
    for(int i=1;i<=n;i++)a[i].input(i),m=max(m,a[i].d);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            dp[j][i]=max(dp[j][i],dp[j][i-1]);
            if(j>=a[i].t && j<a[i].d)dp[j][i]=max(dp[j][i],dp[j-a[i].t][i-1]+a[i].p);
        }
    }
    /*
    for(int j=1;j<=m;j++)
    {
        for(int i=1;i<=n;i++)printf("%d ",dp[j][i]);puts("");
    }
    */
    int mx=0,T=0;
    for(int i=m;i>=1;i--)if(dp[i][n]>mx)mx=dp[i][n],T=i;
    printf("%d\n",mx);
    for(int i=n;i>=1;i--)
    {
        if(dp[T][i]==dp[T][i-1])continue;
        v.push_back(a[i].id);
        T-=a[i].t;
    }
    printf("%d\n",v.size());
    if(!v.size())return 0;
    for(int s : v)printf("%d ",s);
    return 0;
}

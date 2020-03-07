#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
using namespace std;
#define maxn 10000+5
struct stu
{
    int s,e,c;
    bool operator < (const stu& rhs)const
    {
        return e<rhs.e;
    }
};
int vis[maxn];
int dp[2][maxn];
main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int n;scanf("%d",&n);
        memset(vis,0,sizeof(vis));
        memset(dp,0,sizeof(dp));
        stu a[maxn];
        for(int i=1;i<=n;i++)scanf("%d%d%d",&a[i].s,&a[i].e,&a[i].c);
        sort(a+1,a+n+1);
        /*
        int l=1,r=1;
        while(r<=n)//判斷哪些區域不用考慮 vis[i]=1表示不用考慮
        {
            if(r==l){r++;continue;}
            if(a[l].s>=a[r].s)
            {
                if(a[l].c>=a[r].c)
                {
                    vis[l]=1;
                }
                r++;
            }
            else l++;
        }
        */
        /*
        for(int i=1;i<=n;i++)printf("%d ",vis[i]);
        puts("");
        */
        dp[0][1]=0;dp[1][1]=a[1].c;
        for(int i=2;i<=n;i++)
        {
            dp[0][i]=max(dp[1][i-1],dp[0][i-1]);
            int j=i;
            while(a[j].e>a[i].s)j--;
            dp[1][i]=max(dp[1][j],dp[0][j])+a[i].c;

        }
        printf("%d\n",max(dp[0][n],dp[1][n]));

    }
    return 0;
}

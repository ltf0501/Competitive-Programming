#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxsum 50000+4
int a[105];
int n;
bool test(int m)
{
    int dp[maxsum]={0};
    dp[0]=1;
    for(int i=0;i<n;i++)
    {
        for(int j=m;j>=a[i];j--)
        {
            dp[j]+=dp[j-a[i]];
            if(dp[m])return 1;
        }
    }
    return 0;
}
main()
{
    int t;
    scanf("%d%d",&t,&n);
    while(t--)
    {
        int sum=0;
        for(int i=0;i<n;i++)scanf("%d",&a[i]),sum+=a[i];
        if(sum&1){puts("No");continue;}
        int m=sum/2;
        if(test(m))puts("Yes");
        else puts("No");
    }
    return 0;
}

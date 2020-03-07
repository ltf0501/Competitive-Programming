#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 11
long long dp[2][1<<maxn];
int n,m,cur;
void update(int a,int b)
{
    if(b&(1<<m))dp[cur][b^(1<<m)]+=dp[cur^1][a];
}

main()
{

    while(scanf("%d%d",&n,&m)==2)
    {
        if(n<m)swap(n,m);
        memset(dp,0,sizeof(dp));
        cur=0;
        dp[0][(1<<m)-1]=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cur^=1;
                //fill(dp[cur],dp[cur]+(1<<m+1),0);
                memset(dp[cur],0,sizeof(dp[cur]));
                for(int k=0;k<(1<<m);k++)
                {
                    update(k,k<<1);
                    if(i && !(k&(1<<(m-1))))update(k,(k<<1)^(1<<m)^1);//位元運算最後
                    if(j && !(k&1))update(k,(k<<1)^3);
                }
            }
        }
        printf("%lld\n",dp[cur][(1<<m)-1]);
    }
    return 0;
}

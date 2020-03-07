#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define INF 100000000
int A[55];
int dp[55][55]={};
main()
{
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&A[i]);
    n--;
    for(int a=1;a<n;a++)
        for(int b=1,c=a+b;c<=n;b++,c++)
        {
            int mi=INF,t;
            for(int d=b;d<c;d++)
            {
                t=dp[b][d]+dp[d+1][c]+A[b]*A[d+1]*A[c+1];
                mi=min(mi,t);
            }
            dp[b][c]=mi;
            //printf("%d %d\n",b,c);
        }
    printf("%d\n",dp[1][n]);

    return 0;
}


#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define maxn 505

int trans(int x)
{
    if(x==0)return 1;
    if(x==1)return 0;
    if(x==2)return 3;
    if(x==3)return 2;
    if(x==4)return 5;
    if(x==5)return 4;
    return -1;
}

int A[maxn][6];
int dp[maxn][6];
int argdp[505][6][2];

void print(int x,int y)
{
    if(dp[x][y])print(argdp[x][y][0], argdp[x][y][1]);

    printf("%d ", x+1);
    if(y == 0)  puts("front");
    else if(y == 1) puts("back");
    else if(y == 2) puts("left");
    else if(y == 3) puts("right");
    else if(y == 4) puts("top");
    else puts("bottom");
}
main()
{
    int n,cases=0;
    while(scanf("%d",&n)==1 && n)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<6;j++)scanf("%d",&A[i][j]);
        }
        memset(dp,0,sizeof(dp));

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                for(int p=0;p<6;p++)
                {
                    for(int q=0;q<6;q++)
                    {
                        if(A[i][p]==A[j][q])
                        {
                            int x=trans(p);
                            if(dp[j][x]+1>dp[j][q])
                            {
                                dp[j][q] = dp[i][x]+1;
                                argdp[j][q][0] = i;
                                argdp[j][q][1] = x;
                            }
                        }
                    }
                }
            }
        }

        int ret=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<6;j++)ret=max(ret,dp[i][j]);
        }
        if(cases) puts("");
        printf("Case #%d\n",++cases);
        int x,y;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < 6; j++)
                if(dp[i][j] == ret)
                    x = i, y = j;
        print(x,y);
    }
    return 0;
}

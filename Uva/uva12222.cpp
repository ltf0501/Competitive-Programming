
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int maxn = 200+10;
const int INF = 0x3f3f3f3f;

struct Car
{
    int t,c;
    Car(int t = 0,int c = 0):t(t),c(c) {}
}A[maxn],B[maxn];

int dp[maxn][maxn][2];//1±qA 0±qB
int na,nb;

main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        na=0;nb=0;
        int x,y;
        char buf[10];
        for(int i=0;i<n;i++)
        {
            scanf("%s",buf);
            scanf("%d %d",&x,&y);
            if(buf[0] == 'A') A[++na]=Car(x,y);
            else B[++nb]=Car(x,y);
        }
        memset(dp,INF,sizeof(dp));
        dp[0][0][0] = dp[0][0][1] = 0;
         for(int i = 0;i <= na;++i)
            for(int j = 0;j <= nb;++j)
            {
                int s = dp[i][j][0],e = 0;
                for(int k = i+1;k <= na;++k)
                {
                    s = max(s,A[k].t);
                    e = max(s + A[k].c,e);
                    dp[k][j][1] = min(dp[k][j][1],e);
                    s += 10,e += 10;
                }

                s = dp[i][j][1],e = 0;
                for(int k = j+1;k <= nb;++k)
                {
                    s = max(s,B[k].t);
                    e = max(s+B[k].c,e);
                    dp[i][k][0] = min(dp[i][k][0],e);
                    s += 10,e += 10;
                }
            }
        printf("%d\n",min(dp[na][nb][0],dp[na][nb][1]));
    }
    return 0;
}

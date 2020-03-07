#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 20+2

int A[maxn][maxn],s[maxn][maxn],res[maxn],Max[maxn];
main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        memset(s,0,sizeof(s));
        int ans=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)scanf("%d",&A[i][j]);

        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+A[i][j];

        for(int x1=1;x1<=n;x1++)
        {
            for(int x2=x1;x2<=n;x2++)
            {
                for(int y=1;y<=n;y++)
                {
                    res[y]=s[x2][y]-s[x1-1][y]-s[x2][y-1]+s[x1-1][y-1];
                }
                int last=0,Ans=0;
                for(int i=1;i<=n;i++)
                {
                   last=max(0,last)+res[i];
                   Ans=max(Ans,last);
                }
                ans=max(ans,Ans);
            }
        }

       printf("%d\n",ans);
    }
    return 0;
}
/*
4
0 -2 -8 1
11 2 -6 0
-1 -3 -9 12
1 9 0 -3
*/

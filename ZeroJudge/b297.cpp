#include<bits/stdc++.h>
using namespace std;
int n;
main()
{
    while(~scanf("%d\n",&n))
    {
        char c;
        int dp1=0,dp0=0;
        for(int i=1;i<=n;i++)
        {
            c=getchar();
            int tmp1=dp1,tmp0=dp0;
            if(c=='1')
            {

                dp1=min(tmp1,tmp0+1);
                dp0=min(tmp1,tmp0)+1;
            }
            else
            {
                dp1=min(tmp1,tmp0)+1;
                dp0=min(tmp1+1,tmp0);
            }
        }
        getchar();
        //for(int i=1;i<=n;i++)printf("%d ",dp[0][i]);puts("");
        //for(int i=1;i<=n;i++)printf("%d ",dp[1][i]);puts("");
        printf("%d\n",dp1);

    }
    return 0;
}

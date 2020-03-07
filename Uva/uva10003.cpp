#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int L;

    while( scanf("%d", &L) )
    {
        if( L == 0 )
            break;

        int N;
        scanf("%d", &N);

        int num[100];
        num[0] = 0; num[N+1] = L;

        for(int i = 1; i <= N; i++)
        {
            scanf("%d", &num[i]);
        }
        N++;

        int dp[100][100];
        for(int i = 0; i < N; i++)
        {
            dp[i][i+1] = 0;
           // cout<<dp[i][i+1]<<endl;
        }
        for(int i = 0; i + 1 < N; i++)
        {
            dp[i][i+2] = num[i+2] - num[i];
        }

        for(int d = 2; d <= N; d++)
            for(int i = 0; i + d <= N; i++)
            {
                int mn = -1;
                for(int j = i+1; j < i+d; j++)
                {
                    if( mn == -1 )
                        mn = dp[i][j] + dp[j][i+d];

                    mn = min(mn, dp[i][j] + dp[j][i+d]);

                }

                dp[i][i+d] = mn + num[i+d] - num[i];
              // cout<<i<<" "<<i+d<<" "<<dp[i][i+d]<<endl;
            }

        printf("The minimum cutting is %d.\n", dp[0][N]);

    }
}

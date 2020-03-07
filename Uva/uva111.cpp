#include <cstdio>
#include <algorithm>
using namespace std;

int N,pos,Ans[30],num[30],LCS[30][30]={0};

int main()
{
    scanf("%d",&N);
    for(int i=1;i<=N;i++)
    {
        scanf("%d",&pos);
        Ans[pos]=i;
    }

    while(scanf("%d",&pos)!=EOF)
    {
        num[pos]=1;
        for(int i=2;i<=N;i++)
        {
            scanf("%d",&pos);
            num[pos]=i;
        }

        int Max=0;
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=N;j++)
            {
                if(Ans[i]==num[j])
                    LCS[i][j]=LCS[i-1][j-1]+1;
                else
                    LCS[i][j]=max(LCS[i-1][j],LCS[i][j-1]);

                if (LCS[i][j]>Max)Max=LCS[i][j];
            }
        }
        printf("%d\n",Max);
    }
    return 0;
}

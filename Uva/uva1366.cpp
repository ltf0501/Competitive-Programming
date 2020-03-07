#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int m,n;
int A[510][510],B[510][510];
int sum_row[510][510],sum_col[510][510];
int f[510][510][2];//0¦¬A 1¦¬B
main()
{
    while(scanf("%d%d",&n,&m)==2 && n+m)
    {
        memset(sum_row,0,sizeof(sum_row));memset(sum_col,0,sizeof(sum_col));memset(f,0,sizeof(f));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                scanf("%d",&A[i][j]);
                sum_row[i][j]=sum_row[i][j-1]+A[i][j];
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                scanf("%d",&B[i][j]);
                sum_col[i][j]=sum_col[i-1][j]+B[i][j];
            }
        }

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                f[i][j][0]=max(f[i-1][j][0],f[i-1][j][1])+sum_row[i][j];
                f[i][j][1]=max(f[i][j-1][0],f[i][j-1][1])+sum_col[i][j];
            }
        }

        printf("%d\n",max(f[n][m][0],f[n][m][1]));
    }
    return 0;
}


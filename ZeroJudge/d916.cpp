#include<cstdio>
using namespace std;
#define MOD 10000
int C[3005][3005];
void init()
{
    C[0][0]=1;
    for(int i=1;i<=3004;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(j==0 || i==j)C[i][j]=1;
            else C[i][j]=(C[i-1][j]+C[i-1][j-1])%MOD;
        }
    }
}
main()
{
    init();
    int n,m;
    while(scanf("%d%d",&n,&m)==2)
    {
        int a=(n+m)/(m+1);
        int ans=0;
        for(int i=0;i<=a;i++)ans=(ans+C[n-(i-1)*m][i])%MOD;
        printf("%d\n",ans);
    }
    return 0;
}

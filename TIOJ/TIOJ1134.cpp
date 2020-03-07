#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 205
int a[maxn][maxn],sum[maxn][maxn];
main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int n,m;scanf("%d%d",&n,&m);
        for(int i=0;i<=200;i++)a[i][0]=a[0][i]=0,sum[i][0]=sum[0][i]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                int k;scanf("%d",&k);
                a[i][j]=(k==0) ? 1 : -1;
            }
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)sum[i][j]=sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1]+a[i][j];

        int ans=0;
        for(int cx1=1;cx1<=n;cx1++)
            for(int cx2=cx1;cx2<=n;cx2++)
                for(int cy1=1;cy1<=m;cy1++)
                    for(int cy2=cy1;cy2<=m;cy2++)
                        if((0<sum[cx2][cy2]-sum[cx2][cy1-1]-sum[cx1-1][cy2]+sum[cx1-1][cy1-1]) && (ans<=(cx2-cx1+1)*(cy2-cy1+1)))
                            ans=(cx2-cx1+1)*(cy2-cy1+1);
        printf("%d\n",ans);
    }
    return 0;
}

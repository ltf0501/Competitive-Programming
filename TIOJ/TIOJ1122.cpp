#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int a[25][25],sum[25][25];
main()
{
    int n,k;
    while(~scanf("%d%d",&n,&k))
    {
        a[1][1]=k;
        for(int i=0;i<=n;i++)a[i][0]=a[0][i]=0,sum[i][0]=sum[0][i]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(j==1 && i>1)a[i][j]=k+i;
                else if(i+j>2)a[i][j]=((a[i][j-1]*17)%103)*(1-((i+j)%2)*2);
            }
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)sum[i][j]=sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1]+a[i][j];

        int ans=0;
        for(int cx1=1;cx1<=n;cx1++)
            for(int cx2=cx1;cx2<=n;cx2++)
                for(int cy1=1;cy1<=n;cy1++)
                    for(int cy2=cy1;cy2<=n;cy2++)
                        ans=max(ans,sum[cx2][cy2]-sum[cx2][cy1-1]-sum[cx1-1][cy2]+sum[cx1-1][cy1-1]);
        printf("%d\n",ans);
    }
    return 0;
}

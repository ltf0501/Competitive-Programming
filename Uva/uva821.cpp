#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define inf 100000001
int dist[101][101];

main()
{
    int a,b,n,cas=0;
    while(scanf("%d%d",&a,&b)==2 && a+b)
    {
        for(int i=0;i<101;i++)
        {
            for(int j=0;j<101;j++)dist[i][j]=inf;
        }
        for(int i=0;i<101;i++)dist[i][i]=0;

        n=0;
        do
        {
            dist[a][b]=1;
            if(a>n)n=a;
            if(b>n)n=b;
        }while(scanf("%d%d",&a,&b)==2 && a+b);

        for(int k=1;k<=n;k++)
        {
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
        int cnt=0,sum=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if (dist[i][j]<inf && dist[i][j])
                {
                    sum+=dist[i][j];
                    cnt++;
                }
        printf("Case %d: ",++cas);
        printf("average length between pages = %.3lf clicks\n",1.0*sum/cnt);
    }
    return 0;
}

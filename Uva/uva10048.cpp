#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define inf 100000001
int c,s,q;
int d[110][110];
main()
{
    int cas=0;
    while(scanf("%d%d%d",&c,&s,&q)==3 && c+s+q)
    {
        int a,b,r;
        for(int i=1;i<=c;i++)
            for(int j=1;j<=c;j++)d[i][j]=inf;
        for(int i=1;i<=c;i++)d[i][i]=0;

        for(int i=1;i<=s;i++)
        {
            scanf("%d%d%d",&a,&b,&r);
            d[a][b]=r,d[b][a]=r;
        }
        for(int k=1;k<=c;k++)
        {
            for(int i=1;i<=c;i++)
            {
                for(int j=1;j<=c;j++)
                {
                    d[i][j]=min(d[i][j],max(d[i][k],d[k][j]));
                }
            }
        }
        if(cas)puts("");
        printf("Case #%d\n",++cas);
        for(int i=1;i<=q;i++)
        {
            scanf("%d%d",&a,&b);
            if(d[a][b]==inf)printf("no path\n");
            else printf("%d\n",d[a][b]);
        }
    }
    return 0;
}

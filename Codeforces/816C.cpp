#include<bits/stdc++.h>
using namespace std;
#define maxn 105
int a[maxn][maxn],sum;
int r[maxn],c[maxn];
int x[maxn],y[maxn];
int x1[maxn],y1[maxn],sumx,sumy;
main()
{
    int n,m;scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&a[i][j]);
            r[i]+=a[i][j],c[j]+=a[i][j],sum+=a[i][j];
        }
    }
    for(int i=2;i<=n;i++)
    {
        if((r[i]-r[1])%m){puts("-1");return 0;}
        x1[i]=(r[i]-r[1])/m;
        sumx+=x1[i];
    }
    for(int i=2;i<=m;i++)
    {
        if((c[i]-c[1])%n){puts("-1");return 0;}
        y1[i]=(c[i]-c[1])/n;
        sumy+=y1[i];
    }
    if(m!=n)
    {
        int t=sum-m*sumx-(n-1)*sumy-r[1];
        if(t%m){puts("-1");return 0;}
        x[1]=(m*n*a[1][1]-t)/m;
        y[1]=a[1][1]-x[1];
    }
    else
    {

    }

    for(int i=1;i<=n;i++)
    {
        x[i]=x1[i]+x[1];
        if(x[i]<0){puts("-1");return 0;}
    }
    for(int i=1;i<=m;i++)
    {
        y[i]=y1[i]+y[1];
        if(y[i]<0){puts("-1");return 0;}
    }
    //for(int i=1;i<=n;i++)printf("%d ",x[i]);puts("");
    //for(int i=1;i<=m;i++)printf("%d ",y[i]);puts("");
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(x[i]+y[j]!=a[i][j]){puts("-1");return 0;}
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++)cnt+=x[i];
    for(int i=1;i<=m;i++)cnt+=y[i];
    printf("%d\n",cnt);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=x[i];j++)printf("row %d\n",i);
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=y[i];j++)printf("col %d\n",i);
    }
    return 0;
}

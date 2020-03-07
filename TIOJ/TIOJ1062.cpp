#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 105
int x[maxn],y[maxn],sum=0;
main()
{
    int m,n;scanf("%d%d",&m,&n);
    for(int i=1;i<=m;i++)
    {
        int c;
        for(int j=1;j<=n;j++)scanf("%d",&c),x[i]+=c,y[j]+=c,sum+=c;
    }
    sum/=2;
    int t=0;
    for(int i=1;i<=m;i++)
    {
        if(t+x[i]<sum)t+=x[i];
        else
        {
            printf("%d ",i);
            break;
        }
    }
    t=0;
    for(int i=1;i<=n;i++)
    {
        if(t+y[i]<sum)t+=y[i];
        else
        {
            printf("%d\n",i);
            break;
        }
    }
    return 0;
}

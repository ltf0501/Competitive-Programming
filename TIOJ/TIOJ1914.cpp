#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 200+5
#define inf 0x3f3f3f3f
int f[maxn],g[maxn][maxn],n;
int B[maxn];
main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int n,k;scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++)scanf("%d",&B[i]);
        memset(f,inf,sizeof(f));
        memset(g,inf,sizeof(g));
        f[0]=0;
        for(int i=1;i<=n;i++)
        {
            g[i][i]=1;
            if(i+1<=n)
            {
                if(B[i]==B[i+1])g[i][i+1]=1;
                else g[i][i+1]=2;
            }
        }
        for(int k=3;k<=n;k++)
        {
            for(int i=1;i+k-1<=n;i++)
            {
                int j=i+k-1;
                for(int q=i;q<i+k-1;q++)
                    g[i][j]=min(g[i][j],g[i][q]+g[q+1][j]);
                if(B[i]==B[j])g[i][j]=min(g[i][j],min(g[i+1][j],g[i][j-1]));
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(B[i]==0)f[i]=f[i-1];
                f[i]=min(f[i],f[j]+g[j+1][i]);
            }
        }
        printf("%d\n",f[n]);
    }
    return 0;
}


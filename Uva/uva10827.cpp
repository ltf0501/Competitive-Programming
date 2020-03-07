#include <cstdio>
#include <algorithm>
#include<cstring>
using namespace std;

const int MAXN=160;
int m[MAXN][MAXN],s[MAXN][MAXN],a[MAXN],n;
void maxSeq(int* a,int len,int &res)
{
    res=a[0];
    int sum=0;
    for(int i=0;i<len;i++)
    {
        if(sum<=0)sum=a[i];
        else sum+=a[i];
        if(res<sum)res=sum;
    }
}
main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
        {
            scanf("%d",&m[i][j]);
            m[i+n][j]=m[i][j+n]=m[i+n][j+n]=m[i][j];
        }
        memset(s,0,sizeof(s));

        for(int i=1;i<=2*n-1;i++)for(int j=1;j<=2*n-1;j++)
        {
           s[i][j]=s[i-1][j]+m[i][j];
        }

        int ans=-10000000,res;
        for(int i=0;i<=n-1;i++)for(int j=i+1;j<=i+n;j++)
        {
            for(int l=0;l<n;l++)
            {
                for(int k=1;k<=n;k++)a[k]=s[j][k+l]-s[i][k+l];
                maxSeq(a+1,n,res);
                ans=max(ans,res);
            }
        }


        printf("%d\n",ans);
    }
    return 0;
}


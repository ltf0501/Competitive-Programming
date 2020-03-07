#include<bits/stdc++.h>
using namespace std;
#define maxn 5010
int a[maxn],b[maxn][maxn],c[maxn][maxn];
int n;
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)b[i][i]=a[i];
    for(int k=1;k<n;k++)
    {
        for(int i=1;i+k<=n;i++)b[i][i+k]=b[i][i+k-1]^b[i+1][i+k];
    }
    for(int i=1;i<=n;i++)for(int j=i;j<=n;j++)b[i][j]=max(b[i][j],b[i][j-1]);
    for(int j=1;j<=n;j++)for(int i=j;i>=1;i--)c[i][j]=max(b[i][j],c[i+1][j]);
    /*
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)printf("%d ",b[i][j]);puts("");
    }
    */
    int q;scanf("%d",&q);
    while(q--)
    {
        int l,r;scanf("%d%d",&l,&r);
        printf("%d\n",c[l][r]);
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define maxn 2010
int a[maxn];
int g[maxn][maxn];
int n;
main()
{
    scanf("%d",&n);
    int t=0;
    int cnt=0;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),t=__gcd(t,a[i]),cnt+=(a[i]==1);
    if(t!=1){puts("-1");return 0;}
    if(n==1 && a[1]==1){puts("0");return 0;}
    for(int i=1;i<=n;i++)g[i][i]=a[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)g[i][j]=__gcd(g[i][j-1],a[j]);
    }
    for(int k=1;k<n;k++)
    {
        for(int i=1;i+k<=n;i++)
        {
            if(g[i][i+k]==1){printf("%d\n",n-cnt+k-1);return 0;}
        }
    }
    return 0;
}

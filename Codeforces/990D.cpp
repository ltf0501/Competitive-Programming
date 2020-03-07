#include<bits/stdc++.h>
using namespace std;
#define maxn 1010
int n,a,b;
bool c[maxn][maxn];
main()
{
    scanf("%d%d%d",&n,&a,&b);
    if(min(a,b)>1)return 0*puts("NO");
    if((n==3 || n==2) && a==1 && b==1)return 0*puts("NO");
    puts("YES");
    bool flag=0;
    if(a==1)flag^=1,swap(a,b);
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)c[i][j]=flag;
    for(int i=1;i<=n-a;i++)c[i][i+1]=c[i+1][i]=flag^1;
    for(int i=1;i<=n;i++)c[i][i]=0;
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
    {
        printf("%d",c[i][j]);
        if(j==n)puts("");
    }
    return 0;
}

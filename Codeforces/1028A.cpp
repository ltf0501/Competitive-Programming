#include<bits/stdc++.h>
using namespace std;
#define maxn 150
char c[maxn][maxn];
int n,m;
main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)scanf("%s",c[i]);
    int cnt=0;
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)if(c[i][j]=='B')cnt++;
    cnt=sqrt(cnt+0.5);
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)if(c[i][j]=='B')
    {
        printf("%d %d\n",i+1+(cnt-1)/2,j+1+(cnt-1)/2);
        return 0;

    }
    return 0;
}


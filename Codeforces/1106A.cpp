#include<bits/stdc++.h>
using namespace std;
#define maxn 510
int n;
char c[maxn][maxn];
main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%s",c[i]);
    int ans=0;
    for(int i=1;i<n-1;i++)for(int j=1;j<n-1;j++)
    {
        if(c[i][j]=='X' && c[i-1][j-1]=='X' && c[i-1][j+1]=='X' && c[i+1][j-1]=='X' && c[i+1][j+1]=='X')
            ans++;
    }
    printf("%d\n",ans);
    return 0;
}


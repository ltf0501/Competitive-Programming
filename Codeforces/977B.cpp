#include<bits/stdc++.h>
using namespace std;
#define maxn 105
char c[maxn];
int n;
int vis[27][27];
main()
{
    scanf("%d",&n);
    scanf("%s",c);
    for(int i=0;i<n-1;i++)
        vis[c[i]-'A'+1][c[i+1]-'A'+1]++;
    int mx1=0,mx2=0;
    for(int i=1;i<=26;i++)for(int j=1;j<=26;j++)
        if(vis[i][j]>vis[mx1][mx2])mx1=i,mx2=j;
    printf("%c%c\n",mx1+'A'-1,mx2+'A'-1);
    return 0;
}


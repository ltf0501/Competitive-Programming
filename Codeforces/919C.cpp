#include<bits/stdc++.h>
using namespace std;
#define maxn 2010
char c[maxn][maxn];
int n,m,k;
main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)scanf("%s",c[i]+1);
    int ans=0;
    if(k==1)
    {
        for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
            if(c[i][j]=='.')ans++;
        printf("%d\n",ans);
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        int cur=0;
        for(int j=1;j<=m;j++)
        {
            if(c[i][j]=='.')cur++;
            else cur=0;
            if(cur>=k)ans++;
        }
    }
    for(int i=1;i<=m;i++)
    {
        int cur=0;
        for(int j=1;j<=n;j++)
        {
            if(c[j][i]=='.')cur++;
            else cur=0;
            if(cur>=k)ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}

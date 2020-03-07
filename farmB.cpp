#include<bits/stdc++.h>
using namespace std;
#define maxn 1000+5
char c[maxn][maxn];
main()
{
    int n,m,k;scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;i++)scanf("%s",c[i]);

    int ans=1;
    bool flag=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m-1;j++)
        {
            if(c[i][j]!=c[i][j+1])ans++;
            else flag=0;
        }
    }
    //printf("%d\n",ans);
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(c[i][j]!=c[i+1][j])ans++;
            else flag=0;
        }
    }
    if(flag)ans--;
    printf("%d\n",ans);
    return 0;
}

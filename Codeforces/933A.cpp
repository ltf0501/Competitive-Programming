#include<bits/stdc++.h>
using namespace std;
#define maxn 2010
int cnt[3][maxn],mx[maxn][maxn];
main()
{
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x;scanf("%d",&x);
        cnt[x][i]=cnt[x][i-1]+1;
        cnt[3-x][i]=cnt[3-x][i-1];
    }
    for(int i=1;i<=n;i++)
    {
        int cur=-maxn;
        for(int j=i;j<=n;j++)
        {
            cur=max(cur,cnt[2][j]-cnt[1][j]);
            mx[i][j]=cur;
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)ans=max(ans,cnt[1][i]+cnt[2][n]-cnt[2][i]);
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
            ans=max(ans,cnt[1][i-1]+cnt[2][n]-cnt[2][j]+cnt[1][j]-cnt[2][i-1]+mx[i][j]);
    }
    printf("%d\n",ans);
    return 0;
}

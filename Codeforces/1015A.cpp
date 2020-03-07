#include<bits/stdc++.h>
using namespace std;
#define maxn 105
bool vis[maxn];
int n,m,cnt;
main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        for(int j=x;j<=y;j++)vis[j]=1;
    }
    for(int i=1;i<=m;i++)if(!vis[i])cnt++;
    printf("%d\n",cnt);
    for(int i=1;i<=m;i++)if(!vis[i])printf("%d ",i);
    return 0;
}

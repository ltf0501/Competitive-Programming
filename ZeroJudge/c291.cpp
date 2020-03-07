#include<bits/stdc++.h>
using namespace std;
#define maxn 50050
int n;
int a[maxn];
bool vis[maxn];
void dfs(int u)
{
    if(vis[u])return ;
    vis[u]=1;
    dfs(a[u]);
}
main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    int cnt=0;
    for(int i=0;i<n;i++)if(!vis[i])
        dfs(i),cnt++;
    printf("%d\n",cnt);
    return 0;
}

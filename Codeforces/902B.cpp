#include<bits/stdc++.h>
using namespace std;
#define maxn 10010
vector<int> g[maxn];
int n;
int c[maxn];
int cnt=0;
void dfs(int u,int col)
{
    if(c[u]!=col)cnt++;
    for(int v : g[u])dfs(v,c[u]);
}
main()
{
    scanf("%d",&n);
    for(int i=2;i<=n;i++)
    {
        int x;scanf("%d",&x);
        g[x].push_back(i);
    }
    for(int i=1;i<=n;i++)scanf("%d",&c[i]);
    dfs(1,0);
    printf("%d\n",cnt);
    return 0;
}

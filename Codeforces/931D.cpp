#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
vector<int> g[maxn];
int cnt[maxn];
void dfs(int u,int d)
{
    cnt[d]++;
    for(int v : g[u])dfs(v,d+1);
}
main()
{
    int n;scanf("%d",&n);
    for(int i=2;i<=n;i++)
    {
        int x;scanf("%d",&x);
        g[x].push_back(i);
    }
    dfs(1,0);
    int ans=0;
    for(int i=0;i<n;i++)ans+=(cnt[i]&1);
    printf("%d\n",ans);
    return 0;
}

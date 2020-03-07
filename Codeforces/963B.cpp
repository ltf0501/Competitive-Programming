#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
int n;
vector<int> g[maxn],ans,ord,tmp;
bool vis[maxn];
int deg[maxn],p[maxn];
void dfs(int u)
{
    for(int v : g[u])dfs(v);
    ord.push_back(u);
}
main()
{
    scanf("%d",&n);
    int rt=0;
    for(int i=1;i<=n;i++)
    {
        int x;scanf("%d",&x);
        if(!x)rt=i;
        else g[x].push_back(i),deg[x]++,deg[i]++;
        p[i]=x;
    }
    if(n%2==0)return 0*puts("NO");
    puts("YES");
    dfs(rt);
    for(int u : ord)
    {
        if(deg[u]&1)tmp.push_back(u);
        else ans.push_back(u),deg[p[u]]--;
    }
    reverse(tmp.begin(),tmp.end());
    for(int u : tmp)ans.push_back(u);
    for(int u : ans)printf("%d ",u);
    return 0;
}

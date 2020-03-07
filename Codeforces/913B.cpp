#include<bits/stdc++.h>
using namespace std;
#define maxn 1005
int n;
vector<int> g[maxn];
bool leaf[maxn];
int num[maxn];
void dfs(int u)
{
    if(!g[u].size())leaf[u]=1;
    for(int v : g[u])
    {
        dfs(v);
        if(leaf[v])num[u]++;
    }
}
main()
{
    scanf("%d",&n);
    for(int i=2;i<=n;i++)
    {
        int x;scanf("%d",&x);
        g[x].push_back(i);
    }
    dfs(1);
    bool flag=1;
    for(int i=1;i<=n;i++)
    if(!leaf[i] && num[i]<3){flag=0;break;}
    puts(flag ? "Yes" : "No");
    return 0;
}


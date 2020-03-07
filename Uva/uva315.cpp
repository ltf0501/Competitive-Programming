#include<bits/stdc++.h>
using namespace std;
#define maxn 105
vector<int> g[maxn];
bool iscut[maxn];
int pre[maxn],dfs_clock,cnt;
int dfs(int u,int fa)
{
    int lowu=pre[u]=++dfs_clock;
    int ch=0;
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(!pre[v])
        {
            ch++;
            int lowv=dfs(v,u);
            lowu=min(lowu,lowv);
            if(lowv>=pre[u])iscut[u]=1;
        }
        else if(pre[v]<pre[u] && v!=fa)lowu=min(lowu,pre[v]);
    }
    if(fa<0 && ch==1)iscut[u]=0;
    return lowu;
}
main()
{
    int n;
    string line;
    while(~scanf("%d ",&n) && n)
    {
        dfs_clock=0;
        cnt=0;
        for(int i=1;i<=n;i++)g[i].clear();
        memset(iscut,false,sizeof(iscut));
        memset(pre,0,sizeof(pre));
        int a,b;
        while(getline(cin,line))
        {
            stringstream ss(line);
            ss >> a;
            if(!a)break;
            while(ss >> b)
            {
                g[a].push_back(b);
                g[b].push_back(a);
            }
        }
        dfs(1,-1);
        for(int i=1;i<=n;i++)if(iscut[i])cnt++;
        printf("%d\n",cnt);
    }
}

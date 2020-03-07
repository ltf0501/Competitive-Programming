#include<bits/stdc++.h>
using namespace std;
#define maxn 10000+5
int pre[maxn],lowlink[maxn],sccno[maxn],dfs_clock,scc_cnt,topo[maxn];
int n,m;
vector<int> g[maxn];
stack<int> S;
map<string,int> mp;
void dfs(int u)
{
    pre[u]=lowlink[u]=++dfs_clock;
    S.push(u);
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(!pre[v])
        {
            dfs(v);
            lowlink[u]=min(lowlink[u],lowlink[v]);
        }
        else if(!sccno[v])lowlink[u]=min(lowlink[u],pre[v]);
    }
    if(lowlink[u]==pre[u])
    {
        scc_cnt++;
        for(;;)
        {
            int x=S.top();S.pop();
            sccno[x]=scc_cnt;
            if(x==u)break;
        }
    }
}
void find_scc()
{
    dfs_clock=scc_cnt=0;
    memset(sccno,0,sizeof(sccno));
    memset(pre,0,sizeof(pre));
    for(int i=1;i<=n;i++)
        if(!pre[i])dfs(i);
}

main()
{
    while(~scanf("%d%d\n",&n,&m) && n+m)
    {
        for(int i=1;i<=n;i++)g[i].clear();
        mp.clear();
        //for(int i=1;i<=n;i++)g2[i].clear();
        for(int i=1;i<=n;i++)
        {
            string s;
            getline(cin,s);
            mp[s]=i;
        }
        for(int i=0;i<m;i++)
        {
            string s,t;
            getline(cin,s),getline(cin,t);
            g[mp[s]].push_back(mp[t]);
        }
        find_scc();
        printf("%d\n",scc_cnt);
    }
    return 0;
}


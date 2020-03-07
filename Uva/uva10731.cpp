#include<bits/stdc++.h>
using namespace std;
#define maxn 30
int n;
bool app[maxn];
vector<int> g[maxn];
int pre[maxn],sccno[maxn],low[maxn],dfs_clock,scc_cnt;
stack<int> S;
vector<char> ans[maxn];
bool cmp(int i,int j)
{
    return ans[i][0]<ans[j][0];
}
void dfs(int u)
{
    pre[u]=low[u]=++dfs_clock;
    S.push(u);
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(!pre[v])
        {
            dfs(v);
            low[u]=min(low[u],low[v]);
        }
        else if(!sccno[v])low[u]=min(low[u],pre[v]);
    }
    if(low[u]==pre[u])
    {
        scc_cnt++;
        for(;;)
        {
            int x=S.top();S.pop();
            sccno[x]=scc_cnt;
            ans[scc_cnt].push_back(x+'A');
            if(x==u)break;
        }
    }
}
void find_scc()
{
    dfs_clock=scc_cnt=0;
    memset(sccno,0,sizeof(sccno));
    memset(pre,0,sizeof(pre));
    for(int i=0;i<26;i++)
        if(!pre[i] && app[i])dfs(i);
}
bool first=0;
main()
{
    while(~scanf("%d",&n) && n)
    {
        for(int i=0;i<26;i++)g[i].clear();
        for(int i=1;i<30;i++)ans[i].clear();
        memset(app,false,sizeof(app));
        for(int i=0;i<n;i++)
        {
            char y[5][4],x[5];
            for(int j=0;j<5;j++)scanf("%s",y[j]),app[y[j][0]-'A']=1;
            scanf("%s",x);app[x[0]-'A']=1;
            for(int j=0;j<5;j++)
                if(y[j][0]!=x[0])g[y[j][0]-'A'].push_back(x[0]-'A');
        }
        find_scc();
        //for(int i=0;i<26;i++)printf("%c : %d\n",i+'A',sccno[i]);
        if(first)puts("");
        first=1;
        for(int i=1;i<=scc_cnt;i++)sort(ans[i].begin(),ans[i].end());
        sort(ans+1,ans+scc_cnt+1);
        for(int i=1;i<=scc_cnt;i++)
        {
            printf("%c",ans[i][0]);
            for(int j=1;j<ans[i].size();j++)printf(" %c",ans[i][j]);
            puts("");
        }

    }
    return 0;
}

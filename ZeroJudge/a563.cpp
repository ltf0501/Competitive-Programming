#include<bits/stdc++.h>
using namespace std;
#define maxn 90000+10
#define INF 10000000
vector<int> g[maxn];
int leaf[maxn],cnt[maxn];
int Cnt;//業節點個數
int dfs(int u)
{
    int ans=0;
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        ans+=dfs(v);
    }
    if(!ans)return 1;
    return leaf[u]=ans;
}
int dfs2(int u)
{
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(2*leaf[v]>Cnt)return dfs2(v);
    }
    return u;
}
main()
{
    int n;
    while(~scanf("%d",&n))
    {
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<n;i++)g[i].clear();
        for(int i=1;i<n;i++)
        {
            int x;scanf("%d",&x);
            g[x].push_back(i);
            cnt[i]++,cnt[x]++;
        }
        Cnt=0;
        for(int i=0;i<n;i++)if(cnt[i]==1)Cnt++;
        dfs(0);
        //printf("%d\n",Cnt);
        //for(int i=0;i<n;i++)printf("%d ",leaf[i]);puts("");
        printf("%d\n",dfs2(0));

    }
    return 0;
}

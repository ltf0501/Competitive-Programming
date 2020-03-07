
#include<bits/stdc++.h>
using namespace std;
#define maxn 105
#define maxm 1005
vector<int> g[maxn];
int match[maxm];
bool vis[maxn];
int a[maxn],sum[maxn];
int id[maxn];
int ans,n,m;
bool dfs(int u)
{
    vis[u]=1;
    for(int v : g[u])if(!vis[match[v]])
    {
        if(!match[v] || dfs(match[v]))
        {
            if(!match[v])ans++;
            match[v]=u;
            return 1;
        }
    }
    return 0;
}
vector<int> v[maxn];
main()
{
    while(~scanf("%d%d",&n,&m) && n+m)
    {
        for(int i=1;i<=100;i++)g[i].clear(),v[i].clear();
        for(int i=1;i<=n;i++)scanf("%d",&a[i]),sum[i]=a[i]+sum[i-1];
        for(int i=1;i<=n;i++)
        {
            for(int j=sum[i-1]+1;j<=sum[i];j++)id[j]=i;
        }
        for(int i=1;i<=m;i++)
        {
            int num;scanf("%d",&num);
            for(int j=1;j<=num;j++)
            {
                int x;scanf("%d",&x);
                for(int k=sum[x-1]+1;k<=sum[x];k++)g[k].push_back(i);
            }
        }
        ans=0;
        memset(match,0,sizeof(match));
        for(int i=1;i<=100;i++)
        {
            dfs(i);
            memset(vis,0,sizeof(vis));
        }
        //printf("ans=%d\n",ans);
        if(ans!=sum[n])puts("0");
        else
        {
            puts("1");
            for(int j=1;j<=m;j++)v[id[match[j]]].push_back(j);
            for(int i=1;i<=n;i++)
            {
                for(int j=0;j<v[i].size();j++)printf("%d%c",v[i][j],j==v[i].size()-1 ? '\n' : ' ');
            }
        }
    }
    return 0;
}

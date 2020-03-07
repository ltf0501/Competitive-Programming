#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
int n,nxt[maxn],c[maxn];
int dp[maxn];
int vis[maxn];
int cir[maxn],num;
vector<int> v,tmp;
void dfs(int u)
{
    //printf("%d ",u);
    if(vis[u]>=2 || cir[u]==-1)return ;
    if(!vis[u])tmp.push_back(u);
    vis[u]++;
    if(vis[u]<=1)dfs(nxt[u]);
    else
    {
        if(nxt[u]==u){v.push_back(c[u]);return ;}
        int ret=c[u];
        int x=nxt[u];
        while(x!=u)ret=min(ret,c[x]),vis[x]++,x=nxt[x];
        v.push_back(ret);
    }
}
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&c[i]);
    for(int i=1;i<=n;i++)scanf("%d",&nxt[i]);
    int sum=0;
    for(int i=1;i<=n;i++)if(!vis[i])
    {
        tmp.clear();
        dfs(i);
        for(int s : tmp)if(vis[i]<=1)cir[s]=-1;
    }

    int ans=0;
    for(int s : v)ans+=s;
    printf("%d\n",ans);
    return 0;
}

#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
#define maxn 1000000+10
int n;
vector<int> G[maxn];
int num[maxn],ans[maxn];
void dfs(int u,int fa)
{
    num[u]=1;ans[u]=0;
    for(int i=0;i<G[u].size();i++)
    {
        int v=G[u][i];
        if(v==fa)continue;
        dfs(v,u);
        num[u]+=num[v];
        ans[u]=max(ans[u],num[v]);
        ans[v]=max(ans[v],n-num[v]);
    }
}
main()
{
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        G[a].push_back(b);G[b].push_back(a);
    }
    dfs(0,-1);
    int Ans=maxn;
    for(int i=0;i<n;i++)Ans=min(Ans,ans[i]);
    printf("%d\n",Ans);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
vector<int> g[maxn],ans;
int n;
int deg[maxn];
void dfs(int u,int fa)
{
    if(deg[u]==1 && fa!=-1)ans.push_back(u);
    for(int v : g[u])
        if(v!=fa)dfs(v,u);
}
main()
{
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        g[x].push_back(y),g[y].push_back(x);
        deg[x]++,deg[y]++;
    }
    int root=0,cnt=0;
    for(int i=1;i<=n;i++)
        if(deg[i]>=3)cnt++,root=i;
    if(cnt>=2)return 0*puts("No");
    puts("Yes");
    if(!root)
    {
        puts("1");
        for(int i=1;i<=n;i++)
            if(deg[i]==1)ans.push_back(i);
        for(int s : ans)printf("%d ",s);
        return 0;
    }
    dfs(root,-1);
    printf("%d\n",ans.size());
    for(int s : ans)printf("%d %d\n",root,s);
    return 0;
}

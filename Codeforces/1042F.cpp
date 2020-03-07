#include<bits/stdc++.h>
using namespace std;
#define maxn 1000010
int n,k,ans;
vector<int> g[maxn];
int dfs(int u,int fa)
{
    vector<int> cur;
    for(int v : g[u])if(v!=fa)
        cur.push_back(dfs(v,u)+1);
    if(cur.empty())return 0;
    sort(cur.begin(),cur.end());
    while(cur.size()>=2)
    {
        int m=cur.size();
        if(cur[m-1]+cur[m-2]<=k)break;
        ans++,cur.pop_back();
    }
    return cur.back();
}
main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<n;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        g[x].push_back(y),g[y].push_back(x);
    }
    int rt=-1;
    for(int i=1;i<=n;i++)
        if(g[i].size()>1){rt=i;break;}
    dfs(rt,-1);
    printf("%d\n",ans+1);
    return 0;
}

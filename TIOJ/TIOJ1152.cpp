#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
#define maxn 10000+5
vector<int> G[maxn];
int n;
int max_d,max_v;
void dfs(int u,int fa,int d)
{
    if(d>max_d)max_d=d,max_v=u;
    for(int i=0;i<G[u].size();i++)
    {
        int v=G[u][i];
        if(v==fa)continue;
        dfs(v,u,d+1);
    }
}
main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int a;
        while(~scanf("%d",&a) && a!=-1)G[i].push_back(a),G[a].push_back(i);
    }
    max_d=0;
    dfs(0,-1,0);
    max_d=0;
    dfs(max_v,-1,0);
    printf("%d\n",max_d);
    return 0;
}

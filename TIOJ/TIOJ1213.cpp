#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
#define maxn 100000+10
struct node
{
    int to,dis;
};
vector<node> G[maxn];
int n;
int max_d,max_v;
void dfs(int u,int fa,int d)
{
    if(d>max_d)max_v=u,max_d=d;
    for(int i=0;i<G[u].size();i++)
    {
        node v=G[u][i];
        if(v.to==fa)continue;
        dfs(v.to,u,d+v.dis);
    }
}
main()
{
    while(~scanf("%d",&n) && n)
    {
        for(int i=1;i<=n;i++)G[i].clear();
        for(int i=0;i<n-1;i++)
        {
            int a,b,d;
            scanf("%d%d%d",&a,&b,&d);
            G[a].push_back((node){b,d});
            G[b].push_back((node){a,d});
        }
        max_d=0;
        dfs(1,-1,0);
        dfs(max_v,-1,0);
        printf("%d\n",max_d);
    }
    return 0;
}



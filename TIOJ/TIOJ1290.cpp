#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
#define maxn 1000+5
#define LL long long
struct node
{
    int to,dis;
};
vector<node> G[maxn];
LL d[maxn];

main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=1;i<=n;i++)G[i].clear();
        memset(d,-1,sizeof(d));
        int st,ed;
        scanf("%d%d",&st,&ed);
        for(int i=1;i<=m;i++)
        {
            int a,b,d;
            scanf("%d%d%d",&a,&b,&d);
            G[a].push_back((node){b,d});
            G[b].push_back((node){a,d});
        }
        queue<int> q;
        q.push(st);d[st]=0;
        while(!q.empty())
        {
            int u=q.front();q.pop();
            for(int i=0;i<G[u].size();i++)
            {
                node v=G[u][i];
                if(d[v.to]==-1 || d[v.to]>d[u]+v.dis)
                {
                    d[v.to]=d[u]+v.dis;q.push(v.to);
                }
            }
        }
        if(d[ed]==-1)puts("He is very hot");
        else printf("%lld\n",d[ed]);
    }
    return 0;
}

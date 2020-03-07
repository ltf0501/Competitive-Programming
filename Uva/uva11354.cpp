#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
#define maxn 50000+5
#define maxm 100000+5
#define INF 1000000000
int u[maxm],v[maxm],w[maxm],r[maxm];
int n,m;
int f[maxn],fa[maxn];
int anc[maxn][20],L[maxn],cost[maxn],maxcost[maxn][20];
struct node
{
    int to,dis;
};
vector<node> G[maxn];
int finds(int x)
{
    return f[x]==x ? x : f[x]=finds(f[x]);
}
int cmp(int i,int j)
{
    return w[i]<w[j];
}
void kruskal()
{
    for(int i=1;i<=n;i++)f[i]=i;
    for(int i=0;i<m;i++)r[i]=i;
    sort(r,r+m,cmp);
    int cnt=0;
    for(int i=0;i<m;i++)
    {
        int e=r[i];
        int x=finds(u[e]),y=finds(v[e]);
        if(x!=y)
        {
            f[x]=y,cnt++;
            G[u[e]].push_back((node){v[e],w[e]});
            G[v[e]].push_back((node){u[e],w[e]});
        }
        if(cnt==n-1)return ;
    }
}
void dfs(int u,int pa,int d)
{
    L[u]=d;
    for(int i=0;i<G[u].size();i++)
    {
        node v=G[u][i];
        if(v.to==pa)continue;
        fa[v.to]=u;
        cost[v.to]=v.dis;
        dfs(v.to,u,d+1);
    }
}
int query(int p,int q)
{
    if(L[p]<L[q])swap(p,q);
    int hibit;
    for(hibit=1;(1<<hibit)<=L[p];hibit++);hibit--;
    int ans=-INF;
    for(int i=hibit;i>=0;i--)
        if(L[p]-(1<<i)>=L[q])
        {
            ans=max(ans,maxcost[p][i]);
            p=anc[p][i];
        }
    if(p==q)return ans;
    for(int i=hibit;i>=0;i--)
        if(anc[p][i]!=-1 && anc[p][i]!=anc[i][q])
        {
            ans=max(ans,maxcost[p][i]);p=anc[p][i];
            ans=max(ans,maxcost[q][i]);q=anc[q][i];
        }
    ans=max(ans,cost[p]);
    ans=max(ans,cost[q]);
    return ans;
}
main()
{
    int cas=0;
    while(~scanf("%d%d",&n,&m))
    {
        if(cas++)puts("");
        for(int i=1;i<=n;i++)G[i].clear();
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&u[i],&v[i],&w[i]);
        }
        kruskal();
        fa[1]=-1;
        dfs(1,-1,0);
        //for(int i=1;i<=n;i++)printf("%d\n",L[i]);

        memset(anc,-1,sizeof(anc));
        memset(maxcost,-1,sizeof(maxcost));
        for(int i=2;i<=n;i++)anc[i][0]=fa[i],maxcost[i][0]=cost[i];

        for(int j=1;(1<<j)<n;j++)
            for(int i=1;i<=n;i++)
                if(anc[i][j-1]!=-1)
                {
                    int a=anc[i][j-1];
                    if(anc[a][j-1]==-1) continue;
                    anc[i][j]=anc[a][j-1];
                    maxcost[i][j]=max(maxcost[i][j-1],maxcost[a][j-1]);
                }
        /*
        for(int i=1;i<=n;i++)
        {
            for(int j=0;(1<<j)<n;j++)printf("%d ",maxcost[i][j]);
            puts("");
        }
        */
        int q;scanf("%d",&q);
        while(q--)
        {
            int x,y;scanf("%d%d",&x,&y);
            int ans=query(x,y);
            printf("%d\n",ans);
        }


    }
    return 0;
}

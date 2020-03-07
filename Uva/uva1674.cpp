#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
#define maxn 50000+5
vector<int> G[maxn];
int mark[maxn],sum[maxn];
int fa[maxn],dep[maxn];
int anc[maxn][17];
int n;
void dfs(int u,int p,int d)
{
    fa[u]=p;
    dep[u]=d;
    for(int i=0;i<G[u].size();i++)
    {
        int v=G[u][i];
        if(v==p)continue;
        dfs(v,u,d+1);
    }
}
void dfs2(int u,int p)
{
    sum[u]=mark[u];
    for(int i=0;i<G[u].size();i++)
    {
        int v=G[u][i];
        if(v==p)continue;
        dfs2(v,u);
        sum[u]+=sum[v];
    }
}
void pre()
{
    memset(anc,-1,sizeof(anc));
    for(int i=0;i<n;i++)anc[i][0]=fa[i];
    for(int j=1;(1<<j)<n;j++)
        for(int i=1;i<=n;i++)
           if(anc[i][j-1]!=-1)
            {
                int a=anc[i][j-1];
                if(anc[a][j-1]==-1)continue;
                anc[i][j]=anc[a][j-1];
            }
}
int LCA(int p,int q)
{
    if(dep[p]<dep[q])swap(p,q);
    int h;
    for(h=1;(1<<h)<=dep[p];h++);h--;
    for(int i=h;i>=0;i--)
        if(dep[p]-(1<<i)>=dep[q])p=anc[p][i];
    if(p==q)return p;
    for(int i=h;i>=0;i--)
        if(anc[p][i]!=-1 && anc[p][i]!=anc[q][i])p=anc[p][i],q=anc[q][i];
    return fa[p];
}
main()
{
    int t;scanf("%d",&t);
    int cas=0;
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)G[i].clear();
        memset(mark,0,sizeof(mark));
        for(int i=0;i<n-1;i++)
        {
            int x,y;scanf("%d%d",&x,&y);
            G[x].push_back(y);G[y].push_back(x);
        }
        dfs(0,-1,0);
        pre();
        /*
        for(int i=0;i<n;i++)
        {
            for(int j=0;(1<<j)<n;j++)printf("%d ",anc[i][j]);
            puts("");
        }
        */
        int q;scanf("%d",&q);
        while(q--)
        {
            int a,b,c;scanf("%d%d%d",&a,&b,&c);
            mark[a]+=c,mark[b]+=c;
            int d=LCA(a,b);
            //printf("%d\n",d);
            mark[d]-=c;
            if(d)mark[fa[d]]-=c;
        }
        //for(int i=0;i<n;i++)printf("%d ",mark[i]);
        memset(sum,0,sizeof(sum));
        dfs2(0,-1);
        printf("Case #%d:\n",++cas);
        for(int i=0;i<n;i++)printf("%d\n",sum[i]);
    }
    return 0;
}
/*
1
9
0 1
1 2
2 3
2 4
2 7
7 8
7 6
6 5
5
1 4 10
3 5 3
0 8 5
1 6 10
4 4 100
*/

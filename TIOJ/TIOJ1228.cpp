#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
#define maxn 1000000+5
int n,q;
struct node
{
    int to,dis;
};
vector<node> G[maxn];
int a[maxn],c[maxn],cnt;
int in[maxn],out[maxn],dfs_clock;
int sum(int x)
{
    int ret=0;
    while(x>0)
    {
        ret+=c[x];x-=(x&-x);
    }
    return ret;
}
void add(int x,int d)
{
    while(x<=n)
    {
        c[x]+=d;x+=(x&-x);
    }
}
void dfs(int u)
{
    in[u]=++dfs_clock;
    for(int i=0;i<G[u].size();i++)
    {
        a[++cnt]=G[u][i].dis;
        dfs(G[u][i].to);
    }
    out[u]=dfs_clock;
}
main()
{
    scanf("%d%d",&n,&q);
    for(int i=0;i<n-1;i++)
    {
        int a,b,m;
        scanf("%d%d%d",&a,&b,&m);
        G[a].push_back((node){b,m});
    }
    cnt=0;
    dfs_clock=0;
    dfs(0);
    for(int i=1;i<=n;i++)add(i,a[i]);
    while(q--)
    {
        int c;scanf("%d",&c);
        if(c==0)
        {
            int d,m;scanf("%d%d",&d,&m);
            add(in[d]-1,m-a[in[d]-1]);
            a[in[d]-1]=m;
        }
        else
        {
            int d;scanf("%d",&d);
            printf("%d\n",2*(sum(out[d]-1)-sum(in[d]-1)));
        }
    }
    return 0;
}

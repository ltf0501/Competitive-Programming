#include<bits/stdc++.h>
using namespace std;
#define maxn 100000+5
int c[maxn],r[maxn];
int d[maxn];
int n,m;
bool flag=1;
struct node
{
    int id,type;
};
vector<node> g[maxn];
bool dfs(int u)
{
    for(int i=0;i<g[u].size();i++)
    {
        node v=g[u][i];
        if(d[v.id]>=0 && (d[u]+d[v.id]+v.type)%2==0)return 0;
        if(d[v.id]==-1)
        {
            d[v.id]=((3-d[u]-v.type)%2);
            if(!dfs(v.id))return 0;
        }
    }
    return 1;
}
main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&r[i]);
    memset(d,-1,sizeof(d));
    for(int i=1;i<=m;i++)
    {
        int x;scanf("%d",&x);
        while(x--)
        {
            int a;scanf("%d",&a);
            if(!c[a])c[a]=i;
            else g[i].push_back((node){c[a],r[a]}),g[c[a]].push_back((node){i,r[a]});
        }
    }
    //for(int i=0;i<g[3].size();i++)printf("%d %d\n",g[3][i].id,g[3][i].type);
    for(int i=1;i<=m;i++)
        if(d[i]==-1)
        {
            d[i]=0;
            //printf("%d\n",i);
            if(!dfs(i)){flag=0;break;};

        }

    //for(int i=1;i<=m;i++)printf("%d ",d[i]);
    if(flag)puts("YES");else puts("NO");
    return 0;
}

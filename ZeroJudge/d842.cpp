#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
#define maxn 300+10
vector<int> g[maxn],layer[maxn];
int p[maxn],cut[maxn]={};
int res=0x3f3f3f3f;
void root(int u,int fa,int dep)
{
    layer[dep].push_back(u);
    p[u]=fa;
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(v!=fa)root(v,u,dep+1);
    }
}
void dfs(int dep,int sum)
{
    int cnt=0;
    int d=layer[dep].size();
    for(int i=0;i<d;i++)
    {
        if(cut[p[layer[dep][i]]])cut[layer[dep][i]]=1;
        else cnt++,cut[layer[dep][i]]=0;
    }
    if(cnt==0)
    {
        if(sum<res)res=sum;
        return;
    }
    if(sum>=res)return;
    for(int i=0;i<d;i++)
    {
        if(cut[layer[dep][i]]==0)
        {
            cut[layer[dep][i]]=1;
            dfs(dep+1,sum+cnt-1);
            cut[layer[dep][i]]=0;
        }

    }
}
main()
{
    int n,p,x,y;
    scanf("%d%d",&n,&p);
    while(p--)
    {
        scanf("%d%d",&x,&y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    root(1,-1,1);
    dfs(2,1);
    printf("%d\n",res);
    return 0;
}

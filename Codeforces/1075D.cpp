#include<bits/stdc++.h>
using namespace std;
#define maxn 1010
#define umr fflush(stdout)
int n;
vector<int> g[maxn];
int a[maxn],b[maxn],tmp;
bool flag1[maxn],flag2[maxn];
void init(int n)
{
    memset(flag1,0,sizeof(flag1));
    memset(flag2,0,sizeof(flag2));
    for(int i=1;i<=n;i++)g[i].clear();
    tmp=0;
}
void dfs(int u,int fa)
{
    if(flag1[u]){tmp=u;return ;}
    for(int v : g[u])if(v!=fa)
        dfs(v,u);
}
main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        init(n);
        for(int i=1;i<n;i++)
        {
            int x,y;scanf("%d%d",&x,&y);
            g[x].push_back(y),g[y].push_back(x);
        }
        int k1;scanf("%d",&k1);
        for(int i=1;i<=k1;i++)scanf("%d",&a[i]),flag1[a[i]]=1;
        int k2;scanf("%d",&k2);
        for(int i=1;i<=k2;i++)scanf("%d",&b[i]),flag2[b[i]]=1;
        printf("B %d\n",b[1]);umr;
        int x;scanf("%d",&x);
        if(flag1[x]){printf("C %d\n",x);umr;continue;}
        dfs(x,-1);
        printf("A %d\n",tmp);umr;
        scanf("%d",&x);
        if(flag2[x])printf("C %d\n",tmp);
        else printf("C %d\n",-1);
        umr;
    }
    return 0;
}

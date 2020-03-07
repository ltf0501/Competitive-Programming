#include<bit/stsdc++.h>
using namespace std;
#define maxn 200050
int a[maxn];
vector<int> g[maxn];
int Gcd1[maxn],Gcd2[maxn];
void dfs(int u,int fa)
{
    Gcd1[u]=__gcd(a[u],Gcd1[fa]);

    for(int v : g[u])if(v!=fa)
    {

        dfs(v,u);
    }
}
main()
{
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<n;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        g[x].push_back(y),g[y].push_back(x);
    }
    dfs(1,0);
    return 0;
}

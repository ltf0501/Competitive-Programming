#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
#define ll long long
int col[maxn];
vector<int> g[maxn];
void dfs(int u,int fa,int c)
{
    col[u]=c;
    for(int v : g[u])if(v!=fa)
        dfs(v,u,3-c);
}
main()
{
    int n;scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        g[x].push_back(y),g[y].push_back(x);
    }
    dfs(1,0,1);
    ll a[3]={0};
    for(int i=1;i<=n;i++)a[col[i]]++;
    printf("%I64d\n",(a[1]*a[2])-(ll)(n-1));
    return 0;
}

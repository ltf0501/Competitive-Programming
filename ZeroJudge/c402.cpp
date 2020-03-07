#include<bits/stdc++.h>
using namespace std;
#define maxn 3005
int col[maxn],t[maxn],a[maxn],dp[3000001];
vector<int> g[maxn];
int n,m,tot,sum;
int s(int x){return x==1 ? 1 : -1;}
bool dfs(int u,int c,int& ans)
{
    col[u]=c;
    ans+=s(c)*a[u];
    for(int v : g[u])
    {
        if(col[v]==col[u])return 0;
        else if(!col[v])
        {
            if(!dfs(v,3-c,ans))return 0;
        }
    }
    return 1;
}
main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),sum+=a[i];
    for(int i=1;i<=m;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        g[x].push_back(y),g[y].push_back(x);
    }
    int now=1;
    for(int i=1;i<=n;i++)if(!col[i])
    {
        if(!dfs(i,1,t[now])){puts("Bye Bye Cruel World!");return 0;}
        t[now]=abs(t[now]),tot+=t[now],now++;
    }
    now--;
    //printf("%d\n",now);
    //for(int i=1;i<=now;i++)printf("%d ",t[i]);
    int k=tot/2;
    for(int i=1;i<=now;i++)
    {
        for(int j=k;j>=1;j--)if(j>=t[i])dp[j]=max(dp[j],dp[j-t[i]]+t[i]);
    }
    //printf("%d %d %d\n",dp[k],tot,sum);
    printf("%d %d\n",(2*dp[k]-tot+sum)/2,(sum+tot-2*dp[k])/2);
    return 0;
}

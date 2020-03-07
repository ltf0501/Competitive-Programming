#include<bits/stdc++.h>
using namespace std;
#define maxn 500010
vector<int> g[maxn];
int cnt[maxn];
int n,m;
int a[maxn];
main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=m;i++)
    {
        int u,v;scanf("%d%d",&u,&v);
        g[v].push_back(u);
    }
    for(int u : g[a[n]])cnt[u]++;
    int ans=0,cur=1;
    for(int i=n-1;i>=1;i--)
    {
        if(cnt[a[i]]==cur)ans++;
        else
        {
            cur++;
            for(int u : g[a[i]])cnt[u]++;
        }
    }
    printf("%d\n",ans);
    return 0;
}

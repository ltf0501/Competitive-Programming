#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define F first
#define S second
#define maxn 100010
vector<int> g[26];
bool vis[maxn];
vector<pii> ans;
int n;
char a[maxn],b[maxn];
void dfs(int u)
{
    vis[u]=1;
    for(int v : g[u])if(!vis[v])
    {
        ans.push_back(pii(u,v));
        dfs(v);
    }
}
main()
{
    scanf("%d",&n);
    scanf("%s%s",a+1,b+1);
    for(int i=1;i<=n;i++)
    {
        int x=a[i]-'a',y=b[i]-'a';
        g[x].push_back(y),g[y].push_back(x);
    }
    for(int i=0;i<26;i++)
        if(!vis[i])dfs(i);
    printf("%d\n",ans.size());
    for(pii s : ans)printf("%c %c\n",s.F+'a',s.S+'a');
    return 0;
}

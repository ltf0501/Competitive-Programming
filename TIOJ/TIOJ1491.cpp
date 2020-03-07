#include<bits/stdc++.h>
using namespace std;
#define maxn 2005
int n,cnt;
unordered_map<string,int> mp;
vector<int> g[maxn];
void init()
{
    cnt=0;
    mp.clear();
    for(int i=1;i<=n;i++)g[i].clear();
}
int de,ans;
void dfs(int u,int fa,int dep)
{
    if(dep>ans)de=u,ans=dep;
    for(int v : g[u])if(v!=fa)
        dfs(v,u,dep+1);
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    while(cin>>t)while(t--)
    {
        init();
        cin>>n;
        string s,t;
        for(int i=1;i<n;i++)
        {
            cin>>s>>t;
            if(mp.find(s)==mp.end())mp[s]=++cnt;
            if(mp.find(t)==mp.end())mp[t]=++cnt;
            g[mp[s]].push_back(mp[t]),g[mp[t]].push_back(mp[s]);
        }
        cin>>s>>t;
        ans=0;
        dfs(1,0,0);
        //printf("%d %d\n",de,ans);
        ans=0;
        dfs(de,0,0);
        printf("%d\n",ans);
    }
    return 0;
}

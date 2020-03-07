#include<bits/stdc++.h>
using namespace std;
#define maxn 105
map<string,int> mp;
string mp2[maxn];
vector<int> g[maxn];
bool iscut[maxn];
int pre[maxn],dfs_clock,cnt;
int dfs(int u,int fa)
{
    int lowu=pre[u]=++dfs_clock;
    int ch=0;
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(!pre[v])
        {
            ch++;
            int lowv=dfs(v,u);
            lowu=min(lowu,lowv);
            if(lowv>=pre[u])iscut[u]=1;
        }
        else if(pre[v]<pre[u] && v!=fa)lowu=min(lowu,pre[v]);
    }
    if(fa<0 && ch==1)iscut[u]=0;
    return lowu;
}
main()
{
    int n,cas=1;
    while(~scanf("%d",&n) && n)
    {
        dfs_clock=0;
        cnt=0;
        for(int i=0;i<n;i++)g[i].clear();
        memset(iscut,false,sizeof(iscut));
        memset(pre,0,sizeof(pre));
        string s;
        for(int i=0;i<n;i++)cin>>s,mp[s]=i,mp2[i]=s;
        int m;scanf("%d",&m);
        while(m--)
        {
            string s1,s2;cin>>s1>>s2;
            g[mp[s1]].push_back(mp[s2]),g[mp[s2]].push_back(mp[s1]);
        }
        vector<string> ans;
        for(int i=0;i<n;i++)if(!pre[i])dfs(i,-1);
        for(int i=0;i<n;i++)if(iscut[i])cnt++,ans.push_back(mp2[i]);
        if(cas!=1)puts("");
        printf("City map #%d: %d camera(s) found\n",cas++,cnt);
        sort(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<endl;

    }
    return 0;
}
/*
6
sugarloaf
maracana
copacabana
ipanema
corcovado
lapa
7
ipanema copacabana
copacabana sugarloaf
ipanema sugarloaf
maracana lapa
sugarloaf maracana
corcovado sugarloaf
lapa corcovado
5
guanabarabay
downtown
botanicgarden
colombo
sambodromo
4
guanabarabay sambodromo
downtown sambodromo
sambodromo botanicgarden
colombo sambodromo
0
*/

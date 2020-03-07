#include<bits/stdc++.h>
using namespace std;
#define maxn 30
vector<int> g[maxn];
string name[maxn][maxn];
vector<string> ans;
int match[maxn];
bool vis[maxn];
bool dfs(int u)
{
    vis[u]=1;
    for(int v : g[u])if(!vis[match[v]])
    {
        if(!match[v] || dfs(match[v]))
        {
            match[v]=u;
            return 1;
        }
    }
    return 0;
}
main()
{
    int t;scanf("%d",&t);
    int cas=0;
    while(t--)
    {
        int n;scanf("%d",&n);
        ans.clear();
        for(int i=1;i<=n;i++)g[i].clear();
        for(int i=1;i<=n;i++)
        {
            int m;scanf("%d",&m);
            string s;
            for(int j=1;j<=m;j++)
            {
                cin>>s;

                if('a'<=s[0] && s[0]<='z')s[0]+=('A'-'a');
                for(int k=1;k<s.size();k++)
                    if('A'<=s[k] && s[k]<='Z')s[k]+=('a'-'A');
                 //cout<<s<<'\n';
                if(s[0]-'A'+1<=n)
                {
                    name[i][s[0]-'A'+1]=s;
                    //cout<<"XD: "<<s<<'\n';
                    g[s[0]-'A'+1].push_back(i);
                }
            }
        }
        memset(match,0,sizeof(match));
        for(int i=1;i<=n;i++)
        {
            dfs(i);
            memset(vis,0,sizeof(vis));
        }
        printf("Case #%d:\n",++cas);
        for(int i=1;i<=n;i++)
        {
            int k=match[i];
            ans.push_back(name[i][k]);
        }
        sort(ans.begin(),ans.end());
        for(string t : ans)cout<<t<<'\n';
    }
    return 0;
}


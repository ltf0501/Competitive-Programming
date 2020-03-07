#include<bits/stdc++.h>
using namespace std;
#define maxn 1000010
#define ll long long
string t,s[maxn];
vector<int> g[maxn];
int n,m;
int f[maxn],nxt[maxn][26];
ll ans;
void dfs(int u,int k)
{
    for(int v : g[u])
    {
        int cur=k;
        for(char c : s[v])
        {
            cur=nxt[cur][c-'a'];
            if(cur==m)ans++,cur=f[cur];
        }
        dfs(v,cur);
    }
}
main()
{
    scanf("%d",&n);
    for(int i=2;i<=n;i++)
    {
        int p;
        cin>>p>>s[i];
        g[p].push_back(i);
    }
    cin>>t;
    m=t.size();
    int k=0;
    for(int i=1;i<m;i++)
    {
        while(k && t[k]!=t[i])k=f[k];
        if(t[k]==t[i])k++;
        f[i+1]=k;
    }
    //for(int i=1;i<=m;i++)printf("%d ",f[i]);puts("");
    for(int i=0;i<m;i++)for(int j=0;j<26;j++)
        nxt[i][j]=((t[i]-'a')==j) ? i+1 : bool(i)*nxt[f[i]][j];
    dfs(1,0);
    printf("%lld\n",ans);
    return 0;
}

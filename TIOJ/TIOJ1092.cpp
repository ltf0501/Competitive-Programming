#include<bits/stdc++.h>
using namespace std;
#define maxn 10010
vector<int> g[maxn];
int d[maxn];
int n,m;
string s[2];
void init(int n)
{
    for(int i=1;i<=n;i++)g[i].clear();
    for(int i=1;i<=n;i++)d[i]=-1;
    s[0].clear(),s[1].clear();
}
bool dp(int u)
{
    if(d[u]>=0)return d[u];
    bool res=1;
    for(int v : g[u])
    {
        res&=!dp(v);
    }
    return d[u]=res;
}
main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    while(cin>>n>>m && n+m)
    {
        init(n);
        for(int i=1;i<=m;i++)
        {
            int a,b;scanf("%d%d",&a,&b);
            g[a].push_back(b);
        }
        cin>>s[0];
        if(s[0]=="Mimi")s[1]+="Moumou";
        else s[1]+="Mimi";
        bool t=dp(1);
        //for(int i=1;i<=n;i++)cout<<d[i]<<' ';
        //cout<<'\n';
        cout<<s[t^1]<<'\n';
    }
    return 0;
}

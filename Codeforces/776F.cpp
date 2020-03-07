#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
#define pii pair<int,int>
#define F first
#define S second
int n,m;
vector<int> g[maxn],node[maxn];
pii cal(pii a){return a.S-a.F-1<n-1-(a.S-a.F) ? pii(a.S-a.F-1,0) : pii(n-1-(a.S-a.F),1);}
bool cmp(pii a,pii b){return cal(a).F<cal(b).F;}
pii a[maxn];
set<int> s;
map<pii,int> mp;
vector<int> now;
int sz[maxn],mx[maxn],ans[maxn];
bool vis[maxn];
void get_cen(int u)
{
    sz[u]=1,vis[u]=1,mx[u]=0;
    now.push_back(u);
    for(int v : g[u])if(!vis[v])
    {
        get_cen(v);
        sz[u]+=sz[v];
        mx[u]=max(mx[u],sz[v]);
    }
}
void dfs(int u,int d)
{
    get_cen(u);
    int cen=-1;
    int s=now.size();
    for(int w : now)
    {
        if(max(mx[w],s-sz[w])<=s/2)cen=w;
        vis[w]=0;
    }
    now.clear();
    //printf("%d\n",cen);
    if(cen==-1)return ;
    ans[cen]=d,vis[cen]=1;
    for(int v : g[cen])
        if(!vis[v])dfs(v,d+1);
}
main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&a[i].F,&a[i].S);
        if(a[i].F>a[i].S)swap(a[i].F,a[i].S);
    }
    sort(a+1,a+m+1,cmp);
    //for(int i=1;i<=m;i++)printf("%d %d\n",a[i].F,a[i].S);
    for(int i=1;i<=n;i++)s.insert(i);
    for(int i=1;i<=m;i++)
    {
        if(!cal(a[i]).S)
        {
            node[i].push_back(a[i].F);
            auto it=s.upper_bound(a[i].F);
            while(*it!=a[i].S)
            {
                node[i].push_back(*it);
                it++;
            }
            node[i].push_back(a[i].S);
            for(int j=1;j<node[i].size()-1;j++)s.erase(node[i][j]);
        }
        else
        {
            while(*s.begin()!=a[i].F)
            {
                node[i].push_back(*s.begin());
                s.erase(s.begin());
            }
            node[i].push_back(a[i].F);
            node[i].push_back(a[i].S);
            int l=node[i].size();
            auto it=s.upper_bound(a[i].S);
            while(it!=s.end())
            {
                node[i].push_back(*it);
                it++;
            }
            for(;l<node[i].size();l++)s.erase(node[i][l]);
        }
        reverse(node[i].begin(),node[i].end());
        //printf("%d %d %d: ",i,a[i].F,a[i].S);
        //for(int j : node[i])printf("%d ",j);puts("");
    }
    int k=m+1;
    while(!s.empty())
    {
        node[k].push_back(*s.begin());
        s.erase(s.begin());
    }
    reverse(node[k].begin(),node[k].end());
    sort(node+1,node+k+1);
    /*
    for(int i=1;i<=k;i++)
    {
        for(int s : node[i])printf("%d ",s);
        puts("");
    }
    */
    for(int i=1;i<=k;i++)
    {
        int t=node[i].size();t--;
        for(int j=0;j<t;j++)
        {
            if(node[i][j]==node[i][j+1]+1)continue;
            if(mp.find(pii(node[i][j+1],node[i][j]))!=mp.end())
            {
                int x=mp[pii(node[i][j+1],node[i][j])];
                g[i].push_back(x),g[x].push_back(i);
                mp.erase(pii(node[i][j+1],node[i][j]));
            }
            else mp[pii(node[i][j+1],node[i][j])]=i;
        }
        if(node[i][0]==n && node[i][t]==1)continue;
        if(mp.find(pii(node[i][t],node[i][0]))!=mp.end())
        {
            int x=mp[pii(node[i][t],node[i][0])];
            g[i].push_back(x),g[x].push_back(i);
            mp.erase(pii(node[i][t],node[i][0]));
        }
        else mp[pii(node[i][t],node[i][0])]=i;
    }
    /*
    for(int i=1;i<=k;i++)
    {
        printf("%d: ",i);
        for(int s : g[i])printf("%d ",s);
        printf(", ");
        for(int s : node[i])printf("%d ",s);
        puts("");
    }
    */
    dfs(1,1);
    for(int i=1;i<=k;i++)printf("%d ",ans[i]);
    return 0;
}

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include<bits/stdc++.h>
using namespace std;
using namespace __gnu_pbds;
//st.order_of_key(...);
//st.find_by_order(...);


#define maxn 100010
#define pii pair<int,int>
#define ll long long
#define F first
#define S second
#define ALL(v) v.begin(),v.end()
int n,L,R,root,m;
vector<pii> g[maxn],dis;
pii ans;
bool vis[maxn];
vector<int> now,cen_g[maxn];
int sz[maxn],mx[maxn],d1[maxn],d2[maxn];
void get_cen(int u)
{
    sz[u]=1,mx[u]=0,vis[u]=1;
    now.push_back(u);
    for(pii v : g[u])if(!vis[v.F])
    {
        get_cen(v.F);
        sz[u]+=sz[v.F],mx[u]=max(mx[u],sz[v.F]);
    }
}
int dfs0(int u)
{
    get_cen(u);
    int cen=-1,s=now.size();
    for(int w : now)
    {
        if(max(mx[w],s-sz[w])<=s/2)cen=w;
        vis[w]=0;
    }
    now.clear();
    vis[cen]=1;
    for(pii v : g[cen])if(!vis[v.F])
        cen_g[cen].push_back(dfs0(v.F));
    return cen;
}
void get_dis(int u,int fa)
{
    dis.push_back(pii(d1[u],d2[u]));
    for(pii v : g[u])if(v.F!=fa && !vis[v.F])
    {
        d1[v.F]=d1[u]+(v.S>=m ? 1 : -1);
        d2[v.F]=d2[u]+1;
        get_dis(v.F,u);
    }
}
ll cal(int u,int val1,int val2)
{
    dis.clear(),d1[u]=val1,d2[u]=val2;
    dis.resize(0);
    get_dis(u,-1);
    sort(ALL(dis));
    int k=dis.size();
    ll ret=0;
    tree<int, null_type, less<int>, rb_tree_tag,
     tree_order_statistics_node_update> s;

    for(int l=0,r=k-1;l<k,r>=0;l++)
    {
        while(r>=0 && dis[l].F+dis[r].F>=0)s.insert(dis[r--].S);
        printf("l,r = %d %d\n",l,r);
        ret+=(s.order_of_key(R-dis[l].S+1)-s.order_of_key(L-dis[l].S));
    }
    printf("%d %d %d:\n",u,val1,val2);
    for(pii k : dis)printf("%d %d\n",k.F,k.S);
    for(pii k : dis)
        if(k.F>=0 && L<=2*k.S && 2*k.S<=R)ret--;
    printf("ret = %d\n\n",ret);
    return ret;
}
bool dfs(int u)
{
    ll ret=cal(u,0,0);
    vis[u]=1;
    for(pii v : g[u])
        if(!vis[v.F])ret-=cal(v.F,(v.S>=m ? 1 : -1),1);
    if(ret>0)return 1;
    for(int v : cen_g[maxn])
        if(dfs(v))return 1;
    return 0;
}
bool solve()
{
    memset(vis,0,sizeof(vis));
    return dfs(root);
}
main()
{
    scanf("%d%d%d",&n,&L,&R);
    for(int i=1;i<n;i++)
    {
        int x,y,d;scanf("%d%d%d",&x,&y,&d);
        g[x].push_back(pii(y,d)),g[y].push_back(pii(x,d));
    }
    root=dfs0(1);
    printf("%d\n",root);
    for(int i=30;i>=0;i--)
    {
        m+=(1<<i);
        printf("now = %d\n",m);
        if(!solve())m-=(1<<i);
    }
    printf("%d\n",m);
    return 0;
}
/*
8 3 6
1 2 9
2 3 7
3 4 7
4 5 8
5 8 2
3 6 3
2 7 4
*/

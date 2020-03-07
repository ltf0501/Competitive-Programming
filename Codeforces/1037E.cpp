#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
#define pii pair<int,int>
#define F first
#define S second
int n,m,k;
vector<pii> g[maxn];
int ans[maxn];
int u[maxn],v[maxn],deg[maxn];
set<pii> s;
bool flag[maxn];
main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&u[i],&v[i]);
        g[u[i]].push_back(pii(v[i],i)),g[v[i]].push_back(pii(u[i],i));
        deg[u[i]]++,deg[v[i]]++;
    }
    for(int i=1;i<=n;i++)flag[i]=1;
    for(int i=1;i<=n;i++)s.insert(pii(deg[i],i));
    while(!s.empty() && s.begin()->F<k)
    {
        int u=s.begin()->S;
        //printf("%d ",u);
        s.erase(s.begin());
        flag[u]=0;
        for(pii v : g[u])if(flag[v.F])
        {
            s.erase(pii(deg[v.F],v.F));
            deg[v.F]--;
            s.insert(pii(deg[v.F],v.F));
        }
    }
    ans[m]=s.size();
    //puts("");
    for(int i=m;i>=1;i--)
    {
        //printf("%d: ",i);
        int x=u[i],y=v[i];
        if(flag[u[i]] && flag[v[i]])
        {
            s.erase(pii(deg[x],x));
            deg[x]--;
            s.insert(pii(deg[x],x));
            s.erase(pii(deg[y],y));
            deg[y]--;
            s.insert(pii(deg[y],y));
        }
        while(!s.empty() && s.begin()->F<k)
        {
            int u=s.begin()->S;
            //printf("%d ",u);
            s.erase(s.begin());
            flag[u]=0;
            for(pii v : g[u])if(flag[v.F] && v.S<i)
            {
                s.erase(pii(deg[v.F],v.F));
                deg[v.F]--;
                s.insert(pii(deg[v.F],v.F));
            }
        }
        ans[i-1]=s.size();
        //puts("");
    }
    for(int i=1;i<=m;i++)printf("%d\n",ans[i]);
    return 0;
}

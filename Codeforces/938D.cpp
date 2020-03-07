#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
#define ll long long
struct P
{
    int id;ll val;
    bool operator < (const P& b)const{return val>b.val;}
};
vector<P> g[maxn];
priority_queue<P> pq;
ll a[maxn];
main()
{
    int n,m;scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int x,y;ll d;scanf("%d%d%lld",&x,&y,&d);
        d*=2;
        g[x].push_back({y,d}),g[y].push_back({x,d});
    }
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]),pq.push({i,a[i]});
    while(!pq.empty())
    {
        P t=pq.top();pq.pop();
        if(t.val!=a[t.id])continue;
        for(auto v : g[t.id])
        {
            if(a[v.id]>a[t.id]+v.val)
            {
                a[v.id]=a[t.id]+v.val;
                pq.push({v.id,a[v.id]});
            }
        }
    }
    for(int i=1;i<=n;i++)printf("%lld ",a[i]);
    return 0;
}

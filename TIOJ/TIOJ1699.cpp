#include<bits/stdc++.h>
using namespace std;
#define maxn 50000+5
#define maxq 1000000+5
struct query
{
    int l,r,k,id;
    query(int l,int r,int k,int id):l(l),r(r),k(k),id(id){}
    bool operator < (const query &b)const
    {
        return l<b.l || (l==b.l && r<b.r);
    }
};
int a[maxn];
vector<query> G[300];
int num[maxn],cnt[maxn],maxv;
bool check[maxq];
void add(int x)
{
    cnt[num[x]]--,num[x]++,cnt[num[x]]++;
    maxv=max(maxv,num[x]);
}
void sub(int x)
{
    cnt[num[x]]--,num[x]--,cnt[num[x]]++;
    if(!cnt[maxv])maxv--;
}
void sol(const vector<query> &v)
{
    memset(cnt,0,sizeof(cnt));
    memset(num,0,sizeof(num));
    cnt[0]=maxn,maxv=0;
    for(int i=v[0].l;i<=v[0].r;i++)add(a[i]);
    if(maxv>(v[0].r-v[0].l)/v[0].k)check[v[0].id]=1;
    for(int i=1;i<v.size();i++)
    {
        for(int j=v[i-1].l;j<v[i].l;j++)sub(a[j]);
        if(v[i-1].r>v[i].r)for(int j=v[i-1].r;j>v[i].r;j--)sub(a[j]);
        if(v[i-1].r<v[i].r)for(int j=v[i-1].r+1;j<=v[i].r;j++)add(a[j]);
        if(maxv>(v[i].r-v[i].l)/v[i].k)check[v[i].id]=1;
    }
}
vector<int> g;
main()
{
    int n,q;scanf("%d%d",&n,&q);
    int sqn=(int)sqrt(n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),g.push_back(a[i]);
    sort(g.begin(),g.end());
    g.resize(unique(g.begin(),g.end())-g.begin());
    for(int i=1;i<=n;i++)a[i]=lower_bound(g.begin(),g.end(),a[i])-g.begin();
    for(int i=1;i<=q;i++)
    {
        int l,r,k;scanf("%d%d%d",&l,&r,&k);
        G[l/sqn].push_back(query(l,r,k,i));
    }
    for(int i=0;i<300;i++)if(!G[i].empty())
        sort(G[i].begin(),G[i].end()),sol(G[i]);
    for(int i=1;i<=q;i++)puts(check[i] ? "YES" : "NO");
}
/*
5 3
1 2 2 1 3
1 3 2
1 5 2
1 5 3
*/

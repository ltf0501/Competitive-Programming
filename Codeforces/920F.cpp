#include<bits/stdc++.h>
using namespace std;
#define maxn 1000010
#define ll long long
int f[maxn];
int a[maxn];
int n,m;
void pre()
{
    for(int i=1;i<maxn;i++)
        for(int j=i;j<maxn;j+=i)f[j]++;
}
ll bit[maxn],sum[maxn];
void add(int x,ll d)
{
    for(int i=x;i<=n;i+=i&-i)bit[i]+=d;
}
ll query(int x)
{
    ll ret=0;
    for(int i=x;i;i-=i&-i)ret+=bit[i];
    return ret;
}
set<int> s;
main()
{
    pre();
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),sum[i]=sum[i-1]+a[i];
    for(int i=1;i<=n;i++)s.insert(i);
    while(m--)
    {
        int type,l,r;scanf("%d%d%d",&type,&l,&r);
        if(type==1)
        {
            auto it=s.lower_bound(l);
            vector<int> v;
            while(it!=s.end() && *it<=r)
            {
                if(a[*it]==f[a[*it]])v.push_back(*it);
                else add(*it,f[a[*it]]-a[*it]),a[*it]=f[a[*it]];
                it++;
            }
            for(int k : v)s.erase(k);
            v.clear();
            //for(int i=1;i<=n;i++)printf("%d ",a[i]);puts("");
        }
        else printf("%I64d\n",sum[r]+query(r)-sum[l-1]-query(l-1));
    }
    return 0;
}

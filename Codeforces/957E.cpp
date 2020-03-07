#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
#define ll long long
int x[maxn],v[maxn];
int n,w;
struct P
{
    double a,b;
    bool operator < (const P& c)const
    {
        if(a!=c.a)return a<c.a;
        return b>c.b;
    }
}a[maxn];
vector<double> V;
int d[maxn];
int bit[maxn];
void add(int x,int d)
{
    for(int i=x;i<=n;i+=i&-i)bit[i]+=d;
}
int query(int x)
{
    int ret=0;
    for(int i=x;i;i-=i&-i)ret+=bit[i];
    return ret;
}
main()
{
    scanf("%d%d",&n,&w);
    for(int i=1;i<=n;i++)scanf("%d%d",&x[i],&v[i]);
    for(int i=1;i<=n;i++)a[i]={(double)(v[i]-w)/(double)x[i],(double)(v[i]+w)/(double)x[i]};
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)V.push_back(a[i].b);
    sort(V.begin(),V.end());
    V.resize(unique(V.begin(),V.end())-V.begin());
    for(int i=1;i<=n;i++)d[i]=lower_bound(V.begin(),V.end(),a[i].b)-V.begin()+1;
    ll ans=0;
    //for(int i=1;i<=n;i++)printf("%d ",d[i]);puts("");
    for(int i=1;i<=n;i++)
    {
        ans+=query(n-d[i]+1);
        add(n-d[i]+1,1);
    }
    printf("%lld\n",ans);
    return 0;
}

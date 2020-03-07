#include<bits/stdc++.h>
using namespace std;
#define maxn 1000010
#define pii pair<int,int>
#define F first
#define S second
#define ALL(v) v.begin(),v.end()
pii a[maxn];
int n;
vector<int> v;
int p[maxn<<1],e_cnt[maxn<<1],sz[maxn<<1],mx[maxn<<1],secmx[maxn<<1];
int finds(int x){return p[x]==x ? x : p[x]=finds(p[x]);}
void Union(int x,int y)
{
    int a=finds(x),b=finds(y);
    if(a==b){e_cnt[a]++;return ;}
    if(sz[a]<sz[b])swap(a,b);
    sz[a]+=sz[b],e_cnt[a]+=(e_cnt[b]+1),p[b]=a;
    vector<int> tmp;
    tmp.push_back(mx[a]),tmp.push_back(mx[b]),tmp.push_back(secmx[a]),tmp.push_back(secmx[b]);
    sort(ALL(tmp));
    secmx[a]=tmp[2],mx[a]=tmp[3];
}
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&a[i].F,&a[i].S);
        v.push_back(a[i].F),v.push_back(a[i].S);
    }
    sort(ALL(v));
    v.resize(unique(ALL(v))-v.begin());
    for(int i=1;i<=n;i++)
        a[i].F=lower_bound(ALL(v),a[i].F)-v.begin(),
        a[i].S=lower_bound(ALL(v),a[i].S)-v.begin();
    int m=v.size();
    for(int i=0;i<m;i++)p[i]=i,e_cnt[i]=0,sz[i]=1,mx[i]=v[i],secmx[i]=0;
    for(int i=1;i<=n;i++)Union(a[i].F,a[i].S);
    int ans=0;
    for(int i=0;i<m;i++)if(p[i]==i)
    {
        if(e_cnt[i]>sz[i])return 0*puts("-1");
        if(e_cnt[i]==sz[i])ans=max(ans,mx[i]);
        else ans=max(ans,secmx[i]);
    }
    printf("%d\n",ans);
    return 0;
}

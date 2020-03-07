#include<bits/stdc++.H>
using namespace std;
#define maxn 200010
#define ll long long
#define pii pair<int,int>
#define F first
#define S second
#define ALL(v) v.begin(),v.end()
struct Q
{
    int type,x,y;
}a[maxn];
vector<pii> v;
map<ll,multiset<pii> > mp;
int cnt[maxn],num;
void add(int x,int y,int d)
{
    int g=__gcd(x,y);
    x/=g,y/=g;
    int k=lower_bound(ALL(v),pii(x,y))-v.begin();
    if(k<v.size() && v[k]==pii(x,y))cnt[k]++;
}
main()
{
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d %d %d",&a[i].type,&a[i].x,&a[i].y);
        if(a[i].type==3)
        {
            int  g=__gcd(a[i].x,a[i].y);
            a[i].x/=g,a[i].y/=g;
            v.push_back(pii(a[i].x,a[i].y));
        }
    }
    sort(ALL(v));
    v.resize(unique(ALL(v))-v.begin());
    for(int i=1;i<=n;i++)
    {
        ll d=1ll*a[i].x*a[i].x+1ll*a[i].y*a[i].y;
        auto &tmp=mp[d];
        if(a[i].type==1)
        {
            num++;
            for(pii p : tmp)add(p.F+a[i].x,p.S+a[i].y,2);
            add(a[i].x,a[i].y,1);
            tmp.insert(pii(a[i].x,a[i].y));
        }
        else if(a[i].type==2)
        {
            num--;
            auto it=tmp.find(pii(a[i].x,a[i].y));
            tmp.erase(it);
            for(pii p : tmp)add(p.F+a[i].x,p.S+a[i].y,-2);
            add(a[i].x,a[i].y,-1);
        }
        else
        {
            int k=lower_bound(ALL(v),pii(a[i].x,a[i].y))-v.begin();
            printf("%d\n",num-cnt[k]);
        }
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
#define ll long long
#define F first
#define S second
#define mkp make_pair
int n,m;
ll l[maxn],r[maxn];
vector<pair<ll,pair<int,int> > > v;
int ans[maxn];
set<pair<ll,int> > s;
main()
{
    scanf("%d%d",&n,&m);
    ll l_tmp,r_tmp;scanf("%I64d%I64d",&l_tmp,&r_tmp);
    for(int i=1;i<n;i++)
    {
        ll x,y;scanf("%I64d%I64d",&x,&y);
        l[i]=x-r_tmp,r[i]=y-l_tmp;
        l_tmp=x,r_tmp=y;
        v.push_back(mkp(l[i],mkp(-1,i)));
        v.push_back(mkp(r[i],mkp(1,i)));
    }
    for(int i=1;i<=m;i++)
    {
        ll x;scanf("%I64d",&x);
        v.push_back(mkp(x,mkp(0,i)));
    }
    sort(v.begin(),v.end());
    fill(ans+1,ans+n,-1);
    for(auto p : v)
    {
        if(p.S.F==-1)s.insert(mkp(r[p.S.S],p.S.S));
        else if(p.S.F==1)s.erase(mkp(r[p.S.S],p.S.S));
        else if(s.size())
        {
            int id=s.begin()->S;
            ans[id]=p.S.S;
            s.erase(s.begin());
        }
    }
    for(int i=1;i<n;i++)if(ans[i]==-1)return 0*puts("No");
    puts("Yes");
    for(int i=1;i<n;i++)printf("%d ",ans[i]);
    return 0;
}

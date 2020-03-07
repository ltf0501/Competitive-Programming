#include<bits/stdc++.h>
using namespace std;
#define maxn 10000005
#define pii pair<int,int>
#define F first
#define S second
#define mkp make_pair
#define ll long long
struct P{ll h;int id;};
deque<P> md,nd;
vector<pii> ans;
main()
{
    int n,m,k;scanf("%d%d%d",&n,&m,&k);
    ll x;scanf("%lld\n",&x);
    P s={x,0};
    md.push_back(s),nd.push_back(s);
    int i,j=0;
    for(i=1;i<n;i++)
    {
        if(i-j==m)j++;
        while(md.size() && i-md.front().id>=m)md.pop_front();
        while(nd.size() && i-nd.front().id>=m)nd.pop_front();
        ll x;scanf("%lld",&x);
        s={x,i};
        while(md.size() && md.back().h<s.h)md.pop_back();
        md.push_back(s);
        while(nd.size() && nd.back().h>s.h)nd.pop_back();
        nd.push_back(s);
        if(md.front().h-nd.front().h==k)
          ans.push_back(mkp(j,i));
    }
    j++;
    i--;
    while(i-j>=1)
    {
        while(md.size() && md.front().id<j)md.pop_front();
        while(nd.size() && nd.front().id<j)nd.pop_front();
        if(k==md.front().h-nd.front().h)
          ans.push_back(mkp(j,i));
        j++;
    }
    printf("%d\n",ans.size());
    for(pii v : ans)printf("%d %d\n",v.F+1,v.S+1);
    return 0;
}

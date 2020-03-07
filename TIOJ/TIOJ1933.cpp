#include<bits/stdc++.h>
using namespace std;
#define maxn 100000+5
#define ll long long
struct Interval
{
    int l,r;
    Interval(int l,int r):l(l),r(r){}
    bool operator < (const Interval &b)const
    {
        return r<b.r || (r==b.r && l>b.l);
    }
};
set<Interval> s;
set<Interval>::iterator it;
main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        s.clear();
        int n,L,C;scanf("%d%d%d",&n,&L,&C);
        for(int i=0;i<n;i++)
        {
            int x,y;scanf("%d%d",&x,&y);
            s.insert(Interval(x,x+y));
        }
        ll ans=0;
        it=s.begin();
        while(it!=s.end())
        {
            int l=it->l,r=it->r;
            //printf("%d %d\n",l,r);
            ans+=(C-r);
            while(it->l<r && it!=s.end())it++;
        }
        printf("%lld\n",ans);
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define mkp make_pair
#define pii pair<int,int>
vector<pii> e;
main()
{
    int n,m,q;scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=m;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        if(x>y)swap(x,y);
        e.push_back(mkp(x,y));
    }
    sort(e.begin(),e.end());
    while(q--)
    {
        int x,y;scanf("%d%d",&x,&y);
        if(x>y)swap(x,y);
        int k=lower_bound(e.begin(),e.end(),mkp(x,y))-e.begin();
        if(e[k].F==x && e[k].S==y)puts("yes");
        else puts("no");
    }
    return 0;
}

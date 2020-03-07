#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> v;
set<pair<int,int> > ans;
main()
{
    int l,r,x,y;scanf("%d%d%d%d",&l,&r,&x,&y);
    if(y%x!=0)return 0*puts("0");
    for(int i=1;1ll*i*i<=y;i++)
    {
        if(y%i==0)v.push_back(i),v.push_back(y/i);
    }
    for(int a : v)for(int b : v)
    {
        if(min(a,b)<l || max(a,b)>r)continue;
        int g=__gcd(a,b);
        if(g==x && 1ll*a*b/g==y)ans.insert(make_pair(a,b));
    }
    printf("%d\n",ans.size());
    return 0;
}

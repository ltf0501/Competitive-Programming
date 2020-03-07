#include<bits/stdc++.h>
using namespace std;
#define maxn 1000010
#define mkp make_pair
int row[maxn],col[maxn];
struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);

        // Mainly for demonstration purposes, i.e. works but is overly simple
        // In the real world, use sth. like boost.hash_combine
        return h1 ^ h2;
    }
};
unordered_map<pair<int,int>,string,pair_hash> mp;
main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int m,n;cin>>m>>n;
    for(int i=1;i<=m;i++)row[i]=i;
    for(int i=1;i<=n;i++)col[i]=i;
    for(int i=1;i<=m;i++)for(int j=1;j<=n;j++)
    {
        string s;cin>>s;
        mp[make_pair(i,j)]=s;
    }
    int q;cin>>q;
    while(q--)
    {
        char c;cin>>c;
        if(c=='S')
        {
            int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
            swap(mp[mkp(row[x1],col[y1])],mp[mkp(row[x2],col[y2])]);
        }
        else if(c=='R')
        {
            int a,b;cin>>a>>b;
            swap(row[a],row[b]);
        }
        else
        {
            int a,b;cin>>a>>b;
            swap(col[a],col[b]);
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)cout<<mp[mkp(row[i],col[j])]<<' ';
        cout<<'\n';
    }
    return 0;
}
